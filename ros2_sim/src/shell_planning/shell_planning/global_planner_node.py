import rclpy
from rclpy.node import Node
import math
import heapq
import numpy as np
from shapely.geometry import Point, Polygon, LineString

# ROS Messages
from std_msgs.msg import Bool, UInt64
from nav_msgs.msg import Odometry, Path
from geometry_msgs.msg import PoseStamped, Quaternion, Point as RosPoint
from visualization_msgs.msg import Marker, MarkerArray

# Shell Interfaces
try:
    from shell_interfaces.msg import Trajectory, TrajectoryPoint, Boundary, ObstacleArray
    SHELL_MSGS = True
except ImportError:
    SHELL_MSGS = False

# ==========================================
# 1. CONFIGURATION (MATCHING YOUR NOTEBOOK)
# ==========================================
XY_GRID_RESOLUTION = 0.5               
THETA_GRID_RESOLUTION = math.radians(15)
DT = 0.3                                
VEHICLE_SPEED = 4.0                    # Increased slightly for simulation
WHEELBASE = 2.5                         
STEERING_ANGLES = [-0.6, -0.3, 0, +0.3, +0.6]
CAR_RADIUS = 1.0     
SAFETY_MARGIN = 0.5                    # Reduced slightly to fit in narrow tracks

# ==========================================
# 2. HELPER FUNCTIONS
# ==========================================
def euler_from_quaternion(q):
    t0 = +2.0 * (q.w * q.z + q.x * q.y)
    t1 = +1.0 - 2.0 * (q.y * q.y + q.z * q.z)
    return math.atan2(t0, t1)

def quaternion_from_euler(yaw):
    q = Quaternion()
    q.z = math.sin(yaw / 2.0)
    q.w = math.cos(yaw / 2.0)
    return q

def state_key(x, y, theta):
    return (
        round(x / XY_GRID_RESOLUTION),
        round(y / XY_GRID_RESOLUTION),
        round(theta / THETA_GRID_RESOLUTION)
    )

def simulate_motion(x, y, theta, steer):
    x_new = x + VEHICLE_SPEED * math.cos(theta) * DT
    y_new = y + VEHICLE_SPEED * math.sin(theta) * DT
    theta_new = theta + (VEHICLE_SPEED / WHEELBASE) * math.tan(steer) * DT
    theta_new = (theta_new + 2 * math.pi) % (2 * math.pi)
    return x_new, y_new, theta_new

def heuristic(x, y, goal):
    # 1.2 weighting to favor goal direction (from your notebook)
    return 1.2 * math.hypot(goal[0] - x, goal[1] - y)

def is_near_obstacle(x, y, obstacles):
    safe_r = CAR_RADIUS + SAFETY_MARGIN
    if not obstacles: return False
    for ox, oy in obstacles:
        if math.hypot(ox - x, oy - y) < safe_r:
            return True
    return False

# ==========================================
# 3. ALGORITHM CLASSES & FUNCTIONS
# ==========================================
class HybridNode:
    def __init__(self, x, y, theta, g, h, parent=None):
        self.x = x; self.y = y; self.theta = theta
        self.g = g; self.h = h; self.f = g + h
        self.parent = parent
    def __lt__(self, other): return self.f < other.f

def hybrid_astar(start, goal, track_poly, obstacles):
    start_node = HybridNode(start[0], start[1], start[2], 0.0, heuristic(start[0], start[1], goal))
    open_list = [start_node]
    closed = set()
    
    # Limit iterations to prevent freezing
    max_iter = 50000 
    iter_count = 0

    while open_list and iter_count < max_iter:
        iter_count += 1
        current = heapq.heappop(open_list)

        # Goal reached check
        if math.hypot(current.x - goal[0], current.y - goal[1]) < 3.0:
            path = []
            node = current
            while node:
                path.append((node.x, node.y, node.theta))
                node = node.parent
            return path[::-1]

        key = state_key(current.x, current.y, current.theta)
        if key in closed: continue
        closed.add(key)

        for steer in STEERING_ANGLES:
            nx, ny, ntheta = simulate_motion(current.x, current.y, current.theta, steer)

            # 1. Track Boundary Check (Using Shapely directly like Notebook)
            if not track_poly.contains(Point(nx, ny)): continue
            
            # 2. Obstacle Check
            if is_near_obstacle(nx, ny, obstacles): continue

            nkey = state_key(nx, ny, ntheta)
            if nkey in closed: continue

            # Cost calculation
            g_new = current.g + 1.0 + abs(steer)*0.1 # Slight penalty for steering
            h_new = heuristic(nx, ny, goal)
            heapq.heappush(open_list, HybridNode(nx, ny, ntheta, g_new, h_new, current))

    return []

def smooth_path(raw_path, track_poly, obstacles):
    """
    Your Notebook's Smoothing Function
    Removes zig-zags by checking if a straight line exists between points
    """
    if len(raw_path) < 3: return raw_path

    smoothed = [raw_path[0]]
    
    # Iterate from start to end
    i = 0
    while i < len(raw_path) - 1:
        current = raw_path[i]
        # Look ahead as far as possible
        best_next_idx = i + 1
        
        for j in range(len(raw_path) - 1, i + 1, -1):
            target = raw_path[j]
            
            # Simple line check
            line = LineString([(current[0], current[1]), (target[0], target[1])])
            
            # 1. Check if line stays inside track
            if not track_poly.contains(line): continue
            
            # 2. Check if line hits obstacles
            hit_obs = False
            for ox, oy in obstacles:
                if line.distance(Point(ox, oy)) < (CAR_RADIUS + SAFETY_MARGIN):
                    hit_obs = True; break
            if hit_obs: continue
            
            # If safe, this is our shortcut
            best_next_idx = j
            break
        
        smoothed.append(raw_path[best_next_idx])
        i = best_next_idx

    return smoothed

# ==========================================
# 4. GLOBAL PLANNER NODE
# ==========================================
class GlobalPlanner(Node):
    def __init__(self):
        super().__init__('global_planner')
        
        self.create_subscription(Boundary, '/left_boundary', self.left_cb, 10)
        self.create_subscription(Boundary, '/right_boundary', self.right_cb, 10)
        self.create_subscription(ObstacleArray, '/obstacles', self.obs_cb, 10)
        self.create_subscription(Odometry, '/odom', self.odom_cb, 10)
        self.create_subscription(Bool, '/start_signal', self.start_cb, 10)

        self.viz_pub = self.create_publisher(Path, '/viz_path', 10)
        self.debug_pub = self.create_publisher(MarkerArray, '/planner_debug', 10)

        if SHELL_MSGS:
            self.traj_pub = self.create_publisher(Trajectory, '/planned_path', 10)

        self.left_pts = []
        self.right_pts = []
        self.obstacles = []
        self.pose = None
        self.track_poly = None
        
        self.create_timer(1.0, self.planning_loop)
        self.get_logger().info("Global Planner (Notebook Logic + Smoothing) Ready.")

    def left_cb(self, msg): self.left_pts = [(p.x, p.y) for p in msg.points]
    def right_cb(self, msg): self.right_pts = [(p.x, p.y) for p in msg.points]
    def obs_cb(self, msg): self.obstacles = [(o.center.x, o.center.y) for o in msg.obstacles]
    
    def odom_cb(self, msg):
        p = msg.pose.pose.position
        theta = euler_from_quaternion(msg.pose.pose.orientation)
        self.pose = (p.x, p.y, theta)

    def start_cb(self, msg):
        if msg.data: self.plan()

    def planning_loop(self):
        # Auto-construct track if data is available
        if self.left_pts and self.right_pts:
            pts = self.left_pts + self.right_pts[::-1]
            try:
                self.track_poly = Polygon(pts)
                if not self.track_poly.is_valid: self.track_poly = self.track_poly.buffer(0)
            except: pass
            
            # If we have pose, try to plan
            if self.pose: self.plan()

    def get_goal(self):
        # Calculate Centerline Goal
        if not self.left_pts or not self.right_pts: return None
        n = min(len(self.left_pts), len(self.right_pts))
        # Pick 90% down the track
        idx = int(n * 0.9)
        lx, ly = self.left_pts[idx]
        rx, ry = self.right_pts[idx]
        return ((lx+rx)/2.0, (ly+ry)/2.0)

    def plan(self):
        if not self.track_poly or not self.pose: return

        goal = self.get_goal()
        if not goal: return

        # Debug Visuals
        self.publish_debug(goal)

        # 1. Run Hybrid A* (Raw)
        raw_path = hybrid_astar(self.pose, goal, self.track_poly, self.obstacles)
        
        if not raw_path:
            self.get_logger().warn("Hybrid A* Failed (Raw).")
            return

        # 2. Run Smoothing (Fixes the mess!)
        final_path = smooth_path(raw_path, self.track_poly, self.obstacles)
        
        self.get_logger().info(f"Path Found! Raw: {len(raw_path)} -> Smoothed: {len(final_path)}")
        
        self.publish_path(final_path)

    def publish_path(self, path):
        ros_path = Path()
        ros_path.header.frame_id = "map"
        ros_path.header.stamp = self.get_clock().now().to_msg()
        
        traj = Trajectory() if SHELL_MSGS else None

        for i, (x, y, theta) in enumerate(path):
            # ROS Path
            pose = PoseStamped()
            pose.header = ros_path.header
            pose.pose.position.x = float(x)
            pose.pose.position.y = float(y)
            pose.pose.orientation = quaternion_from_euler(theta)
            ros_path.poses.append(pose)

            # Shell Trajectory
            if traj:
                p = TrajectoryPoint()
                p.x, p.y, p.theta = float(x), float(y), float(theta)
                # Set velocity (Slow down at end)
                p.v = 0.0 if i == len(path)-1 else 10.0 
                traj.points.append(p)

        self.viz_pub.publish(ros_path)
        if traj: self.traj_pub.publish(traj)

    def publish_debug(self, goal):
        ma = MarkerArray()
        m = Marker()
        m.header.frame_id = "map"; m.id = 0; m.type = Marker.SPHERE; m.action = Marker.ADD
        m.scale.x = 2.0; m.scale.y = 2.0; m.scale.z = 2.0
        m.color.a = 1.0; m.color.r = 1.0; m.color.g = 0.0; m.color.b = 1.0 # Purple Goal
        m.pose.position.x = goal[0]; m.pose.position.y = goal[1]
        ma.markers.append(m)
        self.debug_pub.publish(ma)

def main():
    rclpy.init()
    node = GlobalPlanner()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()