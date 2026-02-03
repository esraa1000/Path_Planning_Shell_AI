import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/esraamustafa/path_planning/Path_Planning_Shell_AI/ros2_sim/install/shell_visualization'
