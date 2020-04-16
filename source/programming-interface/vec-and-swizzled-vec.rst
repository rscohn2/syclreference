.. _vec-and-swizzled-vec:

Vec and Swizzled Vec
====================


The DPC++ Vec and Swizzled Vec class templates are designed to represent
vectors between host and devices.


To instantiate a ``vec`` class template, provide the type and an integer
representing the number of elements. The number of elements can be 1, 2,
3, 4, 8, or 16; any other integer results in a compile error. The type
provided must be a basic scalar type, such as ``int`` or ``float``.


Member functions once an object is created include:


-  ``get_count`` – obtains the number of elements of the vec
-  ``get_size`` – obtain the size of the vec (in bytes)
-  ``lo`` – obtain the lower half of the vec
-  ``hi`` – obtain the higher half of the vec
-  ``odd`` – obtain the odd index elements of the vec
-  ``even`` – obtain the even index elements of the vec
-  ``load`` – copy the pointed to values into a vec
-  ``store`` – copy the vec into the pointed to location


The ``__swizzled_vec__`` class is employed to reposition elements of a
``vec`` object. A good motivation for employing is to obtain every odd
or even element of a vector. In this case, employ the odd or even member
function of the class. There are member functions associated with the
``__swizzled_vec__`` class for converting a ``vec`` into a new ``vec``,
such as one in RGBA format.


Various operators on the ``vec`` class include: +=, -=, \*=, /=, %=, ++,
--, &, \|, ^, +, -, \*, /, %, &&, \||, <<, >>, <<=, >>=, ==, !=, <, >,
<=, >=.

.. include:: vec-and-swizzled-vec.inc.rst
