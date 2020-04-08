.. _compiler-drivers:

Compiler Drivers
================


The Intel oneAPI DPC++ Compiler includes two compiler drivers:


-  ``dpcpp`` is a GCC\* compatible compiler driver. It recognizes
   GCC-style command line options (starting with “-“) and can be useful
   for projects that share a build system across multiple operating
   systems.
-  ``dpcpp-cl`` is a Microsoft\* Visual C++ compatible driver. This
   driver is only available on Windows. It recognizes Windows command
   line options (starting with “/”) and can be useful for Microsoft
   Visual Studio*-based projects.
-  The examples in this guide use the ``dpcpp`` driver.

