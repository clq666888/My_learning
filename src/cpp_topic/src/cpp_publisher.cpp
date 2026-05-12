#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"  // 注意消息类型头文件
#include <chrono>
#include <functional>
#include <memory>

class publish_node : public rclcpp::Node
{
public:
    publish_node(const std::string name) : Node(name)
    {
        publisher_ = this->create_publisher<std_msgs::msg::String>("cpp_publisher_topic", 10);
                // 创建定时器，间隔1000毫秒（1秒），绑定回调函数
        timer_ = this->create_wall_timer(std::chrono::milliseconds(1000) , std::bind(&publish_node::timer_callback , this));
        
        RCLCPP_INFO(get_logger(), "I am a publisher cpp NODE:%s", name.c_str());
    }
private:
    void timer_callback()
    {
        // 构造消息
        auto msg = std_msgs::msg::String();
        msg.data = "hello " + std::to_string(count_);
        
        // 发布消息
        publisher_->publish(msg);
        
        // 打印日志
        RCLCPP_INFO(this->get_logger(), "Published: %s", msg.data.c_str());
        
        count_++;
    }
    
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;         //声明了发布者，用于发布消息的指针
    rclcpp::TimerBase::SharedPtr timer_;                                    //声明了定时器，用于定时发布消息   
    int count_ = 0;


};

int main(int argc, char * argv[])
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<publish_node>("cpp_publish");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}




