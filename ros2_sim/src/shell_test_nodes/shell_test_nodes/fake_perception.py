import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Polygon, Point32
from std_msgs.msg import Float64MultiArray
import numpy as np


class FakePerception(Node):

    def __init__(self):
        super().__init__('fake_perception')

        self.track_pub = self.create_publisher(Polygon, '/track_boundary', 10)
        self.obs_pub = self.create_publisher(Float64MultiArray, '/obstacle_pose', 10)

        self.timer = self.create_timer(1.0, self.publish_data)
        self.get_logger().info("Fake Perception node started")

    def publish_data(self):
        # ---------- TRACK BOUNDARY ----------
        poly = Polygon()

        boundary = [
            (0.0, 0.0),
            (100.0, 0.0),
            (100.0, 50.0),
            (0.0, 50.0)
        ]

        for x, y in boundary:
            p = Point32()
            p.x = float(x)
            p.y = float(y)
            p.z = 0.0
            poly.points.append(p)

        self.track_pub.publish(poly)

        # ---------- OBSTACLES ----------
        obs_msg = Float64MultiArray()
        obs = []
        for _ in range(5):
            obs.append(50.0 + float(np.random.randn()) * 2.0)
            obs.append(25.0 + float(np.random.randn()) * 2.0)

        obs_msg.data = obs
        self.obs_pub.publish(obs_msg)

        self.get_logger().info(
            f"Published track with {len(poly.points)} points and {len(obs)//2} obstacles"
        )


def main():
    rclpy.init()
    node = FakePerception()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
