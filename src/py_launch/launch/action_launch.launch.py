# 1.导入文件
from launch import LaunchDescription          # 导入启动描述器
from launch_ros.actions import Node            # 导入节点动作

# 2.定义生成函数
def generate_launch_description():

    # 3.创建节点对象
    # ====== 动作服务端 ======
    action_server = Node(
        package='py_action',                   # 包名
        executable='py_action_ser',            # 入口名
        output='screen',                       # 日志打印到终端
    )

    # ====== 动作客户端 ======
    action_client = Node(
        package='py_action',
        executable='py_action_cli',
        output='screen',
    )

    # 4.组装启动描述
    launch_d = LaunchDescription([
        action_server,                         # 服务端放进去
        action_client,                         # 客户端放进去
    ])

    # 5.返回
    return launch_d