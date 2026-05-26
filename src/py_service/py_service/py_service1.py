import rclpy                                     # ROS2 Python接口库
from rclpy.node import Node                      # ROS2 节点类
from service_interface.srv import Mysrv1

#   面向对象编程
class publish_node(Node):
    def __init__(self,name):
        super().__init__(name) 
        self.srv = self.create_service(Mysrv1,"py_service1",self.services1_callback)        
        self.get_logger().info("I am a service1")
        
    def services1_callback(self, request, response):
        response.success = True
        response.sum = request.a + request.b
        self.get_logger().info("get client data")
        return response
        
def main():
    rclpy.init()          
    node = publish_node("py_service1")
    rclpy.spin(node)                            
    node.destroy_node()
    rclpy.shutdown()
