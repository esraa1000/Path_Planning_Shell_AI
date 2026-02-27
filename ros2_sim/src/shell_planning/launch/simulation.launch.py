import os
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import TimerAction

def generate_launch_description():
    return LaunchDescription([
        
        # 1. Fake Perception (Track & Obstacles)
        Node(
            package='shell_test_nodes',
            executable='fake_perception',
            name='fake_perception'
        ),

        # 2. Fake Localization (Odometry)
        Node(
            package='shell_test_nodes',
            executable='fake_localization',
            name='fake_localization'
        ),

        # 3. Fake Control (Receives trajectory, maybe moves car?)
        Node(
            package='shell_test_nodes',
            executable='fake_control',
            name='fake_control'
        ),

        # 4. local Planner (The Brain) - output='screen' shows logs
        Node(
            package='shell_planning',
            executable='local_planner',
            name='local_planner',
            output='screen' 
        ),

        # 5. Planner Visualizer (Markers for RViz)
        Node(
            package='shell_visualization',
            executable='planner_visualizer',
            name='planner_visualizer'
        ),

        # 6. Fake Supervisor (Sends Start Signal)
        # We put this last effectively, though ROS starts them in parallel.
    TimerAction(
        period=3.0, # Wait 3 seconds before starting supervisor
        actions=[
            Node(
                package='shell_test_nodes',
                executable='fake_supervisor',
                name='fake_supervisor',
                output='screen'
            )
        ]
    )
    ])