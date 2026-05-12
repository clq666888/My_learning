import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class subscription_node(Node): 
    def __init__(self,name):
        super().__init__(name)
        self.subscription = self.create_subscription(String, "cpp_publisher_topic", self.subscription_callback, 10)
        self.get_logger().info("I am a subscriber")
    
    def subscription_callback(self, msg):
        self.get_logger().info("I heard: {}".format(msg.data))


def main(args=None):
    rclpy.init(args=args)
    node = subscription_node("py_subscription")
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


