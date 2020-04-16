==========
 Language
==========

.. todo:: C++ version mininum

:ref:`oneapi-programming-model` and subsections documented the C++
language features accepted in code at application scope and command
group scope in a DPC++ program.  Application scope and command group
scope includes the code that executes on the host. That section also
documented the C++ language features accepted in code at kernel scope
in a DPC++ program. Kernel scope is the code that executes on the
device. In general, the full capabilities of C++ are available at
application and command group scope. At kernel scope there are
limitations in accepted C++ due to the more limited, but focused,
capabilities of accelerators.


Compilers from different vendors have small eccentricities or
differences in their conformance to the C++ standard. The Intel oneAPI
DPC++ Compiler is a LLVM-based compiler and therefore drafts the
specific behavior of the LLVM-based compilers in accepting and creating
executables from C++ source code. To determine the specific LLVM version
that the Intel oneAPI DPC++ Compiler is based upon, use the
``-–version`` option.


::


   dpcpp --version


For example:


::


   DPC++ Compiler 2021.1 (2019.8.x.0.1010)
   Target: x86_64-pc-windows-msvc
   Thread model: posix
   InstalledDir: c:\PROGRA~2\INTELO~1\compiler\latest\windows\bin


Keywords
========


One of the design goals of DPC++ and SYCL is to not add keywords to the
language. The motivation is to enable easier compiler vendor adoption.
Whereas OpenCL C code and other accelerator-targeted languages require
proprietary keywords, DPC++ does not.

Preprocessor Directives and Macros
==================================


Standard C++ preprocessing directives and macros are supported by the
compiler. In addition, the SYCL Specification defines the SYCL specific
preprocessor directives and macros.


The following preprocessor directives and macros are supported by the
compiler.


.. container:: tablenoborder


   .. list-table:: 
      :header-rows: 1

      * -     Directive     
        -     Description     
      * -     \ ``SYCL_DUMP_IMAGES``\     
        -     If true, instructs runtime to dump the device image       
      * -     \ ``SYCL_USE_KERNEL_SPV=<device binary>``\     
        -     Employ device binary to fulfill kernel launch request       
      * -     \ ``SYCL_PROGRAM_BUILD_OPTIONS``\     
        -     Used to pass additional options for device program    building.    



Standard Library Classes Required for the Interface
===================================================


Programming for oneAPI employs a variety of vectors, strings, functions,
and pointer objects common in STL programming.


The SYCL specification documents a facility to enable vendors to provide
custom optimized implementations. Implementations require aliases for
several STL interfaces. These are summarized as follows:


.. include:: stlclasses.inc.rst
