.. _onedpl-library-usage:

oneDPL Library Usage
====================


oneDPL is a component of the Intel® oneAPI Base Toolkit.


Several C++ standard APIs have been tested and function well within
DPC++ kernels. To use them, include the corresponding C++ standard
header files and use the std namespace.


To use Parallel STL and non-standard API extensions, include necessary
header files in the source code. All oneDPL header files are in the
``dpstd`` directory. Use ``#include <dpstd/…>`` to include them.


oneDPL has its own namespace dpstd for all its extensions, including
DPC++ execution policies, non-standard algorithms, special iterators,
etc.


To build the code using Parallel STL algorithms, set up environment
variables for the Intel oneAPI DPC++ Compiler, Intel oneAPI Threading
Building Blocks, and Parallel STL. For details, see `Get Started with
Parallel
STL <https://software.intel.com/en-us/articles/get-started-with-parallel-stl>`__\ .

