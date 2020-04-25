.. _command-group-handler:

Command Group Handler
=====================


The command group handler class encapsulates the actions of the command
group, namely the marshaling of data and launching of the kernels on the
devices.


There are no user callable constructors; construction is accomplished by
the oneAPI runtime. Consider the example code below:


::


   d_queue.submit([&](sycl::handler &cgh) {
            auto c_res = c_device.get_access<sycl::access::mode::write>(cgh); 
            cgh.parallel_for<class ex1>(a_size,[=](sycl::id<1> idx) {
              c_res[idx] =0;
            }); 
          });


In the example, the accessor, ``c_res``, is obtained from the device and
takes a command group handler as a parameter, in this case ``cgh``. The
kernel dispatch itself is a member function of the command group
handler. In this case, a ``parallel_for`` is called. The kernel dispatch
API has multiple calls including ``parallel_for``,
``parallel_for_work_group``, and ``single_task``.


There is a ``set_args`` function employed for passing arguments to an
OpenCL™ kernel for interoperability.

.. include:: command-group-handler.inc.rst
