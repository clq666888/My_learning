// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from cpp_msg:msg/Mymsg.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "cpp_msg/msg/detail/mymsg__functions.h"
#include "cpp_msg/msg/detail/mymsg__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace cpp_msg
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Mymsg_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) cpp_msg::msg::Mymsg(_init);
}

void Mymsg_fini_function(void * message_memory)
{
  auto typed_message = static_cast<cpp_msg::msg::Mymsg *>(message_memory);
  typed_message->~Mymsg();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Mymsg_message_member_array[2] = {
  {
    "content",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cpp_msg::msg::Mymsg, content),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "image",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sensor_msgs::msg::Image>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cpp_msg::msg::Mymsg, image),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Mymsg_message_members = {
  "cpp_msg::msg",  // message namespace
  "Mymsg",  // message name
  2,  // number of fields
  sizeof(cpp_msg::msg::Mymsg),
  false,  // has_any_key_member_
  Mymsg_message_member_array,  // message members
  Mymsg_init_function,  // function to initialize message memory (memory has to be allocated)
  Mymsg_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Mymsg_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Mymsg_message_members,
  get_message_typesupport_handle_function,
  &cpp_msg__msg__Mymsg__get_type_hash,
  &cpp_msg__msg__Mymsg__get_type_description,
  &cpp_msg__msg__Mymsg__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace cpp_msg


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<cpp_msg::msg::Mymsg>()
{
  return &::cpp_msg::msg::rosidl_typesupport_introspection_cpp::Mymsg_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, cpp_msg, msg, Mymsg)() {
  return &::cpp_msg::msg::rosidl_typesupport_introspection_cpp::Mymsg_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
