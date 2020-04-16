.. _id:

ID
==


The ``id`` class encapsulates a vector of dimensions that identify an
index into a global or local range. Constructors for the class take one
to three integer arguments representing a one, two, and three dimension
ID. Each integer argument specifies the size of the dimension. ID
objects can also be constructed as a placeholder where the dimension is
unspecified and set to zero by default. Construction can also be based
upon the dimension of an existing range or item.


The class supports operations such as + (plus), - (minus), and many
more. Consult the SYCL Specification for complete details.

.. include:: id.inc.rst
