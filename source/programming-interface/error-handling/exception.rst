.. _exception:

Exception
=========


The DPC++ ``exception`` class encapsulates objects to communicate error
conditions from the DPC++ program. Errors during DPC++ program execution
are either scheduling or device related.


Execution between host and device is asynchronous in nature, therefore
any events or errors are asynchronous. To catch exceptions that occur on
the device, employ an ``asynch_handler``, which is provided during
command queue construction. During execution of the kernel, if any
exceptions occur, these are placed on the ``async_handler`` list for
processing once the command group function returns and the host handles
the exceptions through the ``async_handler`` list. The
``exception_ptr_class`` is used to store the exception and can contain
exceptions representing different types of errors such as
``device_error_ compile_program_error``, ``link_program_error``,
``invalid_object_error``, ``memory_allocation_error``,
``platform_error``, ``profiling_error``, and ``feature_not_supported``.

.. include:: exception.inc.rst
