.. _nd_item:

Nd_item
=======


A DPC++ ``nd_item`` encapsulates a function object executing on an
individual data point in a DPC++ ``nd_range``. When a kernel is
executed, it is associated with an individual item in a range and acts
upon it. This association is accomplished implicitly, by the runtime.
Therefore, there are no user callable constructors; a DPC++ ``nd_item``
is created when a kernel is instantiated.


The member functions of the ``nd_item`` class pertain to determining the
relationship between the ``nd_item`` and the enclosing range:


-  ``get_global_id`` – obtain the position of the work item in the
   iteration space
-  ``get_global_linear_id`` – obtain the position of the work item in a
   linear representation of the global iteration space
-  ``get_local_id`` – obtain the position of the item in the current
   work-group
-  ``get_local_linear_id`` – obtain the position of the item in a linear
   representation of the current work-group
-  ``get_group`` – obtain the position of the item in the overall
   ``nd_range``
-  ``get_group_range`` – obtain the number of work-groups in the
   iteration space
-  ``get_global_range`` – obtain the range representing the dimensions
   of the global iteration space
-  ``get_local_range`` – obtain the range representing the dimension of
   the current work-group
-  ``get_offset`` – obtain an id that represents the offset between a
   work-item representation between local and global iteration space
-  ``get_nd_range`` – obtain the ``nd_range`` from the ``nd_item``


The class also includes a member function, ``async_work_group_copy``,
which can copy a range of items asynchronously.

.. include:: nd-item.inc.rst
