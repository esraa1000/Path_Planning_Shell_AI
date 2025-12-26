import rclpy
from rclpy.node import Node

from std_msgs.msg import Bool, UInt64
from geometry_msgs.msg import Polygon
from std_msgs.msg import Float64MultiArray
from nav_msgs.msg import Odometry

from shell_interfaces.msg import Trajectory, TrajectoryPoint


class GlobalPlanner(Node):

    def __init__(self):
        super().__init__('global_planner')

        # Subscriptions
        self.create_subscription(Polygon, '/track_boundary', self.track_cb, 10)
        self.create_subscription(Float64MultiArray, '/obstacle_pose', self.obs_cb, 10)
        self.create_subscription(Odometry, '/odom', self.odom_cb, 10)
        self.create_subscription(Bool, '/start_signal', self.start_cb, 10)

        # Publishers
        self.path_pub = self.create_publisher(Trajectory, '/planned_path', 10)
        self.heartbeat_pub = self.create_publisher(UInt64, '/planner_heartbeat', 10)

        # Heartbeat timer (1 Hz)
        self.create_timer(1.0, self.publish_heartbeat)

        # Internal state
        self.started = False
        self.have_track = False
        self.have_odom = False

        self.get_logger().info("Global Planner node started")

    def start_cb(self, msg):
        self.started = msg.data
        self.get_logger().info(f"Start signal: {self.started}")
        if self.started:
            self.try_publish_dummy_path()

    def track_cb(self, msg):
        self.have_track = True
        self.get_logger().info("Received track boundary")

    def obs_cb(self, msg):
        self.get_logger().info(f"Received {len(msg.data)//2} obstacles")

    def odom_cb(self, msg):
        self.have_odom = True

    def try_publish_dummy_path(self):
        if not (self.have_track and self.have_odom):
            self.get_logger().warn("Cannot plan yet (missing track or odom)")
            return

        traj = Trajectory()

        for i in range(5):
            p = TrajectoryPoint()
            p.x = 10.0 + i * 2.0
            p.y = 10.0
            p.theta = 0.0
            p.v = 2.0
            traj.points.append(p)

        self.path_pub.publish(traj)
        self.get_logger().info("Published dummy trajectory")

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
