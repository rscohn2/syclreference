.. _link-to-executable-step:

Link to Executable Step
=======================


The link to executable step transforms the fat object files into a fat
binary. The actions taken during this step are very similar to the
traditional link step of compiling for one target, such as x86:


-  Object files are linked together, satisfying variable and function
   dependencies between the files
-  Third-party library dependencies are satisfied by linking the
   specified libraries
-  Compiler libraries and runtime routines are linked into the resulting
   executable.


There are some differences. Since the oneAPI programming model enables
more devices to be employed and compilation to occur at more than one
time, the additional steps employed during the link to executable step
are as follows:


-  Unbundling of the fat object files – Multiple target-specific and
   generic SPIR-V object files are bundled during the compile to object
   step. These fat object files are unbundled so that the correct target
   specific and generic SPIR-V object files can be grouped together for
   linking.


-  Offline compilation – Compilation during the link to executable step
   can occur. This step is optional and is used in the offline
   compilation scenario.


   The option to request offline compilation (for example, for the Intel
   Processor Graphics included in 6th Generation Intel Processors) at
   this step is:


   ::


      dpcpp -fsycl-targets=spir64_gen-unknown-linux-sycldevice -Xsycl-target-backend=spir64_gen-unknown-linux-sycldevice "-device skl" src1.cpp src2.cpp 


   The process of compiling the linked generic SPIR-V device binary into
   a target image is repeated for every device requested.


-  Fat binary – The resulting host code and potentially multiple device
   images are linked together into a fat binary. This is the resulting
   executable that executes on the host device and then selectively
   executes the device kernels on the appropriate devices. A generic
   SPIR-V image may be included in the fat binary for use during the
   `online compilation
   step <online-compilation.html>`__ (default if
   offline compilation is not requested).

