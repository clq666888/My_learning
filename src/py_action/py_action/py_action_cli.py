import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from service_interface.action import Myact

class ActionClientNode(Node):
    def __init__(self, name):
        super().__init__(name)
        # 创建 Action 客户端：(类型, 动作名)
        self.client = ActionClient(self, Myact, "count_to_target")
        self.get_logger().info("I am an action client")



def main():
    rclpy.init()
    node = ActionClientNode("action_client")
    node.send_goal()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()