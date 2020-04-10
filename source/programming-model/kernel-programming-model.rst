.. _kernel-programming-model:

Kernel Programming Model
========================


The kernel programming model for oneAPI is based upon the SYCL\* kernel
programming model. It enables explicit parallelism between the host and
device. The parallelism is explicit in the sense that the programmer
determines what code executes on the host and device; it is not
automatic. The kernel code executes on the accelerator. Programs
employing the oneAPI programming model support single source, meaning
the host code and device code can be in the same source file. However,
there are differences between the source code accepted in the host code
and the device code with respect to language conformance and language
features. The SYCL Specification defines in detail the required language
features for host code and device code. The following is a summary that
is specific to the oneAPI product.

.. toctree::
   :maxdepth: 4

   
   cpp-language-requirements
   error-handling
   fall-back