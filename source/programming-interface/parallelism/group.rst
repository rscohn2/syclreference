.. _group:

Group
=====


The ``group`` class encapsulates work-group functionality. Constructors
are not user-callable; objects are created as a by-product of a call to
``parallel_for_work_group.``


Once a group object has been instantiated, query various properties of
the object by calling several member functions including:


-  ``get_id`` – obtains the index of the work-group
-  ``get_global_range`` – obtain a range that represents the work-items
   across the index space
-  ``get_local_range`` – obtain a range that represents the work-items
   in a work-group
-  ``get_group_range`` – obtain a range representing the dimensions of
   the current work-group
-  ``get_linear_id`` – obtain a linear version of the work-group id


Definitions of global range and local range are in the SYCL
Specification glossary. In brief, a global range is the overall number
of work-items in the index space. A local range is the number of
work-items in a work-group.

.. include:: group.inc.rst
