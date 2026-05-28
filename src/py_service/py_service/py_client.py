import rclpy                                     # ROS2 Python接口库
from rclpy.node import Node                      # ROS2 节点类
from service_interface.srv import Mysrv1         # 导入自定义服务接口

class client_node(Node): 
    def __init__(self,name):
        super().__init__(name)
        # 创建客户端：(服务类型, 服务名) 服务名必须和服务端一致
        self.client = self.create_client(Mysrv1, "Sum_of_positive_numbers")
        self.get_logger().info("I am a client")

    # 发送请求的函数
    def client_call(self):
        request = Mysrv1.Request()               # 创建空的请求对象
        request.a = 10
        request.b = 20
        self.get_logger().info("client need sum of positive numbers: a=%d, b=%d" % (request.a, request.b))
        
        # 等待服务端上线，每1秒检查一次
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().warn("service not available, waiting again...")

        # 异步发送请求，并绑定回调函数处理响应
        self.client.call_async(request).add_done_callback(self.client_callback)

    # 客户端回调：服务端返回响应时自动触发，参数固定为 (self, future)
    def client_callback(self,future):
        response = future.result()               # 从 future 中取出响应
        if response.success:
            self.get_logger().info("get server response: success=%d, sum=%d" % (response.success, response.sum))
        else:
            self.get_logger().info("service refuse calculate negative number")

def main(args=None):
    rclpy.init(args=args)
    node = client_node("py_client")
    node.client_call()                           # spin 之前先发送请求
    rclpy.spin(node)                             # 循环等待回调被触发
    node.destroy_node()
    rclpy.shutdown()

