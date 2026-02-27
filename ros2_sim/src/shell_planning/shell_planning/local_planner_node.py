#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
import math
import numpy as np

from nav_msgs.msg import Odometry, Path
from std_msgs.msg import Float64MultiArray
from geometry_msgs.msg import Twist, PoseStamped

class LocalPlannerNode(Node):
    def __init__(self):
        super().__init__('local_planner_node')

        # ----- Subscribers -----
        self.create_subscription(Path, '/planned_path', self.path_cb, 10)
        self.create_subscription(Odometry, '/odom', self.odom_cb, 10)
        self.create_subscription(Float64MultiArray, '/obstacle_pose', self.obs_cb, 10)

        # ----- Publisher -----
        self.cmd_pub = self.create_publisher(Twist, '/cmd_vel', 10)

        # ----- Internal state -----
        self.global_path = None
        self.odom = None
        self.obstacles = []
        self.current_target_idx = 0

        # ----- Timer -----
        self.timer = self.create_timer(0.05, self.run_local_planner)

        self.get_logger().info("Local Planner Node Ready")

    # ---- Callbacks ----
    def path_cb(self, msg: Path):
        self.global_path = msg.poses

    def odom_cb(self, msg: Odometry):
        px = msg.pose.pose.position.x
        py = msg.pose.pose.position.y
        # compute yaw
        q = msg.pose.pose.orientation
        yaw = math.atan2(2*(q.w*q.z + q.x*q.y), 1 - 2*(q.y*q.y + q.z*q.z))

        self.odom = (px, py, yaw)

    def obs_cb(self, msg: Float64MultiArray):
        self.obstacles = [(msg.data[i], msg.data[i+1], 0.5)  # treat obstacles as x,y,radius
                          for i in range(0, len(msg.data), 2)]

    # ---- Main update loop ----
    def run_local_planner(self):
        if self.global_path is None or self.odom is None:
            return

        # extract path coords
        gx = [p.pose.position.x for p in self.global_path]
        gy = [p.pose.position.y for p in self.global_path]

        # run your existing local planner function
        v, w, self.current_target_idx, _ = local_planner(
            self.odom, gx, gy,
            lookahead_dist=1.5,
            last_index=self.current_target_idx,
            obstacles=self.obstacles,
            safe_margin=0.4,
            max_v=0.6,
            max_w=1.0
        )

        # publish Twist
        cmd = Twist()
        cmd.linear.x = float(v)
        cmd.angular.z = float(w)
        self.cmd_pub.publish(cmd)


### ----------------------------------------------------------------------
### Paste your local_planner and helpers below **unchanged**
### (I’ve removed simulation/testing code and just kept the planner logic)
### ----------------------------------------------------------------------

def local_planner(current_pose, global_path_x, global_path_y, lookahead_dist,
                  last_index=0,
                  obstacles=None, safe_margin=0.5, max_v=0.5, max_w=1.0):

    x, y, theta = current_pose

    # Find current index
    search_window = 50
    start_search = last_index
    end_search = min(last_index + search_window, len(global_path_x))
    if start_search >= len(global_path_x) - 1:
        start_search = len(global_path_x) - 1
        end_search = len(global_path_x)

    distances = []
    for i in range(start_search, end_search):
        d = math.hypot(global_path_x[i] - x, global_path_y[i] - y)
        distances.append(d)

    if distances:
        idx_local = np.argmin(distances)
        current_idx = start_search + idx_local
    else:
        current_idx = last_index

    # lookahead target
    target_idx = current_idx
    for i in range(current_idx, len(global_path_x)):
        dist = math.hypot(global_path_x[i] - x, global_path_y[i] - y)
        if dist >= lookahead_dist:
            target_idx = i
            break

    tx = global_path_x[target_idx]
    ty = global_path_y[target_idx]

    # obstacle avoidance
    avoiding = False
    if obstacles:
        for obs in obstacles:
            obs_x, obs_y, obs_r = obs
            if is_obstacle_blocking_path(x, y, tx, ty, obs_x, obs_y, obs_r + safe_margin):
                avoiding = True
                tx, ty = compute_avoidance_target(x, y, theta, obs_x, obs_y,
                                                  obs_r + safe_margin,
                                                  tx, ty, lookahead_dist)
                break

    # pure pursuit steering
    angle_to_target = math.atan2(ty - y, tx - x)
    alpha = (angle_to_target - theta + math.pi) % (2*math.pi) - math.pi

    L = math.hypot(tx - x, ty - y)
    v = max_v
    if abs(alpha) > math.pi/4:
        v *= 0.5
    if avoiding:
        v *= 0.6

    w = 2.0 * v * math.sin(alpha) / max(L, 0.001)
    w = max(-max_w, min(max_w, w))

    return v, w, target_idx, avoiding

def is_obstacle_blocking_path(x1, y1, x2, y2, obs_x, obs_y, obs_radius):
    dx, dy = x2 - x1, y2 - y1
    length = math.hypot(dx, dy)
    if length < 0.01: return False
    dx /= length; dy /= length

    to_obs_x = obs_x - x1
    to_obs_y = obs_y - y1
    proj = to_obs_x*dx + to_obs_y*dy
    if proj < 0 or proj > length: return False

    closest_x = x1 + proj*dx
    closest_y = y1 + proj*dy
    return math.hypot(obs_x - closest_x, obs_y - closest_y) < obs_radius

def compute_avoidance_target(robot_x, robot_y, robot_theta,
                             obs_x, obs_y, obs_radius,
                             orig_tx, orig_ty, lookahead_dist):

    to_obs_x = obs_x - robot_x
    to_obs_y = obs_y - robot_y
    d = math.hypot(to_obs_x, to_obs_y)
    if d < 1e-3:
        return orig_tx, orig_ty

    to_obs_x /= d; to_obs_y /= d
    perp_left_x, perp_left_y = -to_obs_y, to_obs_x
    perp_right_x, perp_right_y = to_obs_y, -to_obs_x

    avoidance_dist = obs_radius * 1.5
    left_x = robot_x + perp_left_x*avoidance_dist
    left_y = robot_y + perp_left_y*avoidance_dist
    right_x = robot_x + perp_right_x*avoidance_dist
    right_y = robot_y + perp_right_y*avoidance_dist

    # choose closest to original target
    if math.hypot(left_x - orig_tx, left_y - orig_ty) < math.hypot(right_x - orig_tx, right_y - orig_ty):
        return left_x, left_y
    return right_x, right_y

def main(args=None):
    rclpy.init(args=args)
    node = LocalPlannerNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
