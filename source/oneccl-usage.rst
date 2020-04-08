.. _oneccl-usage:

oneCCL Usage
============


Dependencies:


-  MPI
-  libfabrics
-  Intel oneAPI DPC++ Compiler


SYCL-aware API is an optional feature of oneCCL. The choice between CPU
and SYCL back ends is performed by specifying ``ccl_stream_type`` value
when creating the oneCCL stream object. For a GPU backend, specify
``ccl_stream_sycl`` as the first argument. For collective operations
that operate on SYCL stream, oneCCL expects communication buffers to be
``sycl::buffer`` objects casted to ``void*``.

