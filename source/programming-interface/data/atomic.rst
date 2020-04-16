.. _atomic:

Atomic
======


The DPC++ ``atomic`` class encapsulates operations and member
functions to guarantee synchronized access to data
values. Construction of an atomic object requires a reference to a
:ref:`multi-pointer`. A ``multi_ptr`` is an abstraction on top of a
low-level pointer that enables efficient access across the host and
devices.


The atomic member functions are modeled after the C++ standard atomic
functions. They are documented more fully in the SYCL Specification and
include the following:


-  ``Store`` – store a value
-  ``Load`` – load a value
-  ``Exchange`` – swap two values
-  ``Compare_exchange_strong`` - compares two values for equality and
   exchanges based on result
-  ``Fetch_add`` – add a value to the value pointed to by a
   ``multi_ptr``
-  ``Fetch_sub`` - subtract a value from the value pointed to by a
   ``multi_ptr``
-  ``Fetch_and`` – bitwise and a value from the value pointed to by a
   ``multi_ptr``
-  ``Fetch_or`` - bitwise or a value from the value pointed to by a
   ``multi_ptr``
-  ``Fetch_xor`` - bitwise xor a value from the value pointed to by a
   ``multi_ptr``
-  ``Fetch_min`` – compute the minimum between a value and the value
   pointed to by a ``multi_ptr``
-  ``Fetch_max`` - compute the maximum between a value and the value
   pointed to by a ``multi_ptr``


In addition to the member functions above, a set of functions with the
same capabilities are available acting on atomic types. These functions
are similarly named with the addition of "``atomic_``" prepended.

.. include:: atomic.inc.rst
