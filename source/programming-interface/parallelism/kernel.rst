.. _kernel:

Kernel
======


The DPC++ ``kernel`` class encapsulates methods and data for executing
code on the device when a command group is instantiated. In many cases,
the runtime creates the kernel objects when a command queue is
instantiated.


Typically, a kernel object is not explicitly constructed by the user;
instead it is constructed when a kernel dispatch function, such as
``parallel_for``, is called. The sole case where a kernel object is
constructed is when constructing a kernel object from an OpenCL
application’s ``cl_kernel``. To compile the kernel ahead of time for use
by the command queue, use the
`program <program.html>`__ class.


Member functions of the class return related objects and attributes
regarding the kernel object including:


-  ``get`` – obtains a ``cl_kernel`` if associated
-  ``Is_host`` – obtains if the kernel is for the host
-  ``get_context`` – obtains the context to which the kernel is
   associated
-  ``get_program`` – obtains the program the kernel is contained in
-  ``get_info`` – obtain details on the kernel and return in
   ``info::kernel_info`` descriptor
-  ``get_work_group_info`` – obtain details on the work group and return
   in ``info::kernel_work_group`` descriptor


The ``get_info`` member function obtains kernel information such as
``function_name``, ``num_args``, ``context``, ``program``,
``reference_count``, and ``attributes``.

.. include:: kernel.inc.rst
