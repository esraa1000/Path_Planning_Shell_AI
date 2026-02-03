import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Polygon, Point32
from std_msgs.msg import Float64MultiArray


class FakePerception(Node):

    def __init__(self):
        super().__init__('fake_perception')

        self.track_pub = self.create_publisher(Polygon, '/track_boundary', 10)
        self.obs_pub = self.create_publisher(Float64MultiArray, '/obstacle_pose', 10)

        self.timer = self.create_timer(1.0, self.publish_data)
        self.get_logger().info("Fake Perception node started")

    # def publish_data(self):
    #     # ---------- TRACK BOUNDARY ----------
    #     poly = Polygon()

    #     boundary = [
    #         (0.0, 0.0),
    #         (200.0, 0.0),
    #         (200.0, 120.0),
    #         (180.0, 140.0),
    #         (160.0, 120.0),
    #         (140.0, 140.0),
    #         (120.0, 120.0),
    #         (100.0, 140.0),
    #         (80.0, 120.0),
    #         (60.0, 140.0),
    #         (40.0, 120.0),
    #         (0.0, 120.0)
    #     ]

    #     for x, y in boundary:
    #         p = Point32()
    #         p.x = float(x)
    #         p.y = float(y)
    #         p.z = 0.0
    #         poly.points.append(p)

    #     self.track_pub.publish(poly)

    #     # ---------- OBSTACLES ----------
    #     obs_msg = Float64MultiArray()
    #     obs_msg.data = [
    #         50.0, 60.0,
    #         70.0, 70.0,
    #         100.0, 80.0,
    #         130.0, 100.0,
    #         160.0, 110.0,
    #     ]
    #     self.obs_pub.publish(obs_msg)

    def publish_data(self):
        # ---------- TRACK BOUNDARY (Urban Eco-Shell Style) ----------
        poly = Polygon()

        # Approximate urban loop with smooth turns & chicane
        boundary = [
            # Start straight
            (0.0, 0.0),
            (80.0, 0.0),
            (140.0, 0.0),

            # First wide right turn
            (160.0, 10.0),
            (175.0, 25.0),
            (180.0, 45.0),
            (180.0, 70.0),

            # Long straight
            (180.0, 100.0),
            (180.0, 130.0),

            # Top curve (left)
            (170.0, 145.0),
            (150.0, 155.0),
            (120.0, 155.0),

            # Urban chicane section
            (105.0, 145.0),
            (90.0, 155.0),
            (75.0, 145.0),
            (60.0, 155.0),

            # Left straight
            (40.0, 150.0),
            (20.0, 140.0),
            (5.0, 120.0),

            # Downward straight
            (0.0, 100.0),
            (0.0, 70.0),
            (0.0, 40.0),

            # Final curve back to start
            (5.0, 20.0),
            (15.0, 5.0),
            (0.0, 0.0)  # close loop
        ]

        for x, y in boundary:
            p = Point32()
            p.x = float(x)
            p.y = float(y)
            p.z = 0.0
            poly.points.append(p)

        self.track_pub.publish(poly)

        # ---------- OBSTACLES (Urban cones / checkpoints) ----------
        obs_msg = Float64MultiArray()
        obs_msg.data = [
            # Straight section
            50.0, 10.0,
            100.0, 10.0,

            # First curve
            160.0, 40.0,

            # Long straight
            170.0, 90.0,

            # Top section
            140.0, 150.0,

            # Chicane cones
            95.0, 145.0,
            75.0, 145.0,

            # Left section
            30.0, 135.0,

            # Bottom straight
            10.0, 60.0,
        ]

        self.obs_pub.publish(obs_msg)

        self.get_logger().info(
            f"Published track with {len(poly.points)} points and {len(obs_msg.data)//2} obstacles"
        )


def main():
    rclpy.init()
    node = FakePerception()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
