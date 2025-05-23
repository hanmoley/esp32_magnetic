// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from multi_sensor_interfaces:srv/Multisensor.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "multi_sensor_interfaces/srv/detail/multisensor__struct.h"
#include "multi_sensor_interfaces/srv/detail/multisensor__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool multi_sensor_interfaces__srv__multisensor__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[61];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("multi_sensor_interfaces.srv._multisensor.Multisensor_Request", full_classname_dest, 60) == 0);
  }
  multi_sensor_interfaces__srv__Multisensor_Request * ros_message = _ros_message;
  {  // mid_finger
    PyObject * field = PyObject_GetAttrString(_pymsg, "mid_finger");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->mid_finger = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // index_finger
    PyObject * field = PyObject_GetAttrString(_pymsg, "index_finger");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->index_finger = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // ring_finger
    PyObject * field = PyObject_GetAttrString(_pymsg, "ring_finger");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->ring_finger = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // location
    PyObject * field = PyObject_GetAttrString(_pymsg, "location");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->location, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * multi_sensor_interfaces__srv__multisensor__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Multisensor_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("multi_sensor_interfaces.srv._multisensor");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Multisensor_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  multi_sensor_interfaces__srv__Multisensor_Request * ros_message = (multi_sensor_interfaces__srv__Multisensor_Request *)raw_ros_message;
  {  // mid_finger
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->mid_finger);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mid_finger", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // index_finger
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->index_finger);
    {
      int rc = PyObject_SetAttrString(_pymessage, "index_finger", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ring_finger
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->ring_finger);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ring_finger", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // location
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->location.data,
      strlen(ros_message->location.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "location", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "multi_sensor_interfaces/srv/detail/multisensor__struct.h"
// already included above
// #include "multi_sensor_interfaces/srv/detail/multisensor__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool multi_sensor_interfaces__srv__multisensor__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[62];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("multi_sensor_interfaces.srv._multisensor.Multisensor_Response", full_classname_dest, 61) == 0);
  }
  multi_sensor_interfaces__srv__Multisensor_Response * ros_message = _ros_message;
  {  // result
    PyObject * field = PyObject_GetAttrString(_pymsg, "result");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->result = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * multi_sensor_interfaces__srv__multisensor__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Multisensor_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("multi_sensor_interfaces.srv._multisensor");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Multisensor_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  multi_sensor_interfaces__srv__Multisensor_Response * ros_message = (multi_sensor_interfaces__srv__Multisensor_Response *)raw_ros_message;
  {  // result
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->result);
    {
      int rc = PyObject_SetAttrString(_pymessage, "result", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
