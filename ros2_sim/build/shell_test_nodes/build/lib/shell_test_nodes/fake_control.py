import rclpy
from rclpy.node import Node
from shell_interfaces.msg import Trajectory

class FakeControl(Node):

    def __init__(self):
        super().__init__('fake_control')
        self.create_subscription(
            Trajectory,
            '/planned_path',
            self.cb,
            10
        )

    def cb(self, msg):
        self.get_logger().info(
            f"Received trajectory with {len(msg.points)} points"
        )

def main():
    rclpy.init()
    node = FakeControl()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
