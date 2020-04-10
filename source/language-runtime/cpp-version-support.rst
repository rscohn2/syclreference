.. _cpp-version-support:

C++ Version Support
===================


The `oneAPI Programming
Model <oneapi-programming-model.html>`__ section and
subsections documented the C++ language features accepted in code at
application scope and command group scope in a DPC++ program.
Application scope and command group scope includes the code that
executes on the host. That section also documented the C++ language
features accepted in code at kernel scope in a DPC++ program. Kernel
scope is the code that executes on the device. In general, the full
capabilities of C++ are available at application and command group
scope. At kernel scope there are limitations in accepted C++ due to the
more limited, but focused, capabilities of accelerators.


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

