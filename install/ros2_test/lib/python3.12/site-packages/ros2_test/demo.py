import rclpy                                     # ROS2 Python接口库
from rclpy.node import Node                      # ROS2 节点类
import time

#   面向对象编程
class say_hello(Node):
    def __init__(self,name):
        super().__init__(name)                    
        while rclpy.ok():
            self.get_logger().info("Hello")
            time.sleep(0.5)        

def main():
    rclpy.init()
    node = say_hello("node_say_hello")
    node.destroy_node()
    rclpy.shutdown()


#   面向过程编程
def hello(args=None):                             # ROS2节点主入口hello函数
    rclpy.init(args=args)                        # ROS2 Python接口初始化
    node = Node("node_helloworld")               # 创建ROS2节点对象并进行初始化
    
    while rclpy.ok():                            # ROS2系统是否正常运行
        node.get_logger().info("Hello World")    # ROS2日志输出
        time.sleep(0.5)                          # 休眠控制循环时间
    
    rclpy.spin(node);                            # 进入ROS2事件循环
    node.destroy_node()                          # 销毁节点对象    
    rclpy.shutdown()                             # 关闭ROS2 Python接口


