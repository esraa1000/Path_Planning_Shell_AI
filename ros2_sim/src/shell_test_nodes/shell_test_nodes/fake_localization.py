import rclpy
from rclpy.node import Node
import math
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Quaternion, Twist

class FakeLocalization(Node):

    def __init__(self):
        super().__init__('fake_localization')

        # State
        self.x = 0.0
        self.y = 0.0
        self.theta = 0.0
        self.v = 0.0
        self.w = 0.0
        self.last_time = self.get_clock().now()

        # Publishers & Subscriptions
        self.odom_pub = self.create_publisher(Odometry, '/odom', 10)
        self.cmd_sub = self.create_subscription(Twist, '/cmd_vel', self.cmd_cb, 10)

        # Publish at 50Hz
        self.timer = self.create_timer(0.02, self.publish_odom)

        self.get_logger().info("Fake Localization (Dynamic) started")

    def cmd_cb(self, msg):
        self.v = msg.linear.x
        self.w = msg.angular.z

    def publish_odom(self):
        now = self.get_clock().now()
        dt = (now - self.last_time).nanoseconds / 1e9
        self.last_time = now

        # Unicycle model integration
        self.x += self.v * math.cos(self.theta) * dt
        self.y += self.v * math.sin(self.theta) * dt
        self.theta += self.w * dt
        self.theta = (self.theta + math.pi) % (2 * math.pi) - math.pi

        # Create Odometry message
        msg = Odometry()
        msg.header.stamp = now.to_msg()
        msg.header.frame_id = 'map'
        msg.child_frame_id = 'base_link'

        msg.pose.pose.position.x = self.x
        msg.pose.pose.position.y = self.y

        # Yaw to Quaternion
        q = Quaternion()
        q.x = 0.0
        q.y = 0.0
        q.z = math.sin(self.theta / 2.0)
        q.w = math.cos(self.theta / 2.0)
        msg.pose.pose.orientation = q

        msg.twist.twist.linear.x = self.v
        msg.twist.twist.angular.z = self.w

        self.odom_pub.publish(msg)

def main():
    rclpy.init()
    node = FakeLocalization()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
