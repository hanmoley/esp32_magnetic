// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from multi_sensor_interfaces:srv/Multisensor.idl
// generated code does not contain a copyright notice
#include "multi_sensor_interfaces/srv/detail/multisensor__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `location`
#include "rosidl_runtime_c/string_functions.h"

bool
multi_sensor_interfaces__srv__Multisensor_Request__init(multi_sensor_interfaces__srv__Multisensor_Request * msg)
{
  if (!msg) {
    return false;
  }
  // mid_finger
  // index_finger
  // ring_finger
  // location
  if (!rosidl_runtime_c__String__init(&msg->location)) {
    multi_sensor_interfaces__srv__Multisensor_Request__fini(msg);
    return false;
  }
  return true;
}

void
multi_sensor_interfaces__srv__Multisensor_Request__fini(multi_sensor_interfaces__srv__Multisensor_Request * msg)
{
  if (!msg) {
    return;
  }
  // mid_finger
  // index_finger
  // ring_finger
  // location
  rosidl_runtime_c__String__fini(&msg->location);
}

bool
multi_sensor_interfaces__srv__Multisensor_Request__are_equal(const multi_sensor_interfaces__srv__Multisensor_Request * lhs, const multi_sensor_interfaces__srv__Multisensor_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // mid_finger
  if (lhs->mid_finger != rhs->mid_finger) {
    return false;
  }
  // index_finger
  if (lhs->index_finger != rhs->index_finger) {
    return false;
  }
  // ring_finger
  if (lhs->ring_finger != rhs->ring_finger) {
    return false;
  }
  // location
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->location), &(rhs->location)))
  {
    return false;
  }
  return true;
}

bool
multi_sensor_interfaces__srv__Multisensor_Request__copy(
  const multi_sensor_interfaces__srv__Multisensor_Request * input,
  multi_sensor_interfaces__srv__Multisensor_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // mid_finger
  output->mid_finger = input->mid_finger;
  // index_finger
  output->index_finger = input->index_finger;
  // ring_finger
  output->ring_finger = input->ring_finger;
  // location
  if (!rosidl_runtime_c__String__copy(
      &(input->location), &(output->location)))
  {
    return false;
  }
  return true;
}

multi_sensor_interfaces__srv__Multisensor_Request *
multi_sensor_interfaces__srv__Multisensor_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_sensor_interfaces__srv__Multisensor_Request * msg = (multi_sensor_interfaces__srv__Multisensor_Request *)allocator.allocate(sizeof(multi_sensor_interfaces__srv__Multisensor_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(multi_sensor_interfaces__srv__Multisensor_Request));
  bool success = multi_sensor_interfaces__srv__Multisensor_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
multi_sensor_interfaces__srv__Multisensor_Request__destroy(multi_sensor_interfaces__srv__Multisensor_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    multi_sensor_interfaces__srv__Multisensor_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
multi_sensor_interfaces__srv__Multisensor_Request__Sequence__init(multi_sensor_interfaces__srv__Multisensor_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_sensor_interfaces__srv__Multisensor_Request * data = NULL;

  if (size) {
    data = (multi_sensor_interfaces__srv__Multisensor_Request *)allocator.zero_allocate(size, sizeof(multi_sensor_interfaces__srv__Multisensor_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = multi_sensor_interfaces__srv__Multisensor_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        multi_sensor_interfaces__srv__Multisensor_Request__fini(&data[i - 1]);
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
multi_sensor_interfaces__srv__Multisensor_Request__Sequence__fini(multi_sensor_interfaces__srv__Multisensor_Request__Sequence * array)
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
      multi_sensor_interfaces__srv__Multisensor_Request__fini(&array->data[i]);
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

multi_sensor_interfaces__srv__Multisensor_Request__Sequence *
multi_sensor_interfaces__srv__Multisensor_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_sensor_interfaces__srv__Multisensor_Request__Sequence * array = (multi_sensor_interfaces__srv__Multisensor_Request__Sequence *)allocator.allocate(sizeof(multi_sensor_interfaces__srv__Multisensor_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = multi_sensor_interfaces__srv__Multisensor_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
multi_sensor_interfaces__srv__Multisensor_Request__Sequence__destroy(multi_sensor_interfaces__srv__Multisensor_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    multi_sensor_interfaces__srv__Multisensor_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
multi_sensor_interfaces__srv__Multisensor_Request__Sequence__are_equal(const multi_sensor_interfaces__srv__Multisensor_Request__Sequence * lhs, const multi_sensor_interfaces__srv__Multisensor_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!multi_sensor_interfaces__srv__Multisensor_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
multi_sensor_interfaces__srv__Multisensor_Request__Sequence__copy(
  const multi_sensor_interfaces__srv__Multisensor_Request__Sequence * input,
  multi_sensor_interfaces__srv__Multisensor_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(multi_sensor_interfaces__srv__Multisensor_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    multi_sensor_interfaces__srv__Multisensor_Request * data =
      (multi_sensor_interfaces__srv__Multisensor_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!multi_sensor_interfaces__srv__Multisensor_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          multi_sensor_interfaces__srv__Multisensor_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!multi_sensor_interfaces__srv__Multisensor_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
multi_sensor_interfaces__srv__Multisensor_Response__init(multi_sensor_interfaces__srv__Multisensor_Response * msg)
{
  if (!msg) {
    return false;
  }
  // result
  return true;
}

void
multi_sensor_interfaces__srv__Multisensor_Response__fini(multi_sensor_interfaces__srv__Multisensor_Response * msg)
{
  if (!msg) {
    return;
  }
  // result
}

bool
multi_sensor_interfaces__srv__Multisensor_Response__are_equal(const multi_sensor_interfaces__srv__Multisensor_Response * lhs, const multi_sensor_interfaces__srv__Multisensor_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // result
  if (lhs->result != rhs->result) {
    return false;
  }
  return true;
}

bool
multi_sensor_interfaces__srv__Multisensor_Response__copy(
  const multi_sensor_interfaces__srv__Multisensor_Response * input,
  multi_sensor_interfaces__srv__Multisensor_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // result
  output->result = input->result;
  return true;
}

multi_sensor_interfaces__srv__Multisensor_Response *
multi_sensor_interfaces__srv__Multisensor_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_sensor_interfaces__srv__Multisensor_Response * msg = (multi_sensor_interfaces__srv__Multisensor_Response *)allocator.allocate(sizeof(multi_sensor_interfaces__srv__Multisensor_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(multi_sensor_interfaces__srv__Multisensor_Response));
  bool success = multi_sensor_interfaces__srv__Multisensor_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
multi_sensor_interfaces__srv__Multisensor_Response__destroy(multi_sensor_interfaces__srv__Multisensor_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    multi_sensor_interfaces__srv__Multisensor_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
multi_sensor_interfaces__srv__Multisensor_Response__Sequence__init(multi_sensor_interfaces__srv__Multisensor_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_sensor_interfaces__srv__Multisensor_Response * data = NULL;

  if (size) {
    data = (multi_sensor_interfaces__srv__Multisensor_Response *)allocator.zero_allocate(size, sizeof(multi_sensor_interfaces__srv__Multisensor_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = multi_sensor_interfaces__srv__Multisensor_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        multi_sensor_interfaces__srv__Multisensor_Response__fini(&data[i - 1]);
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
multi_sensor_interfaces__srv__Multisensor_Response__Sequence__fini(multi_sensor_interfaces__srv__Multisensor_Response__Sequence * array)
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
      multi_sensor_interfaces__srv__Multisensor_Response__fini(&array->data[i]);
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

multi_sensor_interfaces__srv__Multisensor_Response__Sequence *
multi_sensor_interfaces__srv__Multisensor_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  multi_sensor_interfaces__srv__Multisensor_Response__Sequence * array = (multi_sensor_interfaces__srv__Multisensor_Response__Sequence *)allocator.allocate(sizeof(multi_sensor_interfaces__srv__Multisensor_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = multi_sensor_interfaces__srv__Multisensor_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
multi_sensor_interfaces__srv__Multisensor_Response__Sequence__destroy(multi_sensor_interfaces__srv__Multisensor_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    multi_sensor_interfaces__srv__Multisensor_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
multi_sensor_interfaces__srv__Multisensor_Response__Sequence__are_equal(const multi_sensor_interfaces__srv__Multisensor_Response__Sequence * lhs, const multi_sensor_interfaces__srv__Multisensor_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!multi_sensor_interfaces__srv__Multisensor_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
multi_sensor_interfaces__srv__Multisensor_Response__Sequence__copy(
  const multi_sensor_interfaces__srv__Multisensor_Response__Sequence * input,
  multi_sensor_interfaces__srv__Multisensor_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(multi_sensor_interfaces__srv__Multisensor_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    multi_sensor_interfaces__srv__Multisensor_Response * data =
      (multi_sensor_interfaces__srv__Multisensor_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!multi_sensor_interfaces__srv__Multisensor_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          multi_sensor_interfaces__srv__Multisensor_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!multi_sensor_interfaces__srv__Multisensor_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
