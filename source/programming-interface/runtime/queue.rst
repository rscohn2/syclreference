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

=====
queue
=====

.. synopsis::
   class queue;

.. member-functions::

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

(constructor)
=============

.. synopsis::
  explicit queue(const property_list &propList = {});
.. synopsis::
  explicit queue(const async_handler &asyncHandler,
                 const property_list &propList = {});
.. synopsis::
  explicit queue(const device_selector &deviceSelector,
                 const property_list &propList = {});
.. synopsis::
  explicit queue(const device_selector &deviceSelector,
                 const async_handler &asyncHandler,
		 const property_list &propList = {});
.. synopsis::
  explicit queue(const device &syclDevice, const property_list &propList = {});
.. synopsis::
  explicit queue(const device &syclDevice, const async_handler &asyncHandler,
                 const property_list &propList = {});
.. synopsis::
  explicit queue(const context &syclContext,
                 const device_selector &deviceSelector,
		 const property_list &propList = {});
.. synopsis::
  explicit queue(const context &syclContext,
                 const device_selector &deviceSelector,
                 const async_handler &asyncHandler,
		 const property_list &propList = {});
.. synopsis::
  explicit queue(const context &syclContext,
                 const device &syclDevice,
		 const property_list &propList = {});
.. synopsis::
  explicit queue(const context &syclContext, const device &syclDevice,
                 const async_handler &asyncHandler,
		 const property_list &propList = {});
.. synopsis::
  explicit queue(cl_command_queue clQueue, const context& syclContext,
                 const async_handler &asyncHandler = {});

get
===

.. synopsis::
  cl_command_queue get() const;

.. returns::

get_context
===========

.. synopsis::
  context get_context() const;

.. returns::

get_device
==========

.. synopsis::
  device get_device() const;

.. returns::

is_host
=======

.. synopsis::
  bool is_host() const;

.. returns::

get_info
========

.. synopsis::
  template <info::queue param>
  typename info::param_traits<info::queue, param>::return_type get_info() const;

.. returns::

submit
======

.. synopsis::
  template <typename T>
  event submit(T cgf);
.. synopsis::
  template <typename T>
  event submit(T cgf, const queue &secondaryQueue);

.. params::

| ``cgf`` -
| ``secondaryQueue`` -

.. returns::

wait
====

.. synopsis::
  void wait();

wait_and_throw
==============

.. synopsis::
  void wait_and_throw();

throw_asynchronous
==================

.. synopsis::
  void throw_asynchronous();
