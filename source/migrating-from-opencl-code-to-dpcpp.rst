.. _migrating-from-opencl-code-to-dpcpp:

Migrating from OpenCL Code to DPC++
===================================


In the current version of DPC++, the runtime employs OpenCL code to
enact the parallelism. DPC++ typically requires fewer lines of code to
implement kernels and also fewer calls to essential API functions and
methods. It enables creation of OpenCL programs by embedding the device
source code in line with the host source code.


Most of the OpenCL application developers are aware of the somewhat
verbose setup code that goes with offloading kernels on devices. Using
DPC++, it is possible to develop a clean, modern C++ based application
without most of the setup associated with OpenCL C code. This reduces
the learning effort and allows for focus on parallelization techniques.


However, OpenCL application features can continue to be used via the
SYCL API. The updated code can use as much or as little of the SYCL
interface as desired.

