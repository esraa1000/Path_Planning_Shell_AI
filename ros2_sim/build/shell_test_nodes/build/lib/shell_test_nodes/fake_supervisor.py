import rclpy
from rclpy.node import Node
from std_msgs.msg import Bool

class FakeSupervisor(Node):

    def __init__(self):
        super().__init__('fake_supervisor')
        self.pub = self.create_publisher(Bool, '/start_signal', 10)

        # Send start after 2 seconds
        self.timer = self.create_timer(2.0, self.send_start)

    def send_start(self):
        msg = Bool()
        msg.data = True
        self.pub.publish(msg)
        self.get_logger().info("START signal sent")

def main():
    rclpy.init()
    node = FakeSupervisor()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
