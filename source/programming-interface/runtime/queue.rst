.. _queue:

Queue
=====


A DPC++ ``queue`` is employed to schedule and execute the command queues
on the devices.


Multiple forms of constructors are available with different combinations
of arguments, including device selectors, devices, contexts, and command
queue. In addition, an ``asyc_handler`` can be passed to help
communicate errors from the devices back to the host.


The command queue itself executes in a synchronous fashion and therefore
errors are also synchronous in nature. The actual kernels execute
asynchronous and therefore errors are handled asynchronously by the
``async_handler``. Queues can synchronize by calling ``wait`` and
``wait_and_throw_throw`` member functions.


Command groups are submitted to the queue object using the submit member
function.


A ``property_list`` can also be passed during construction, which can be
used to communicate an ``enable_profiling`` property to the devices.


A description of a few other member functions include:


-  ``get`` – obtain a ``cl_command_queue``
-  ``get_context`` – obtain the context associated with the queue
-  ``get_device`` – obtain the device associated with the queue
-  ``is_host`` – return if the queue is executing on the host

.. include:: queue.inc.rst
