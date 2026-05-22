// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from cpp_msg:msg/Mymsg.idl
// generated code does not contain a copyright notice
#ifndef CPP_MSG__MSG__DETAIL__MYMSG__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define CPP_MSG__MSG__DETAIL__MYMSG__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "cpp_msg/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "cpp_msg/msg/detail/mymsg__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_cpp_msg
bool cdr_serialize_cpp_msg__msg__Mymsg(
  const cpp_msg__msg__Mymsg * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_cpp_msg
bool cdr_deserialize_cpp_msg__msg__Mymsg(
  eprosima::fastcdr::Cdr &,
  cpp_msg__msg__Mymsg * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_cpp_msg
size_t get_serialized_size_cpp_msg__msg__Mymsg(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_cpp_msg
size_t max_serialized_size_cpp_msg__msg__Mymsg(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_cpp_msg
bool cdr_serialize_key_cpp_msg__msg__Mymsg(
  const cpp_msg__msg__Mymsg * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_cpp_msg
size_t get_serialized_size_key_cpp_msg__msg__Mymsg(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_cpp_msg
size_t max_serialized_size_key_cpp_msg__msg__Mymsg(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_cpp_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, cpp_msg, msg, Mymsg)();

#ifdef __cplusplus
}
#endif

#endif  // CPP_MSG__MSG__DETAIL__MYMSG__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
