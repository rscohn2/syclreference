..
  // Copyright (c) 2011-2020 The Khronos Group, Inc.
  //
  // Licensed under the Apache License, Version 2.0 (the License);
  // you may not use this file except in compliance with the License.
  // You may obtain a copy of the License at
  //
  //     http://www.apache.org/licenses/LICENSE-2.0
  //
  // Unless required by applicable law or agreed to in writing, software
  // distributed under the License is distributed on an AS IS BASIS,
  // WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  // See the License for the specific language governing permissions and
  // limitations under the License.

======
device
======

.. synopsis::
   class device;

An abstract class representing various models of SYCL devices

.. member-functions::

=====================  =======================
`(constructor)`_
(destructor)    
get_          
is_host_      
is_cpu_      
is_gpu_      
is_accelerator_      
get_platform_  
get_info_     
has_extension_
create_sub_devices_
=====================  =======================

.. non-member-functions::

=================  =======================
get_devices_
=================  =======================

(constructor)
=============

.. synopsis::
  device();                                                [#default]_
.. synopsis::
  explicit device(cl_device_id deviceId);                  [#opencl]_
.. synopsis::
  explicit device(const device_selector &deviceSelector);  [#select]_

.. [#default] Default Constructor. Constructs a device object in host
              mode.
.. [#opencl] Constructs a device object from another device object and
             retains the cl_device_id object if the device is not in
             host mode.
.. [#select] Use deviceSelector to choose device
	     
.. params::

| ``deviceID`` - OpenCL device id
| ``deviceSelector`` - Device selector

get
===

.. synopsis::
  cl_device_id get() const;

Return the cl_device_id of the underlying OpenCL platform

.. returns::

cl_device_id of underlying OpenCL platform

is_host
=======

.. synopsis::
  bool is_host() const;

Checks if the device is a SYCL host device

.. returns::

|true| if the device is a :term:`host device`, |false| otherwise.

is_cpu
======

.. synopsis::
  bool is_cpu() const;

Checks if the device is a CPU

.. returns::

|true| if the device is a CPU, |false| otherwise

is_gpu
======

.. synopsis::
  bool is_gpu() const;

Checks if the device is a GPU

.. returns::

|true| if the device is a GPU, |false| otherwise

is_accelerator
==============

.. synopsis::
  bool is_accelerator() const;

Checks if the device is a GPU

.. returns::

|true| if the device is a GPU, |false| otherwise

get_platform
============

.. synopsis::
  platform get_platform() const;

Returns the platform that contains the device

.. returns::

Platform object

get_info
========

.. synopsis::
  template <info::device param>
  typename info::param_traits<info::device, param>::return_type
  get_info() const;

Queries the device for information specific to ``param``.

.. tparams::

``param`` - refer to info::device table 

.. returns::

Device information

.. example::

See :ref:`platform-example`.

has_extension
=============

.. synopsis::
  bool has_extension(const string_class &extension) const;

Check

.. params::

``extension`` - name of extension

.. returns::

create_sub_devices
==================

.. synopsis::
  template <info::partition_property prop>
  vector_class<device> create_sub_devices(size_t nbSubDev) const; [#1]_
.. synopsis::
  template <info::partition_property prop>
  vector_class<device> create_sub_devices(const vector_class<size_t> &counts) const; [#2]_
.. synopsis::
  template <info::partition_property prop>
  vector_class<device> create_sub_devices(info::affinity_domain affinityDomain) const; [#3]_

.. [#1] Available only when prop == info::partition_property::partition_equally
.. [#2] Available only when prop == info::partition_property::partition_by_counts
.. [#3]	Available only when prop == info::partition_property::partition_by_affinity_domain

.. params::

nbSubDev -
counts -
affinityDomain -

.. returns::

get_devices
===========

.. synopsis::
  static vector_class<device> get_devices(
      info::device_type deviceType = info::device_type::all);

.. returns::

