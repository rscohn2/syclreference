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
 ``platform``
==============

.. synopsis::

   class platform;

Handle for a SYCL platform available on the system.

.. member-functions::

=================  =======================
`(constructor)`_   constructs a platform
(destructor)       destroys a platform
`get`_             returns OpenCL platform ID
`get_devices`_     returns devices bound to the platform
`get_info`_        queries properties
`has_extension`_   checks if platform has an extension
`is_host`_         checks if platform has a SYCL host device
=================  =======================

.. non-member-functions::

=================  =======================
`get_platforms`_   returns platforms bound to the system
=================  =======================

.. _platform-example:

.. example::

Demonstrates several methods for ``platform``
   
.. literalinclude:: /examples/get-platforms.cpp

Output:

.. literalinclude:: /../build/examples/get-platforms.out

``(constructor)``
=================

.. synopsis::

  platform();
  explicit platform(cl_platform_id platformID); [#opencl]_
  explicit platform(const device_selector &deviceSelector); [#selector]_

Constructs a platform handle.

.. [#opencl] Constructs a SYCL platform that retains an OpenCL id
.. [#selector] Selects a platform that contains the desired device
	     

.. args::

==================  ======================
``platformID``      OpenCL platform ID
``deviceSelector``  Platform must contain the selected device
==================  ======================

``get``
=======

.. synopsis::
   
  cl_platform_id get() const;

Returns OpenCL platform id used in the constructor.

``get_devices``
===============

.. synopsis::
   
  vector_class<device> get_devices(
     info::device_type = info::device_type::all) const;

Returns vector of devices of the requested type

.. args::

=================  ======================
``device_type``    limits type of device returned
=================  ======================

.. returns::

``vector`` containing devices of the specified type bound to the
platform.

.. example::

See :ref:`platform-example`.


``get_info``
============

.. synopsis::
   
  template< info::platform param >
  typename info::param_traits<info::platform, param>::return_type get_info() const;

Returns information about the platform, as specified by ``param``.

.. returns::

Requested information

.. example::

See :ref:`platform-example`.


``has_extension``
=================

.. synopsis::

  bool has_extension(const string_class &extension) const;

Checks if the platform has the requested extension.
  

.. args::

=================  ======================
``extension``
=================  ======================

.. returns::

|true| if the platform has ``extension``

``is_host``
===========

.. synopsis::

  bool is_host() const;

Checks if the platform contains a SYCL :term:`host device`

.. returns::

|true| if the platform contains a host device


``get_platforms``
=================

.. synopsis::

  static vector_class<platform> get_platforms();

Returns vector of platforms

.. returns::

vector_class containing SYCL platforms bound to the system

.. example::

See :ref:`platform-example`.
