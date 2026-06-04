from launch import LaunchDescription          # 导入启动描述器
from launch_ros.actions import Node            # 导入节点动作

def generate_launch_description():
    parameter_server = Node(
        package='py_parameter',
        executable='py_parameter',
        output='screen',
        parameters=[
            {'my_number': 99.0},
            {'my_string': 'hello clq'},
        ]
    )

    launch_d = LaunchDescription([
        parameter_server,
    ])
    
    return launch_d

