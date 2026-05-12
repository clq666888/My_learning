import rclpy                                     # ROS2 Python接口库
from rclpy.node import Node                      # ROS2 节点类
import time
from std_msgs.msg import String                   # 标准消息类型

#   面向对象编程
class publish_node(Node):
    def __init__(self,name):
        super().__init__(name)                    
        self.get_logger().info("I am a publisher")  
        self.publisher = self.create_publisher(String, "py_publisher_topic", 10) 
        self.timer =self.create_timer(1,self.publish_callback)
        self.count = 0

    def publish_callback(self):
        msg=String()
        msg.data="this page is %d" % self.count
        self.publisher.publish(msg)
        self.get_logger().info("已发布消息: %s" % msg.data)
        self.count += 1

def main():
    rclpy.init()          
    node = publish_node("py_publisher")
    rclpy.spin(node)                            
    node.destroy_node()
    rclpy.shutdown()


