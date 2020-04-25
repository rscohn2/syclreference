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
 ``event``
==============

.. synopsis::

   class event;

.. member-functions::

=====================  =======================
`(constructor)`_
(destructor)    
`cl_event_get`_ 
`is_host`_     
`get_wait_list`_
`wait`_   
`wait_and_throw`_ 
`get_info`_       
`get_profiling_info`_
=====================  =======================

``(constructor)``
=================

.. synopsis::

  event();
  event(cl_event clEvent, const context& syclContext);

``cl_event_get``
================

.. synopsis::
   
  cl_event get();

.. returns::

``is_host``
===========

.. synopsis::
   
  bool is_host() const;

.. returns::

``get_wait_list``
=================

.. synopsis::
   
  vector_class<event> get_wait_list();

.. returns::

``wait``
========

.. synopsis::
   
  void wait();

  static void wait(const vector_class<event> &eventList);

``wait_and_throw``
==================

.. synopsis::
   
  void wait_and_throw();

  static void wait_and_throw(const vector_class<event> &eventList);

``get_info``
============

.. synopsis::
   
  template <info::event param>
  typename info::param_traits<info::event, param>::return_type get_info() const;

.. returns::

``get_profiling_info``
======================

.. synopsis::
   
  template <info::event_profiling param>
  typename info::param_traits<info::event_profiling, param>::return_type get_profiling_info() const;

.. returns::

