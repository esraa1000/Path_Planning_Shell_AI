import rclpy
from rclpy.node import Node

import math
import heapq
import numpy as np
from shapely.geometry import Point, Polygon

from std_msgs.msg import Bool, UInt64, Float64MultiArray
from geometry_msgs.msg import Polygon as RosPolygon, Point32
from nav_msgs.msg import Odometry

from shell_interfaces.msg import Trajectory, TrajectoryPoint

# HYBRID A* PARAMETERS (URBAN TRACK)

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

        if math.hypot(current.x - goal[0], current.y - goal[1]) < 1.5:
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

        # Subscriptions
        self.create_subscription(RosPolygon, '/track_boundary', self.track_cb, 10)
        self.create_subscription(Float64MultiArray, '/obstacle_pose', self.obs_cb, 10)
        self.create_subscription(Odometry, '/odom', self.odom_cb, 10)
        self.create_subscription(Bool, '/start_signal', self.start_cb, 10)

        # Publishers
        self.path_pub = self.create_publisher(Trajectory, '/planned_path', 10)
        self.heartbeat_pub = self.create_publisher(UInt64, '/planner_heartbeat', 10)

        self.create_timer(1.0, self.publish_heartbeat)

        # State
        self.started = False
        self.track_poly = None
        self.obstacles = []
        self.start_pose = None
        self.goal = (60.0, 15.0)

        self.get_logger().info("Global Planner (Hybrid A*) started")

    # --------------------
    # Callbacks
    # --------------------
    def start_cb(self, msg):
        self.started = msg.data
        self.get_logger().info(f"Start signal received: {self.started}")
        if self.started:
            self.plan()

    def track_cb(self, msg):
        pts = [(p.x, p.y) for p in msg.points]
        if pts[0] != pts[-1]:
            pts.append(pts[0])
        self.track_poly = Polygon(pts)

    def obs_cb(self, msg):
        self.obstacles = [(msg.data[i], msg.data[i + 1])
                          for i in range(0, len(msg.data), 2)]

    def odom_cb(self, msg):
        x = msg.pose.pose.position.x
        y = msg.pose.pose.position.y
        theta = 0.0
        self.start_pose = (x, y, theta)

    # --------------------
    # Planning
    # --------------------
    def plan(self):
        if not (self.track_poly and self.start_pose):
            self.get_logger().warn("Planner missing inputs")
            return

        self.get_logger().info("Running Hybrid A* planner...")
        path = hybrid_astar(self.start_pose, self.goal, self.track_poly, self.obstacles)

        if not path:
            self.get_logger().error("No path found")
            return

        traj = build_trajectory(path)
        self.path_pub.publish(traj)
        self.get_logger().info(f"Published trajectory with {len(traj.points)} points")

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
