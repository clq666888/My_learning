#include "rclcpp/rclcpp.hpp"

class function_node : public rclcpp::Node
{
    private:
    public:
        function_node(std::string name) : Node(name)
        {
            RCLCPP_INFO(this->get_logger(), "Hello World!From NODE:%s", name.c_str());
        }

};

int main(int argc, char const *argv[])
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<function_node>("node_say_hello");
    
    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}








