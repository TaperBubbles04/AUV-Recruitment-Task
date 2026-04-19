// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from auv_interfaces:msg/BotPose.idl
// generated code does not contain a copyright notice
#include "auv_interfaces/msg/detail/bot_pose__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `facing_direction`
#include "rosidl_runtime_c/string_functions.h"

bool
auv_interfaces__msg__BotPose__init(auv_interfaces__msg__BotPose * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // facing_direction
  if (!rosidl_runtime_c__String__init(&msg->facing_direction)) {
    auv_interfaces__msg__BotPose__fini(msg);
    return false;
  }
  return true;
}

void
auv_interfaces__msg__BotPose__fini(auv_interfaces__msg__BotPose * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // facing_direction
  rosidl_runtime_c__String__fini(&msg->facing_direction);
}

bool
auv_interfaces__msg__BotPose__are_equal(const auv_interfaces__msg__BotPose * lhs, const auv_interfaces__msg__BotPose * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // facing_direction
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->facing_direction), &(rhs->facing_direction)))
  {
    return false;
  }
  return true;
}

bool
auv_interfaces__msg__BotPose__copy(
  const auv_interfaces__msg__BotPose * input,
  auv_interfaces__msg__BotPose * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // facing_direction
  if (!rosidl_runtime_c__String__copy(
      &(input->facing_direction), &(output->facing_direction)))
  {
    return false;
  }
  return true;
}

auv_interfaces__msg__BotPose *
auv_interfaces__msg__BotPose__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auv_interfaces__msg__BotPose * msg = (auv_interfaces__msg__BotPose *)allocator.allocate(sizeof(auv_interfaces__msg__BotPose), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(auv_interfaces__msg__BotPose));
  bool success = auv_interfaces__msg__BotPose__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
auv_interfaces__msg__BotPose__destroy(auv_interfaces__msg__BotPose * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    auv_interfaces__msg__BotPose__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
auv_interfaces__msg__BotPose__Sequence__init(auv_interfaces__msg__BotPose__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auv_interfaces__msg__BotPose * data = NULL;

  if (size) {
    data = (auv_interfaces__msg__BotPose *)allocator.zero_allocate(size, sizeof(auv_interfaces__msg__BotPose), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = auv_interfaces__msg__BotPose__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        auv_interfaces__msg__BotPose__fini(&data[i - 1]);
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
auv_interfaces__msg__BotPose__Sequence__fini(auv_interfaces__msg__BotPose__Sequence * array)
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
      auv_interfaces__msg__BotPose__fini(&array->data[i]);
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

auv_interfaces__msg__BotPose__Sequence *
auv_interfaces__msg__BotPose__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  auv_interfaces__msg__BotPose__Sequence * array = (auv_interfaces__msg__BotPose__Sequence *)allocator.allocate(sizeof(auv_interfaces__msg__BotPose__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = auv_interfaces__msg__BotPose__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
auv_interfaces__msg__BotPose__Sequence__destroy(auv_interfaces__msg__BotPose__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    auv_interfaces__msg__BotPose__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
auv_interfaces__msg__BotPose__Sequence__are_equal(const auv_interfaces__msg__BotPose__Sequence * lhs, const auv_interfaces__msg__BotPose__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!auv_interfaces__msg__BotPose__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
auv_interfaces__msg__BotPose__Sequence__copy(
  const auv_interfaces__msg__BotPose__Sequence * input,
  auv_interfaces__msg__BotPose__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(auv_interfaces__msg__BotPose);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    auv_interfaces__msg__BotPose * data =
      (auv_interfaces__msg__BotPose *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!auv_interfaces__msg__BotPose__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          auv_interfaces__msg__BotPose__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!auv_interfaces__msg__BotPose__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
