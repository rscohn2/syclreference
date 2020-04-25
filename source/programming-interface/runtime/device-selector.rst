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

=====================
 ``device_selector``
=====================

.. synopsis::
   
  class device_selector();

.. member-functions::
   
=================  =======================
`(constructor)`_
`(destructor)`_
`select_device`_   
=================  =======================

.. non-member-functions::

=================  =======================
operator()
=================  =======================


``(constructor)``
=================

.. synopsis::
   
  device_selector(const device_selector &rhs);
  device_selector &operator=(const device_selector &rhs);

``(destructor)``
================

.. synopsis::
   
  virtual ~device_selector();

``select_device``
===================

.. synopsis::
   
  device select_device() const;

.. returns::
   
``operator()``
==============

.. synopsis::
   
  virtual int operator()(const device &device) const = 0;

.. returns::
