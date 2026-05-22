// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cpp_msg:msg/Mymsg.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "cpp_msg/msg/mymsg.hpp"


#ifndef CPP_MSG__MSG__DETAIL__MYMSG__STRUCT_HPP_
#define CPP_MSG__MSG__DETAIL__MYMSG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'image'
#include "sensor_msgs/msg/detail/image__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cpp_msg__msg__Mymsg __attribute__((deprecated))
#else
# define DEPRECATED__cpp_msg__msg__Mymsg __declspec(deprecated)
#endif

namespace cpp_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Mymsg_
{
  using Type = Mymsg_<ContainerAllocator>;

  explicit Mymsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : image(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->content = "";
    }
  }

  explicit Mymsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : content(_alloc),
    image(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->content = "";
    }
  }

  // field types and members
  using _content_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _content_type content;
  using _image_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _image_type image;

  // setters for named parameter idiom
  Type & set__content(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->content = _arg;
    return *this;
  }
  Type & set__image(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->image = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cpp_msg::msg::Mymsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const cpp_msg::msg::Mymsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cpp_msg::msg::Mymsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cpp_msg::msg::Mymsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cpp_msg::msg::Mymsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cpp_msg::msg::Mymsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cpp_msg::msg::Mymsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cpp_msg::msg::Mymsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cpp_msg::msg::Mymsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cpp_msg::msg::Mymsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cpp_msg__msg__Mymsg
    std::shared_ptr<cpp_msg::msg::Mymsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cpp_msg__msg__Mymsg
    std::shared_ptr<cpp_msg::msg::Mymsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Mymsg_ & other) const
  {
    if (this->content != other.content) {
      return false;
    }
    if (this->image != other.image) {
      return false;
    }
    return true;
  }
  bool operator!=(const Mymsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Mymsg_

// alias to use template instance with default allocator
using Mymsg =
  cpp_msg::msg::Mymsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cpp_msg

#endif  // CPP_MSG__MSG__DETAIL__MYMSG__STRUCT_HPP_
