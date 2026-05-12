import rclpy                                     # ROS2 Python接口库
from rclpy.node import Node                      # ROS2 节点类
import time

#   面向对象编程
class writenode(Node):
    def __init__(self,name):
        super().__init__(name)                    
        self.get_logger().info("I am a publisher")   
        self.timer =self.create_timer(1,self.publish_callback)
        self.count = 0

    def publish_callback(self):
        self.get_logger().info("this page is %d" % self.count)
        self.count += 1

def main():
    rclpy.init()          
    node = writenode("publisher")
    rclpy.spin(node)                            
    node.destroy_node()
    rclpy.shutdown()


