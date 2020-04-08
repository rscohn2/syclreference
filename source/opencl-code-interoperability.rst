.. _opencl-code-interoperability:

OpenCL™ Code Interoperability
=============================


The oneAPI programming model enables developers to continue using all
OpenCL code features via different parts of the SYCL API. The OpenCL
code interoperability mode provided by SYCL helps reuse the existing
OpenCL code while keeping the advantages of higher programming model
interfaces provided by SYCL. There are 2 main parts in the
interoperability mode:


#. To create SYCL objects from OpenCL code objects. For example, a SYCL
   buffer can be constructed from an OpenCL ``cl_mem`` or SYCL queue
   from a ``cl_command_queue``.
#. To get OpenCL code objects from SYCL objects. For example, launching
   an OpenCL kernel that uses an implicit ``cl_mem`` associated to a
   SYCL accessor.

