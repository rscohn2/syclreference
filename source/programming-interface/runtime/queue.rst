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
 ``queue``
==============

.. parsed-literal::

   class queue;

.. rubric:: Member functions

=====================  =======================
`(constructor)`_   
(destructor)       
`get`_             
`get_context`_     
`get_device`_      
`get_info`_        
`is_host`_      
`submit`_       
`wait`_         
`wait_and_throw`_    
`throw_asynchronous`_
=====================  =======================

``(constructor)``
=================

.. parsed-literal::

  explicit queue(const property_list &propList = {});
  explicit queue(const async_handler &asyncHandler,
                 const property_list &propList = {});
  explicit queue(const device_selector &deviceSelector,
                 const property_list &propList = {});
  explicit queue(const device_selector &deviceSelector,
                 const async_handler &asyncHandler,
		 const property_list &propList = {});
  explicit queue(const device &syclDevice, const property_list &propList = {});
  explicit queue(const device &syclDevice, const async_handler &asyncHandler,
                 const property_list &propList = {});
  explicit queue(const context &syclContext,
                 const device_selector &deviceSelector,
		 const property_list &propList = {});
  explicit queue(const context &syclContext,
                 const device_selector &deviceSelector,
                 const async_handler &asyncHandler,
		 const property_list &propList = {});
  explicit queue(const context &syclContext,
                 const device &syclDevice,
		 const property_list &propList = {});
  explicit queue(const context &syclContext, const device &syclDevice,
                 const async_handler &asyncHandler,
		 const property_list &propList = {});
  explicit queue(cl_command_queue clQueue, const context& syclContext,
                 const async_handler &asyncHandler = {});

``get``
=======

.. parsed-literal::
   
  cl_command_queue get() const;

.. rubric:: Return value

``get_context``
===============

.. parsed-literal::
   
  context get_context() const;

.. rubric:: Return value

``get_device``
==============

.. parsed-literal::
   
  device get_device() const;

.. rubric:: Return value

``is_host``
===========

.. parsed-literal::
   
  bool is_host() const;

.. rubric:: Return value

``get_info``
============

.. parsed-literal::
   
  template <info::queue param>
  typename info::param_traits<info::queue, param>::return_type get_info() const;

.. rubric:: Return value

``submit``
==========

.. parsed-literal::
   
  template <typename T>
  event submit(T cgf);

  template <typename T>
  event submit(T cgf, const queue &secondaryQueue);

.. rubric:: Parameters

==================  ======================
``cgf``
``secondaryQueue``
==================  ======================

.. rubric:: Return value

``wait``
========

.. parsed-literal::
   
  void wait();

``wait_and_throw``
==================

.. parsed-literal::
   
  void wait_and_throw();

``throw_asynchronous``
======================

.. parsed-literal::
   
  void throw_asynchronous();
