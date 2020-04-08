.. _execute-step:

Execute Step
============


During the execute step, the fat binary is obtained and loaded onto the
system for execution. The fat binary is an operating system module (an
executable or a dynamically loaded library) containing one or more
device code binaries.


When a DPC++ application starts, its operating system modules are loaded
into the process memory, and static initialization is performed for
each. During this static initialization process, each module makes a
call into the DPC++ runtime to register available device binary images.
The DPC++ runtime bookmarks the registered binaries and uses them to
resolve kernel launch requests to the appropriate device kernels.


To target new devices, the oneAPI programming model supports `online
compilation <online-compilation.html>`__. If a
device code binary is not available during a kernel launch request, an
online compilation may be requested.


DPC++ applications may also dynamically compile and run OpenCL kernels
provided in the source form. The main APIs for this feature are:


-  ``cl::sycl::program::build_with_source`` to dynamically create a
   kernel from a string containing OpenCL code.


-  ``cl::sycl::program::get_kernel`` to obtain the DPC++ kernel
   instance, which can be run on a device.


See the DPC++ Specification for more details about the APIs.

