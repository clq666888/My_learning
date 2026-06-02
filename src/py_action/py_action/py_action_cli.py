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

    def send_goal(self):
        self.client.wait_for_server()          # 等服务端上线，没上线就一直等
        goal_msg = Myact.Goal()                # 创建一个空的目标对象
        goal_msg.target_number = 10            # 填上要数到几
        # 把目标异步发出去，同时指定收到反馈时调用哪个函数
        self.send_goal_future = self.client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)
        # 设置表态回调函数，调用 goal_response_callback
        self.send_goal_future.add_done_callback(self.goal_response_callback)

    # 服务端表态（接 / 不接）后，自动跑这个函数
    def goal_response_callback(self, future):
        goal_handle = future.result()                # 从回执单里取出「任务句柄」
        if not goal_handle.accepted:                 # 如果服务端拒绝了
            self.get_logger().info("目标被拒绝")
            return                                   # 不接就直接结束
        self.get_logger().info("目标被接受，等待结果...")
        self.result_future = goal_handle.get_result_async()      # 异步去要最终结果
        self.result_future.add_done_callback(self.get_result_callback)  # 结果回来后调用 get_result_callback

    # 每次服务端发来反馈，就自动跑这个函数
    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback                                # 从消息里取出反馈本体
        self.get_logger().info("收到反馈：%d" % feedback.current_number)  # 打印当前数到几

    # 服务端干完活、返回最终结果时，自动跑这个函数
    def get_result_callback(self, future):
        result = future.result().result          # 从回执单里取出最终结果本体
        self.get_logger().info("最终结果：成功=%s，总和=%d" % (result.success, result.final_sum))

def main():
    rclpy.init()
    node = ActionClientNode("action_client")
    node.send_goal()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()