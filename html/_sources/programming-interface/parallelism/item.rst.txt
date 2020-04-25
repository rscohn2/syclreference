.. _item:

Item
====


A DPC++ ``item`` encapsulates a function object executing on an
individual data point in a DPC++ range. When a kernel is executed, it is
associated with an individual item in a range and acts upon it. This
association is accomplished implicitly, by the runtime. Therefore, there
are no user callable constructors; a DPC++ item is created when a kernel
is instantiated.


The member functions of the item class pertain to determining the
relationship between the item and the enclosing range:


-  ``get_id`` – obtain the position of the work item in the iteration
   space
-  ``get_range`` – obtain the range associated with the item
-  ``get_offset`` – obtain the position of the item in the n-dimensional
   space
-  ``get_linear_id`` – obtain the position of the item converting the
   n-dimensional space into one

.. include:: item.inc.rst
