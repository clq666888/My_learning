// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cpp_msg:msg/Mymsg.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "cpp_msg/msg/mymsg.hpp"


#ifndef CPP_MSG__MSG__DETAIL__MYMSG__BUILDER_HPP_
#define CPP_MSG__MSG__DETAIL__MYMSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cpp_msg/msg/detail/mymsg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cpp_msg
{

namespace msg
{

namespace builder
{

class Init_Mymsg_image
{
public:
  explicit Init_Mymsg_image(::cpp_msg::msg::Mymsg & msg)
  : msg_(msg)
  {}
  ::cpp_msg::msg::Mymsg image(::cpp_msg::msg::Mymsg::_image_type arg)
  {
    msg_.image = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cpp_msg::msg::Mymsg msg_;
};

class Init_Mymsg_content
{
public:
  Init_Mymsg_content()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Mymsg_image content(::cpp_msg::msg::Mymsg::_content_type arg)
  {
    msg_.content = std::move(arg);
    return Init_Mymsg_image(msg_);
  }

private:
  ::cpp_msg::msg::Mymsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cpp_msg::msg::Mymsg>()
{
  return cpp_msg::msg::builder::Init_Mymsg_content();
}

}  // namespace cpp_msg

#endif  // CPP_MSG__MSG__DETAIL__MYMSG__BUILDER_HPP_
