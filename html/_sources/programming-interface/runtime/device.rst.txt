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

==============
 ``device``
==============

.. synopsis::

   class device;

.. member-functions::

=====================  =======================
`(constructor)`_
(destructor)    
`get`_          
`is_host`_      
`is_cpu`_      
`is_gpu`_      
`is_accelerator`_      
`get_platform`_  
`get_info`_     
`has_extension`_
`create_sub_devices`_
=====================  =======================

.. non-member-functions::

=================  =======================
`get_devices`_
=================  =======================

``(constructor)``
=================

.. synopsis::

  device();
  explicit device(cl_device_id deviceId);
  explicit device(const device_selector &deviceSelector);

.. args::

==================  ======================
``deviceID``
``deviceSelector``
==================  ======================

``get``
=======

.. synopsis::
   
  cl_device_id get() const;

.. returns::

``is_host``
===========

.. synopsis::
   
  bool is_host() const;

.. returns::

``is_cpu``
==========

.. synopsis::
   
  bool is_cpu() const;

.. returns::

``is_gpu``
==========

.. synopsis::
   
  bool is_gpu() const;

.. returns::

``is_accelerator``
==================

.. synopsis::
   
  bool is_accelerator() const;

.. returns::

``get_platform``
================

.. synopsis::
   
  platform get_platform() const;

.. returns::

``get_info``
============

.. synopsis::
   
  template <info::device param>
  typename info::param_traits<info::device, param>::return_type
  get_info() const;

.. returns::

.. example::

See :ref:`platform-example`.

``has_extension``
=================

.. synopsis::
   
  bool has_extension(const string_class &extension) const;

.. args::

==================  ======================
``extension``
==================  ======================

.. returns::

``create_sub_devices``
======================

.. synopsis::
   
  template <info::partition_property prop>
  vector_class<device> create_sub_devices(size_t nbSubDev) const; [#1]_

  template <info::partition_property prop>
  vector_class<device> create_sub_devices(const vector_class<size_t> &counts) const; [#2]_

  template <info::partition_property prop>
  vector_class<device> create_sub_devices(info::affinity_domain affinityDomain) const; [#3]_

.. [#1] Available only when prop == info::partition_property::partition_equally
.. [#2] Available only when prop == info::partition_property::partition_by_counts
.. [#3]	Available only when prop == info::partition_property::partition_by_affinity_domain

.. args::

==================  ======================
nbSubDev
counts
affinityDomain
==================  ======================

.. returns::

``get_devices``
===============

.. synopsis::
   
  static vector_class<device> get_devices(
      info::device_type deviceType = info::device_type::all);

.. returns::

