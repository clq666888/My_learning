import rclpy
from rclpy.node import Node

class ParameterNode(Node):
    def __init__(self,name):
        super().__init__(name)
        self.get_logger().info("I am a parameter node")
        self.timer = self.create_timer(1,self.timer_callback)
        self.declare_parameter("my_number",1.0)
        self.declare_parameter("my_string","hello world")
    
    def timer_callback(self):
        self.get_logger().info("current number is %f" % self.get_parameter("my_number").value)
        self.get_logger().info("current string is %s" % self.get_parameter("my_string").value)


def main(args=None):
    rclpy.init(args=args)
    node = ParameterNode("py_parameter")
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()    











