#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"   // 订阅的消息类型

class subscription_node : public rclcpp::Node
{
public:
    subscription_node(const std::string & name) : Node(name)
    {
        // 创建订阅者，订阅话题 ，队列大小10，绑定回调函数
        subscription_ = this->create_subscription<std_msgs::msg::String>(
            "py_publisher_topic", 10, std::bind(&subscription_node::topic_callback, this, std::placeholders::_1));
        RCLCPP_INFO(this->get_logger(), "订阅者已启动，等待话题的消息...");
    }

private:
    void topic_callback(const std_msgs::msg::String::SharedPtr msg) const
    {
        // 收到消息时打印出来
        RCLCPP_INFO(this->get_logger(), "cpp_subscription收到消息: '%s'", msg->data.c_str());
    }

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<subscription_node>("cpp_subscription");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}