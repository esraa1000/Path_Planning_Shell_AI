import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, DurabilityPolicy
import math
import numpy as np
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
from std_msgs.msg import Float64MultiArray
from shell_interfaces.msg import Trajectory

class LocalPlanner(Node):
    def __init__(self):
        super().__init__('local_planner')

        # Parameters
        self.lookahead_dist = 2.5
        self.safe_margin = 1.0
        self.max_v = 15.0
        self.max_w = 2.0

        # State
        self.current_pose = None # (x, y, theta)
        self.global_path = None # list of (x, y)
        self.obstacles = [] # list of (x, y, radius)
        self.last_index = 0

        # Subscriptions
        path_qos = QoSProfile(depth=1, durability=DurabilityPolicy.TRANSIENT_LOCAL)
        self.create_subscription(Trajectory, '/planned_path', self.path_cb, path_qos)
        self.create_subscription(Odometry, '/odom', self.odom_cb, 10)
        self.create_subscription(Float64MultiArray, '/obstacle_pose', self.obs_cb, 10)

        # Publisher
        self.cmd_pub = self.create_publisher(Twist, '/cmd_vel', 10)

        # Timer (20Hz)
        self.create_timer(0.05, self.control_loop)

        self.get_logger().info("Local Planner Node started")

    def path_cb(self, msg):
        self.global_path = [(p.x, p.y) for p in msg.points]
        self.last_index = 0
        self.get_logger().info(f"Received new path with {len(self.global_path)} points")

    def odom_cb(self, msg):
        x = msg.pose.pose.position.x
        y = msg.pose.pose.position.y
        # Simple yaw from quaternion
        q = msg.pose.pose.orientation
        siny_cosp = 2 * (q.w * q.z + q.x * q.y)
        cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z)
        theta = math.atan2(siny_cosp, cosy_cosp)
        self.current_pose = (x, y, theta)

    def obs_cb(self, msg):
        self.obstacles = []
        for i in range(0, len(msg.data), 2):
            self.obstacles.append((msg.data[i], msg.data[i+1], 1.5)) # Default obstacle radius

    def control_loop(self):
        if self.current_pose is None or self.global_path is None or len(self.global_path) == 0:
            return

        v, w, target_idx, avoiding = self.plan()
        self.last_index = target_idx

        twist = Twist()
        twist.linear.x = float(v)
        twist.angular.z = float(w)
        self.cmd_pub.publish(twist)

    def plan(self):
        x, y, theta = self.current_pose
        gx = [p[0] for p in self.global_path]
        gy = [p[1] for p in self.global_path]

        # 1. Windowed Search for nearest point
        search_window = 100
        start_search = self.last_index
        end_search = min(self.last_index + search_window, len(gx))

        if start_search >= len(gx) - 1:
            start_search = len(gx) - 1
            end_search = len(gx)

        distances = []
        for i in range(start_search, end_search):
            d = math.hypot(gx[i] - x, gy[i] - y)
            distances.append(d)

        if not distances:
            current_path_index = self.last_index
        else:
            current_path_index = start_search + np.argmin(distances)

        # 2. Find lookahead point
        target_idx = current_path_index
        for i in range(current_path_index, len(gx)):
            dist = math.hypot(gx[i] - x, gy[i] - y)
            if dist >= self.lookahead_dist:
                target_idx = i
                break

        tx, ty = gx[target_idx], gy[target_idx]

        # 3. Obstacle Avoidance
        avoiding = False
        for obs in self.obstacles:
            ox, oy, orad = obs
            dist_to_obs = math.hypot(ox - x, oy - y)

            if dist_to_obs > self.lookahead_dist + self.safe_margin:
                continue

            angle_to_obs = math.atan2(oy - y, ox - x)
            diff = (angle_to_obs - theta + math.pi) % (2*math.pi) - math.pi
            if abs(diff) > math.pi / 2:
                continue

            if self.is_obstacle_blocking_path(x, y, tx, ty, ox, oy, orad + self.safe_margin):
                avoiding = True
                tx, ty = self.compute_avoidance_target(x, y, theta, ox, oy, orad + self.safe_margin, tx, ty)
                break

        # 4. Steering Control (Pure Pursuit)
        angle_to_target = math.atan2(ty - y, tx - x)
        alpha = (angle_to_target - theta + math.pi) % (2*math.pi) - math.pi

        L = math.hypot(tx - x, ty - y)
        L = max(L, 0.1)

        v = self.max_v
        # Scale speed based on steering angle
        if abs(alpha) > math.pi / 6:
            v *= 0.5
        if avoiding:
            v *= 0.6

        w = 2.0 * v * math.sin(alpha) / L
        w = np.clip(w, -self.max_w, self.max_w)

        # 5. Goal Slowdown
        dist_to_final = math.hypot(x - gx[-1], y - gy[-1])
        if dist_to_final < 5.0 and target_idx > len(gx) - 50:
            v *= (dist_to_final / 5.0)
            v = max(v, 0.5)
            if dist_to_final < 0.5:
                v = 0.0
                w = 0.0

        return v, w, target_idx, avoiding

    def is_obstacle_blocking_path(self, x1, y1, x2, y2, ox, oy, orad):
        dx = x2 - x1
        dy = y2 - y1
        l2 = dx*dx + dy*dy
        if l2 == 0: return math.hypot(ox-x1, oy-y1) < orad
        t = ((ox - x1) * dx + (oy - y1) * dy) / l2
        t = max(0, min(1, t))
        closest_x = x1 + t * dx
        closest_y = y1 + t * dy
        return math.hypot(ox - closest_x, oy - closest_y) < orad

    def compute_avoidance_target(self, rx, ry, rt, ox, oy, orad, tx, ty):
        to_obs_x = ox - rx
        to_obs_y = oy - ry
        dist = math.hypot(to_obs_x, to_obs_y)
        if dist < 0.01: return tx, ty

        to_obs_x /= dist
        to_obs_y /= dist

        # Perpendiculars
        perp_left_x, perp_left_y = -to_obs_y, to_obs_x
        perp_right_x, perp_right_y = to_obs_y, -to_obs_x

        avoid_dist = orad * 1.5
        l_x, l_y = rx + perp_left_x * avoid_dist, ry + perp_left_y * avoid_dist
        r_x, r_y = rx + perp_right_x * avoid_dist, ry + perp_right_y * avoid_dist

        if math.hypot(l_x - tx, l_y - ty) < math.hypot(r_x - tx, r_y - ty):
            return l_x, l_y
        return r_x, r_y

def main(args=None):
    rclpy.init(args=args)
    node = LocalPlanner()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
