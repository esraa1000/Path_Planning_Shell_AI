import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Quaternion

class FakeLocalization(Node):

    def __init__(self):
        super().__init__('fake_localization')
        self.pub = self.create_publisher(Odometry, '/odom', 10)
        self.timer = self.create_timer(0.5, self.publish_odom)

    def publish_odom(self):
        msg = Odometry()
        msg.pose.pose.position.x = 10.0
        msg.pose.pose.position.y = 10.0

        # zero yaw
        q = Quaternion()
        q.w = 1.0
        msg.pose.pose.orientation = q

        self.pub.publish(msg)

def main():
    rclpy.init()
    node = FakeLocalization()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
