.. _data-parallel-cpp-dpcpp:

Data Parallel C++ (DPC++)
=========================


Data Parallel C++ (DPC++) is a high-level language designed for data
parallel programming productivity. It is based on C++ for broad
compatibility and uses common, familiar C and C++ constructs. The
language seeks to deliver performance on par with other compiled
languages, such as standard C++ compiled code, and uses C++ class
libraries to allow the compiler to interpret the code and run on various
supported architectures.


DPC++ is based on SYCL\* from the Khronos\* Group to support data
parallelism and heterogeneous programming. In addition, Intel is
pursuing extensions to SYCL with the aim of providing value to customer
code and working with the standards organization for adoption. For
instance, the DPC++ language includes an implementation of unified
shared memory to ease memory usage between the host and the
accelerators. These features are being driven into a future version of
the SYCL language. For more details about SYCL, refer to version 1.2.1
of the `SYCL
Specification <https://www.khronos.org/registry/SYCL/specs/sycl-1.2.1.pdf>`__.


While DPC++ applications can run on any supported target hardware,
tuning is required to gain the best performance advantage on a given
target architecture. For example, code tuned for a CPU likely will not
run as fast on a GPU accelerator without modification. This guide aims
to help developers understand how to program using the oneAPI
programming model and how to target and optimize for the appropriate
architecture to achieve optimal application performance.

