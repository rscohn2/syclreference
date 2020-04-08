.. _oneapi-programming-model-overview:

oneAPI Programming Model Overview
=================================


The oneAPI programming model provides a comprehensive and unified
portfolio of developer tools that can be used across hardware targets,
including a range of performance libraries spanning several workload
domains. The libraries include functions custom-coded for each target
architecture, so the same function call delivers optimized performance
across supported architectures. DPC++ is based on industry standards and
open specifications to encourage ecosystem collaboration and innovation.


|image0|


As shown in the figure above, applications that take advantage of the
oneAPI programming model can execute on multiple target hardware
platforms ranging from CPU to FPGA. The oneAPI product is comprised of
the Intel® oneAPI Base Toolkit and several add-on toolkits featuring
complementary tools based on specific developer workload needs. The
Intel oneAPI Base Toolkit includes the Intel® oneAPI DPC++ Compiler, the
Intel® DPC++ Compatibility Tool, select libraries, and analysis tools.


-  Developers who want to migrate existing CUDA\* code to DPC++, can use
   the **Intel DPC++ Compatibility Tool** to help migrate their existing
   projects to DPC++.
-  The **Intel oneAPI DPC++ Compiler** supports direct programming of
   code targeting accelerators. Direct programming is coding for
   performance when APIs are not available. It supports online and
   offline compilation for CPU and GPU targets and offline compilation
   for FPGA targets.
-  API-based programming is supported via sets of optimized libraries.
   The library functions provided in the oneAPI product are pre-tuned
   for use with any supported target architecture, eliminating the need
   for developer intervention. For example, the BLAS routine available
   from **Intel oneAPI Math Kernel Library** is just as optimized for a
   GPU target as a CPU target.
-  Finally, the compiled DPC++ application can be analyzed and debugged
   to ensure performance, stability, and energy efficiency goals are
   achieved using tools such as **Intel® VTune™ Profiler** or **Intel®
   Advisor**.


.. |image0| image:: image/GUID-5758F720-3C7C-4919-9BB5-F650F88DBD01-low.jpg

.. toctree::
   :maxdepth: 4

   
   data-parallel-cpp-dpcpp
   oneapi-toolkit-distribution