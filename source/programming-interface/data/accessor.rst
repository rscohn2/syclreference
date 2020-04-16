.. _accessor:

Accessor
========


A DPC++ ``accessor`` encapsulates reading and writing memory objects
which can be buffers, images, or device local memory. Creating an
accessor requires a method to reference the desired access target.
Construction also requires the type of the memory object, the
dimensionality of the memory object, the access mode, and a placeholder
argument.

A common method of construction can employ the ``get_access`` method of
the memory object to specify the object and infer the other parameters
from that memory object.

See :ref:`accessors` for access modes and targets.

Placeholder accessors are those created independent of a command group
and then later associated with a particular memory object. Designation
of a placeholder accessor is communicated via the placeholder argument
set to ``access::placeholder::true_t`` if so and
``access::placeholder::false_t`` otherwise.

Once an accessor is created, query member functions to review accessor
information. These member functions include:

-  ``is_placeholder`` – return true if accessor is a placeholder, not
   yet associated with a memory object, false otherwise
-  ``get_size`` – obtain the size (in bytes) of the memory object
-  ``get_count`` – obtain the number of elements of the memory object
-  ``get_range`` – obtain the range of the memory object, where range is
   a range class
-  ``get_offset`` – obtain the offset of the memory object

An accessor can reference a subset of a memory object; this is the
offset of the accessor into the memory object.

Buffer Accessor
===============

.. include:: accessor.inc.rst


.. todo:: image accessor

.. todo:: local memory accessor

