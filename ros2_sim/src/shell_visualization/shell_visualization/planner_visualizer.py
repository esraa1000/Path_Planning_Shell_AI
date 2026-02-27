import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Point
from visualization_msgs.msg import Marker, MarkerArray

# UPDATED IMPORTS
from shell_interfaces.msg import Trajectory, Boundary, ObstacleArray

class PlannerVisualizer(Node):

    def __init__(self):
        super().__init__('planner_visualizer')

        # ------------------ Subscriptions ------------------
        # 1. Left Boundary
        self.create_subscription(
            Boundary,
            '/left_boundary',
            self.left_cb,
            10
        )

        # 2. Right Boundary
        self.create_subscription(
            Boundary,
            '/right_boundary',
            self.right_cb,
            10
        )

        # 3. Obstacles (Custom Message)
        self.create_subscription(
            ObstacleArray,
            '/obstacles',
            self.obs_cb,
            10
        )

        # 4. Planned Path
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
        self.left_bound = None
        self.right_bound = None
        self.obstacles = None
        self.path = None
        
        # Publish at 10Hz
        self.timer = self.create_timer(0.1, self.publish_markers)

        self.get_logger().info("Planner Visualizer Started (Shell Interfaces)")

    # =====================================================
    # Callbacks
    # =====================================================

    def left_cb(self, msg):
        self.left_bound = msg

    def right_cb(self, msg):
        self.right_bound = msg

    def obs_cb(self, msg):
        self.obstacles = msg

    def path_cb(self, msg):
        self.path = msg

    # =====================================================
    # Visualization Logic
    # =====================================================

    def publish_markers(self):
        markers = MarkerArray()
        marker_id = 0
        now = self.get_clock().now().to_msg()

        # -------------------------------------------------
        # 1. VISUALIZE LEFT BOUNDARY (Blue Line)
        # -------------------------------------------------
        if self.left_bound:
            m = Marker()
            m.header.frame_id = "map"
            m.header.stamp = now
            m.ns = "boundaries"
            m.id = marker_id
            marker_id += 1
            m.type = Marker.LINE_STRIP
            m.action = Marker.ADD
            m.scale.x = 0.2  # Line width
            m.color.r = 0.0; m.color.g = 0.0; m.color.b = 1.0; m.color.a = 1.0 # Blue

            for pt in self.left_bound.points:
                p = Point()
                p.x = float(pt.x)
                p.y = float(pt.y)
                p.z = 0.0
                m.points.append(p)
            
            markers.markers.append(m)

        # -------------------------------------------------
        # 2. VISUALIZE RIGHT BOUNDARY (Red Line)
        # -------------------------------------------------
        if self.right_bound:
            m = Marker()
            m.header.frame_id = "map"
            m.header.stamp = now
            m.ns = "boundaries"
            m.id = marker_id
            marker_id += 1
            m.type = Marker.LINE_STRIP
            m.action = Marker.ADD
            m.scale.x = 0.2
            m.color.r = 1.0; m.color.g = 0.0; m.color.b = 0.0; m.color.a = 1.0 # Red

            for pt in self.right_bound.points:
                p = Point()
                p.x = float(pt.x)
                p.y = float(pt.y)
                p.z = 0.0
                m.points.append(p)
            
            markers.markers.append(m)

        # -------------------------------------------------
        # 3. VISUALIZE OBSTACLES (Yellow Cylinders)
        # -------------------------------------------------
        if self.obstacles:
            for obs in self.obstacles.obstacles:
                m = Marker()
                m.header.frame_id = "map"
                m.header.stamp = now
                m.ns = "obstacles"
                m.id = marker_id
                marker_id += 1
                m.type = Marker.CYLINDER
                m.action = Marker.ADD
                
                m.pose.position.x = obs.center.x
                m.pose.position.y = obs.center.y
                m.pose.position.z = 0.5 # Raise it slightly

                # Use radius from message, or default
                d = obs.radius * 2.0 if obs.radius > 0 else 1.0
                m.scale.x = d
                m.scale.y = d
                m.scale.z = 1.0 # Height

                m.color.r = 1.0; m.color.g = 1.0; m.color.b = 0.0; m.color.a = 1.0 # Yellow

                markers.markers.append(m)

        # -------------------------------------------------
        # 4. VISUALIZE PLANNED PATH (Green Line)
        # -------------------------------------------------
        if self.path and len(self.path.points) > 0:
            m = Marker()
            m.header.frame_id = "map"
            m.header.stamp = now
            m.ns = "path"
            m.id = marker_id
            marker_id += 1
            m.type = Marker.LINE_STRIP
            m.action = Marker.ADD
            m.scale.x = 0.3 # Thicker line
            m.color.r = 0.0; m.color.g = 1.0; m.color.b = 0.0; m.color.a = 1.0 # Green

            for tp in self.path.points:
                p = Point()
                p.x = float(tp.x)
                p.y = float(tp.y)
                p.z = 0.1 # Draw slightly above ground
                m.points.append(p)

            markers.markers.append(m)

        # Publish all markers
        self.marker_pub.publish(markers)


def main(args=None):
    rclpy.init(args=args)
    node = PlannerVisualizer()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()