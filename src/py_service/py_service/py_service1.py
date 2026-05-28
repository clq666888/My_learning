import rclpy                                     # ROS2 Python接口库
from rclpy.node import Node                      # ROS2 节点类
from service_interface.srv import Mysrv1         # 导入自定义服务接口

class publish_node(Node):
    def __init__(self,name):
        super().__init__(name)
        # 创建服务：(服务类型, 服务名, 回调函数)
        self.srv = self.create_service(Mysrv1,"Sum_of_positive_numbers",self.services1_callback)        
        self.get_logger().info("我是只对正数求和的服务")

    # 服务回调：客户端发请求时自动触发，参数固定为 (self, request, response)
    def services1_callback(self, request, response):
        if request.a > 0 and request.b > 0:
            response.success = True
            response.sum = request.a + request.b
            self.get_logger().info("get client data: a=%d, b=%d \r\n return sum=%d" % (request.a, request.b, response.sum))
            return response                      # 必须 return response
        else:
            response.success = False
            self.get_logger().info("service1 refuse caculate negative number")
            return response


def main():
    rclpy.init()          
    node = publish_node("py_service1")
    rclpy.spin(node)                             # 循环等待客户端请求
    node.destroy_node()
    rclpy.shutdown()
