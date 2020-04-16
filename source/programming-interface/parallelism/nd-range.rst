.. _nd_range:

Nd_range
========


The DPC++ ``nd_range`` class encapsulates the iteration domain of the
work-groups and kernel dispatch. It is the entire iteration space of
data that a kernel may operation upon. The constructor for an
``nd_range`` object take the global range, local range, and an optional
offset.


Member functions include:


-  ``get_global_range`` – obtain the global range
-  ``get_local_range`` – obtain the local range
-  ``get_group_range`` – obtain the number of groups in each dimension
   of the ``nd_range``
-  ``get_offset`` – obtain the offset

.. include:: nd-range.inc.rst
