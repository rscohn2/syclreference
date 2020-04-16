.. _multi-pointer:

Address Spaces
==============


The DPC++ ``multi-pointer`` class encapsulates lower level pointers that
point to abstract device memory.


Constructors for the ``multi-pointer`` class enable explicit mention of
the address space of the memory. The following lists the address space
with the appropriate identifier:


-  Global memory – ``global_space``
-  Local memory – ``local_space``
-  Constant memory – ``constant_space``
-  Private memory – ``private_space``


The constructors can also be called in an unqualified fashion for cases
where the location will be known later.


Member functions include standard pointer operations such as ++
(increment), -- (decrement), + (plus), and – (minus). A prefetch
function is also specified to aid in optimization and is implementation
defined.


Conversion operations are also available to convert between the raw
underlying pointer and an OpenCL program’s C pointer for
interoperability. Consult the SYCL Specification for complete details.

.. include:: multi-pointer.inc.rst
.. include:: pointer.inc.rst
	     
