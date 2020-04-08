.. _onedal-usage:

oneDAL Usage
============


The following dependencies are needed to build and link your application
with oneDAL:


#. `Intel oneAPI DPC++
   Compiler <https://software.intel.com/en-us/get-started-with-dpcpp-compiler>`__
#. `OpenCL™
   Runtime <https://software.intel.com/en-us/articles/opencl-drivers>`__
   1.2 or later


A oneDAL-based application can seamlessly execute algorithms on CPU or
GPU by picking the proper device selector. New capabilities also allow:


-  extracting DPC++ buffers from numeric tables and pass them to a
   custom kernel
-  creating numeric tables from DPC++ buffers


Algorithms are optimized to reuse DPC++ buffers to keep GPU data and
remove overload from repeatedly copying data between GPU and CPU.

