import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from service_interface.action import Myact
import time


class ActionServerNode(Node):
    def __init__(self, name):
        super().__init__(name)
        # 创建 Action 服务：(类型, 动作名, 回调函数)
        self.action_server = ActionServer(self,Myact,"count_to_target",self.action_callback)
        self.get_logger().info("I am an action server")

    # 收到目标时触发（类似服务的回调）
    def action_callback(self, goal_handle):
        target = goal_handle.request.target_number    # 读取客户端发来的目标值
        feedback = Myact.Feedback()                   # 创建一个空的反馈对象
        result = Myact.Result()                       # 创建一个空的结果对象
        for i in range(1, target + 1):
            feedback.current_number = i               # 把当前数到几填进反馈
            goal_handle.publish_feedback(feedback)    # 把反馈发给客户端
            self.get_logger().info("数到了：%d" % i)   # 服务端打印一下
            time.sleep(0.5)                           # 模拟耗时，每数一个停0.5秒
        goal_handle.succeed()                        # 标记任务成功完成
        result.success = True                        # 填结果：成功
        result.final_sum = sum(range(1, target + 1)) # 填结果：1到target的总和
        return result                                # 把结果返回给客户端


def main():
    rclpy.init()
    node = ActionServerNode("action_server")
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()