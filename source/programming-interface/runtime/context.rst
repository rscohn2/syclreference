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

===========
``context``
===========

.. parsed-literal::
   
  class context;
  
.. rubric:: Member functions

=================  =======================
`(constructor)`_   constructs a context
`get`_             returns OpenCL conext ID
`is_host`_         checks if contains a SYCL host device
`get_platform`_
`get_devices`_     returns devices bound to the context
`get_info`_        queries properties
=================  =======================


``(constructor)``
=================

.. parsed-literal::
   
  explicit context(const property_list &propList = {});
  context(async_handler asyncHandler,
          const property_list &propList = {});
  context(const device &dev, const property_list &propList = {});
  context(const device &dev, async_handler asyncHandler,
          const property_list &propList = {});
  context(const platform &plt, const property_list &propList = {});
  context(const platform &plt, async_handler asyncHandler,
          const property_list &propList = {});
  context(const vector_class<device> &deviceList,
          const property_list &propList = {});
  context(const vector_class<device> &deviceList,
          async_handler asyncHandler, const property_list &propList = {});
  context(cl_context clContext, async_handler asyncHandler = {});

.. rubric:: Parameters

==================  ======================
``propList``
``asyncHandler``
``dev``
``plt``
``deviceList``
==================  ======================

``get``
=======

.. parsed-literal::
   
  cl_context get() const;

.. rubric:: Return value
	    
``is_host``
===========

.. parsed-literal::

  bool is_host() const;

.. rubric:: Return value
	    
``get_platform``
================

.. parsed-literal::

  platform get_platform() const;

.. rubric:: Return value
	    
``get_devices``
===============

.. parsed-literal::

  vector_class<device> get_devices() const;

.. rubric:: Return value
	    
``get_info``
============

.. parsed-literal::

  template <info::context param>
  typename info::param_traits<info::context, param>::return_type get_info() const;


.. rubric:: Return value
	    
