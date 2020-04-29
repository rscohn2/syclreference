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

=================
default_selector
=================

.. synopsis::
   class default_selector;

Selects a SYCL device based on a implementation-defined
heuristic. Selects a :term:`host device` if no other device can be
found.
   
============
gpu_selector
============

.. synopsis::
   class gpu_selector;

Selects a GPU.   

.. exceptions::

Throws a ``runtime_error`` if a GPU device cannot be found

.. _gpu-selector-example:

.. example::

.. literalinclude:: /examples/gpu-selector.cpp

Output on a system without a GPU

.. literalinclude:: /../build/examples/gpu-selector.out
		    
====================
accelerator_selector
====================

.. synopsis::
   class accelerator_selector;

Selects an accelerator.

.. exceptions::

Throws a ``runtime_error`` if an accelerator device cannot be found.

.. example::

See :ref:`gpu-selector-example` for the use of a pre-defined selector.

============
cpu_selector
============

.. synopsis::
   class cpu_selector;

Select a CPU device.

.. exceptions::

Throws a ``runtime_error`` if a CPU device cannot be found.

.. example::

See :ref:`gpu-selector-example` for the use of a pre-defined selector.

=============
host_selector
=============

.. synopsis::
   class host_selector;

.. example::

See :ref:`gpu-selector-example` for the use of a pre-defined selector.

===============
device_selector
===============

.. synopsis::
  class device_selector();

``device_selector`` is an abstract class that cann

.. member-functions::
   
====================  =======================
`(constructor)`_      constructs a device_selector
(destructor)          destroys the device_selector
select_device_     
====================  =======================

.. non-member-functions::

=================  =======================
operator()
=================  =======================


(constructor)
=============

.. synopsis::
  device_selector(const device_selector &rhs);
.. synopsis::
  device_selector &operator=(const device_selector &rhs);

Constructs a ``device_selector`` from another ``device_selector``

.. params::

| ``rhs`` - device 

select_device
=============

.. synopsis::
  device select_device() const;

.. returns::
   
operator()
==========

.. synopsis::
  virtual int operator()(const device &device) const = 0;

.. returns::
