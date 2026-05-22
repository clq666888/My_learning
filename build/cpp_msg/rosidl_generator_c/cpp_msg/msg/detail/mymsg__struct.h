// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cpp_msg:msg/Mymsg.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "cpp_msg/msg/mymsg.h"


#ifndef CPP_MSG__MSG__DETAIL__MYMSG__STRUCT_H_
#define CPP_MSG__MSG__DETAIL__MYMSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'content'
#include "rosidl_runtime_c/string.h"
// Member 'image'
#include "sensor_msgs/msg/detail/image__struct.h"

/// Struct defined in msg/Mymsg in the package cpp_msg.
/**
  * 调用原始数据类型
 */
typedef struct cpp_msg__msg__Mymsg
{
  rosidl_runtime_c__String content;
  /// 调用已由的消息类型
  sensor_msgs__msg__Image image;
} cpp_msg__msg__Mymsg;

// Struct for a sequence of cpp_msg__msg__Mymsg.
typedef struct cpp_msg__msg__Mymsg__Sequence
{
  cpp_msg__msg__Mymsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cpp_msg__msg__Mymsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CPP_MSG__MSG__DETAIL__MYMSG__STRUCT_H_
