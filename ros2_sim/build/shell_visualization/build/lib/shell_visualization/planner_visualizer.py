import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Polygon, Point, Point32
from visualization_msgs.msg import Marker, MarkerArray
from std_msgs.msg import Float64MultiArray
from shell_interfaces.msg import Trajectory


class PlannerVisualizer(Node):

    def __init__(self):
        super().__init__('planner_visualizer')

        # ------------------ Subscriptions ------------------
        self.create_subscription(
            Polygon,
            '/track_boundary',
            self.track_cb,
            10
        )

        self.create_subscription(
            Float64MultiArray,
            '/obstacle_pose',
            self.obs_cb,
            10
        )

        self.create_subscription(
            Trajectory,
            '/planned_path',
            self.path_cb,
            10
        )

        # ------------------ Publisher ------------------
        self.marker_pub = self.create_publisher(
            MarkerArray,
            '/planner_markers',
            10
        )

        # ------------------ Stored data ------------------
        self.track = None
        self.obstacles = None
        self.path = None

        self.get_logger().info("Planner visualizer started")

    # =====================================================
    # Callbacks
    # =====================================================

    def track_cb(self, msg):
        self.track = msg
        self.publish_markers()

    def obs_cb(self, msg):
        self.obstacles = msg.data
        self.publish_markers()

    def path_cb(self, msg):
        self.path = msg
        self.publish_markers()

    # =====================================================
    # Visualization
    # =====================================================

    def publish_markers(self):
        markers = MarkerArray()
        marker_id = 0

        now = self.get_clock().now().to_msg()

        # ---------- Track boundary ----------
        if self.track is not None and len(self.track.points) > 0:
            m = Marker()
            m.header.frame_id = "map"
            m.header.stamp = now
            m.ns = "track"
            m.id = marker_id
            marker_id += 1

            m.type = Marker.LINE_STRIP
            m.action = Marker.ADD
            m.scale.x = 0.3

            m.color.r = 0.0
            m.color.g = 0.0
            m.color.b = 1.0
            m.color.a = 1.0

            m.points = []

            for p32 in self.track.points:  # Point32 → Point
                p = Point()
                p.x = float(p32.x)
                p.y = float(p32.y)
                p.z = float(p32.z)
                m.points.append(p)

            # close the loop
            p0_32 = self.track.points[0]
            p0 = Point()
            p0.x = float(p0_32.x)
            p0.y = float(p0_32.y)
            p0.z = float(p0_32.z)
            m.points.append(p0)

            markers.markers.append(m)

        # ---------- Obstacles ----------
        if self.obstacles is not None and len(self.obstacles) >= 2:
            for i in range(0, len(self.obstacles), 2):
                m = Marker()
                m.header.frame_id = "map"
                m.header.stamp = now
                m.ns = "obstacles"
                m.id = marker_id
                marker_id += 1

                m.type = Marker.SPHERE
                m.action = Marker.ADD

                m.pose.position.x = float(self.obstacles[i])
                m.pose.position.y = float(self.obstacles[i + 1])
                m.pose.position.z = 0.5

                m.scale.x = 1.0
                m.scale.y = 1.0
                m.scale.z = 1.0

                m.color.r = 1.0
                m.color.g = 0.0
                m.color.b = 0.0
                m.color.a = 1.0

                markers.markers.append(m)

        # ---------- Planned path ----------
        if self.path is not None and len(self.path.points) > 1:
            m = Marker()
            m.header.frame_id = "map"
            m.header.stamp = now
            m.ns = "path"
            m.id = marker_id
            marker_id += 1

            m.type = Marker.LINE_STRIP
            m.action = Marker.ADD
            m.scale.x = 0.25

            m.color.r = 0.0
            m.color.g = 1.0
            m.color.b = 0.0
            m.color.a = 1.0

            m.points = []

            for pt in self.path.points:  # Point32 → Point
                p = Point()
                p.x = float(pt.x)
                p.y = float(pt.y)
                p.z = 0.1
                m.points.append(p)

            markers.markers.append(m)

        self.marker_pub.publish(markers)


# =========================================================
# Main
# =========================================================

def main(args=None):
    rclpy.init(args=args)
    node = PlannerVisualizer()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
