import rclpy
from rclpy.node import Node

import math
import heapq
from shapely.geometry import Point, Polygon

from std_msgs.msg import Bool, UInt64
# We need Path and PoseStamped for RViz visualization
from nav_msgs.msg import Odometry, Path
from geometry_msgs.msg import PoseStamped, Quaternion

# Custom interfaces for the controller
from shell_interfaces.msg import Trajectory, TrajectoryPoint, Boundary, ObstacleArray

# ==============================
# PARAMETERS
# ==============================
XY_GRID_RESOLUTION = 0.5
THETA_GRID_RESOLUTION = math.radians(10)
DT = 0.15
VEHICLE_SPEED = 15.0
WHEELBASE = 2.5
STEERING_ANGLES = [-0.5, -0.35, -0.2, 0.0, 0.2, 0.35, 0.5]
CAR_RADIUS = 0.7
SAFETY_MARGIN = 0.2

# ==============================
# HELPER FUNCTIONS
# ==============================
def euler_from_quaternion(x, y, z, w):
    t0 = +2.0 * (w * x + y * z)
    t1 = +1.0 - 2.0 * (x * x + y * y)
    roll_x = math.atan2(t0, t1)
    t2 = +2.0 * (w * y - z * x)
    t2 = +1.0 if t2 > +1.0 else t2
    t2 = -1.0 if t2 < -1.0 else t2
    pitch_y = math.asin(t2)
    t3 = +2.0 * (w * z + x * y)
    t4 = +1.0 - 2.0 * (y * y + z * z)
    yaw_z = math.atan2(t3, t4)
    return roll_x, pitch_y, yaw_z

def quaternion_from_euler(yaw):
    """Convert yaw (theta) to quaternion so RViz can show the arrow direction"""
    q = Quaternion()
    q.x = 0.0
    q.y = 0.0
    q.z = math.sin(yaw / 2.0)
    q.w = math.cos(yaw / 2.0)
    return q

def state_key(x, y, theta):
    return (
        round(x / XY_GRID_RESOLUTION),
        round(y / XY_GRID_RESOLUTION),
        round(theta / THETA_GRID_RESOLUTION),
    )

def simulate_motion(x, y, theta, steer):
    x_new = x + VEHICLE_SPEED * math.cos(theta) * DT
    y_new = y + VEHICLE_SPEED * math.sin(theta) * DT
    theta_new = theta + (VEHICLE_SPEED / WHEELBASE) * math.tan(steer) * DT
    theta_new = (theta_new + 2 * math.pi) % (2 * math.pi)
    return x_new, y_new, theta_new

def heuristic(x, y, goal):
    gx, gy = goal
    return 1.2 * math.hypot(gx - x, gy - y)

def is_near_obstacle(x, y, obstacles):
    safe_r = CAR_RADIUS + SAFETY_MARGIN
    for ox, oy in obstacles:
        if math.hypot(ox - x, oy - y) < safe_r:
            return True
    return False

class HybridNode:
    def __init__(self, x, y, theta, g, h, parent=None):
        self.x = x
        self.y = y
        self.theta = theta
        self.g = g
        self.h = h
        self.f = g + h
        self.parent = parent
    def __lt__(self, other):
        return self.f < other.f

def hybrid_astar(start, goal, track_poly, obstacles):
    start_node = HybridNode(start[0], start[1], start[2], 0.0, heuristic(start[0], start[1], goal))
    open_list = [start_node]
    closed = set()

    while open_list:
        current = heapq.heappop(open_list)

        if math.hypot(current.x - goal[0], current.y - goal[1]) < 2.0:
            path = []
            node = current
            while node:
                path.append((node.x, node.y, node.theta))
                node = node.parent
            return path[::-1]

        key = state_key(current.x, current.y, current.theta)
        if key in closed:
            continue
        closed.add(key)

        for steer in STEERING_ANGLES:
            nx, ny, ntheta = simulate_motion(current.x, current.y, current.theta, steer)
            
            # Check if point is inside polygon
            if not track_poly.contains(Point(nx, ny)):
                continue
            if is_near_obstacle(nx, ny, obstacles):
                continue
            
            nkey = state_key(nx, ny, ntheta)
            if nkey in closed:
                continue

            g = current.g + 1.0
            h = heuristic(nx, ny, goal)
            heapq.heappush(open_list, HybridNode(nx, ny, ntheta, g, h, current))

    return []

def build_trajectory(path):
    traj = Trajectory()
    for i, (x, y, theta) in enumerate(path):
        p = TrajectoryPoint()
        p.x = float(x)
        p.y = float(y)
        p.theta = float(theta)
        p.v = VEHICLE_SPEED if i < len(path) - 1 else 0.0
        traj.points.append(p)
    return traj

# ==============================
# GLOBAL PLANNER NODE
# ==============================
class GlobalPlanner(Node):
    def __init__(self):
        super().__init__('global_planner')

        self.create_subscription(Boundary, '/left_boundary', self.left_bound_cb, 10)
        self.create_subscription(Boundary, '/right_boundary', self.right_bound_cb, 10)
        self.create_subscription(ObstacleArray, '/obstacles', self.obs_cb, 10)
        self.create_subscription(Odometry, '/odom', self.odom_cb, 10)
        self.create_subscription(Bool, '/start_signal', self.start_cb, 10)

        # 1. Custom Trajectory for Control (Keep this!)
        self.path_pub = self.create_publisher(Trajectory, '/planned_path', 10)
        
        # 2. Standard Path for RViz (Use this in RViz!)
        self.viz_pub = self.create_publisher(Path, '/viz_path', 10)

        self.heartbeat_pub = self.create_publisher(UInt64, '/planner_heartbeat', 10)
        self.create_timer(1.0, self.publish_heartbeat)

        self.started = False
        self.left_pts = []
        self.right_pts = []
        self.track_poly = None
        self.obstacles = []
        self.start_pose = None
        self.goal = (140.0, 35.0) 

        self.get_logger().info("Global Planner Initialized")

    def left_bound_cb(self, msg):
        self.left_pts = [(p.x, p.y) for p in msg.points]
        self.try_construct_track()

    def right_bound_cb(self, msg):
        self.right_pts = [(p.x, p.y) for p in msg.points]
        self.try_construct_track()

    def try_construct_track(self):
        if self.left_pts and self.right_pts:
            combined_pts = self.left_pts + self.right_pts[::-1] + [self.left_pts[0]]
            try:
                self.track_poly = Polygon(combined_pts)
                if not self.track_poly.is_valid:
                    self.track_poly = self.track_poly.buffer(0)
            except Exception as e:
                self.get_logger().error(f"Polygon Error: {e}")

    def obs_cb(self, msg):
        self.obstacles = [(obs.center.x, obs.center.y) for obs in msg.obstacles]

    def odom_cb(self, msg):
        x = msg.pose.pose.position.x
        y = msg.pose.pose.position.y
        oq = msg.pose.pose.orientation
        _, _, theta = euler_from_quaternion(oq.x, oq.y, oq.z, oq.w)
        self.start_pose = (x, y, theta)

    def start_cb(self, msg):
        self.started = msg.data
        if self.started:
            self.plan()

    def plan(self):
        missing = []
        if not self.left_pts: missing.append("Left Boundary")
        if not self.right_pts: missing.append("Right Boundary")
        if self.start_pose is None: missing.append("/odom")

        if missing:
            self.get_logger().warn(f"Waiting for inputs: {', '.join(missing)}")
            return

        self.get_logger().info(f"Planning from {self.start_pose} to {self.goal}")
        
        if self.track_poly and not self.track_poly.contains(Point(self.start_pose[0], self.start_pose[1])):
             self.get_logger().warn("Start pose is OUTSIDE the track boundary! (Planning anyway)")

        path = hybrid_astar(self.start_pose, self.goal, self.track_poly, self.obstacles)
        
        if not path:
            self.get_logger().error("Hybrid A* failed to find a path.")
            return

        # --- 1. Publish Control Trajectory ---
        traj = build_trajectory(path)
        self.path_pub.publish(traj)
        
        # --- 2. Publish Visualization Path (For RViz) ---
        self.publish_viz_path(traj)

        self.get_logger().info(f"Published trajectory with {len(traj.points)} points")

    def publish_viz_path(self, traj):
        viz_msg = Path()
        viz_msg.header.frame_id = "map"
        viz_msg.header.stamp = self.get_clock().now().to_msg()

        for tp in traj.points:
            pose = PoseStamped()
            pose.header = viz_msg.header
            pose.pose.position.x = tp.x
            pose.pose.position.y = tp.y
            pose.pose.position.z = 0.0
            pose.pose.orientation = quaternion_from_euler(tp.theta)
            viz_msg.poses.append(pose)

        self.viz_pub.publish(viz_msg)

    def publish_heartbeat(self):
        msg = UInt64()
        msg.data = self.get_clock().now().nanoseconds
        self.heartbeat_pub.publish(msg)

def main():
    rclpy.init()
    node = GlobalPlanner()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()