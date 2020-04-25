============
``accessor``
============

.. parsed-literal::
   
   template<
       typename dataT,
       int dimensions,
       access::mode accessmode,
       access::target accessTarget = access::target::global_buffer,
       access::placeholder isPlaceholder = access::placeholder::false_t
   > accessor;


A DPC++ ``accessor`` encapsulates reading and writing memory objects
which can be buffers, images, or device local memory. Creating an
accessor requires a method to reference the desired access target.
Construction also requires the type of the memory object, the
dimensionality of the memory object, the access mode, and a placeholder
argument.

.. rubric:: Template parameters

=================  ===============
``dataT``          type of buffer element
``dimensions``     dimensionality of buffer
``accessmode``     type of access
``accessTarget``   type of memory
``isPlaceholder``  placeholder
=================  ===============

.. rubric:: Member types

===================  ===============
``value_type``       dataT
``reference``        dataT&
``const_reference``  const dataT&
===================  ===============

.. rubric:: Member functions

=================  ======================
(constructor)      constructs an accessor
(destructor)       destroys the accessor
is_placeholder
`get_size`_
`get_count`_
get_range
get_offset
=================  ======================

``get_size``
============

.. parsed-literal::

   size_t get_size() const

Description   

``get_count``
=============

.. parsed-literal::

   size_t get_size() const [#none]_
   size_t get_size(int b) const [#single]_
   size_t get_size(int c, int d) const [#double]_

Description

.. [#none] No arguments
.. [#single] single argument
.. [#double] 2 arguments


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

