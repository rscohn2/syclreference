========
accessor
========

.. synopsis::
   template<
       typename dataT,
       int dimensions,
       access::mode accessmode,
       access::target accessTarget = access::target::global_buffer,
       access::placeholder isPlaceholder = access::placeholder::false_t
   > class accessor;


A DPC++ ``accessor`` encapsulates reading and writing memory objects
which can be buffers, images, or device local memory. Creating an
accessor requires a method to reference the desired access target.
Construction also requires the type of the memory object, the
dimensionality of the memory object, the access mode, and a placeholder
argument.

.. tparams::

| ``dataT`` - type of buffer element
| ``dimensions``- dimensionality of buffer
| ``accessmode`` - type of access
| ``accessTarget`` - type of memory
| ``isPlaceholder`` - placeholder


.. member-types::

===================  ===============
``value_type``       dataT
``reference``        dataT&
``const_reference``  const dataT&
===================  ===============

.. member-functions::

=================  ======================
(constructor)      constructs an accessor
(destructor)       destroys the accessor
is_placeholder
`get_size`_
`get_count`_
get_range
get_offset
=================  ======================

get_size
============

.. synopsis::
   size_t get_size() const

Description   

get_count
=============

