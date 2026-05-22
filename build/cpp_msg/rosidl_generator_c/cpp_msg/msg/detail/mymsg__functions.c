// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cpp_msg:msg/Mymsg.idl
// generated code does not contain a copyright notice
#include "cpp_msg/msg/detail/mymsg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `content`
#include "rosidl_runtime_c/string_functions.h"
// Member `image`
#include "sensor_msgs/msg/detail/image__functions.h"

bool
cpp_msg__msg__Mymsg__init(cpp_msg__msg__Mymsg * msg)
{
  if (!msg) {
    return false;
  }
  // content
  if (!rosidl_runtime_c__String__init(&msg->content)) {
    cpp_msg__msg__Mymsg__fini(msg);
    return false;
  }
  // image
  if (!sensor_msgs__msg__Image__init(&msg->image)) {
    cpp_msg__msg__Mymsg__fini(msg);
    return false;
  }
  return true;
}

void
cpp_msg__msg__Mymsg__fini(cpp_msg__msg__Mymsg * msg)
{
  if (!msg) {
    return;
  }
  // content
  rosidl_runtime_c__String__fini(&msg->content);
  // image
  sensor_msgs__msg__Image__fini(&msg->image);
}

bool
cpp_msg__msg__Mymsg__are_equal(const cpp_msg__msg__Mymsg * lhs, const cpp_msg__msg__Mymsg * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // content
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->content), &(rhs->content)))
  {
    return false;
  }
  // image
  if (!sensor_msgs__msg__Image__are_equal(
      &(lhs->image), &(rhs->image)))
  {
    return false;
  }
  return true;
}

bool
cpp_msg__msg__Mymsg__copy(
  const cpp_msg__msg__Mymsg * input,
  cpp_msg__msg__Mymsg * output)
{
  if (!input || !output) {
    return false;
  }
  // content
  if (!rosidl_runtime_c__String__copy(
      &(input->content), &(output->content)))
  {
    return false;
  }
  // image
  if (!sensor_msgs__msg__Image__copy(
      &(input->image), &(output->image)))
  {
    return false;
  }
  return true;
}

cpp_msg__msg__Mymsg *
cpp_msg__msg__Mymsg__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_msg__msg__Mymsg * msg = (cpp_msg__msg__Mymsg *)allocator.allocate(sizeof(cpp_msg__msg__Mymsg), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cpp_msg__msg__Mymsg));
  bool success = cpp_msg__msg__Mymsg__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cpp_msg__msg__Mymsg__destroy(cpp_msg__msg__Mymsg * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cpp_msg__msg__Mymsg__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cpp_msg__msg__Mymsg__Sequence__init(cpp_msg__msg__Mymsg__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_msg__msg__Mymsg * data = NULL;

  if (size) {
    data = (cpp_msg__msg__Mymsg *)allocator.zero_allocate(size, sizeof(cpp_msg__msg__Mymsg), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cpp_msg__msg__Mymsg__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cpp_msg__msg__Mymsg__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
cpp_msg__msg__Mymsg__Sequence__fini(cpp_msg__msg__Mymsg__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      cpp_msg__msg__Mymsg__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

cpp_msg__msg__Mymsg__Sequence *
cpp_msg__msg__Mymsg__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_msg__msg__Mymsg__Sequence * array = (cpp_msg__msg__Mymsg__Sequence *)allocator.allocate(sizeof(cpp_msg__msg__Mymsg__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cpp_msg__msg__Mymsg__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cpp_msg__msg__Mymsg__Sequence__destroy(cpp_msg__msg__Mymsg__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cpp_msg__msg__Mymsg__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cpp_msg__msg__Mymsg__Sequence__are_equal(const cpp_msg__msg__Mymsg__Sequence * lhs, const cpp_msg__msg__Mymsg__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cpp_msg__msg__Mymsg__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cpp_msg__msg__Mymsg__Sequence__copy(
  const cpp_msg__msg__Mymsg__Sequence * input,
  cpp_msg__msg__Mymsg__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cpp_msg__msg__Mymsg);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cpp_msg__msg__Mymsg * data =
      (cpp_msg__msg__Mymsg *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cpp_msg__msg__Mymsg__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cpp_msg__msg__Mymsg__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cpp_msg__msg__Mymsg__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
