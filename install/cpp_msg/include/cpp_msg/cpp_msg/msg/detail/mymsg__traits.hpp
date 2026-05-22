// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cpp_msg:msg/Mymsg.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "cpp_msg/msg/mymsg.hpp"


#ifndef CPP_MSG__MSG__DETAIL__MYMSG__TRAITS_HPP_
#define CPP_MSG__MSG__DETAIL__MYMSG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cpp_msg/msg/detail/mymsg__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'image'
#include "sensor_msgs/msg/detail/image__traits.hpp"

namespace cpp_msg
{

namespace msg
{

inline void to_flow_style_yaml(
  const Mymsg & msg,
  std::ostream & out)
{
  out << "{";
  // member: content
  {
    out << "content: ";
    rosidl_generator_traits::value_to_yaml(msg.content, out);
    out << ", ";
  }

  // member: image
  {
    out << "image: ";
    to_flow_style_yaml(msg.image, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Mymsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: content
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "content: ";
    rosidl_generator_traits::value_to_yaml(msg.content, out);
    out << "\n";
  }

  // member: image
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "image:\n";
    to_block_style_yaml(msg.image, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Mymsg & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace cpp_msg

namespace rosidl_generator_traits
{

[[deprecated("use cpp_msg::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cpp_msg::msg::Mymsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  cpp_msg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cpp_msg::msg::to_yaml() instead")]]
inline std::string to_yaml(const cpp_msg::msg::Mymsg & msg)
{
  return cpp_msg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cpp_msg::msg::Mymsg>()
{
  return "cpp_msg::msg::Mymsg";
}

template<>
inline const char * name<cpp_msg::msg::Mymsg>()
{
  return "cpp_msg/msg/Mymsg";
}

template<>
struct has_fixed_size<cpp_msg::msg::Mymsg>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cpp_msg::msg::Mymsg>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cpp_msg::msg::Mymsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CPP_MSG__MSG__DETAIL__MYMSG__TRAITS_HPP_
