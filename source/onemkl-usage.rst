.. _onemkl-usage:

oneMKL Usage
============


When using the DPC++ programming language interfaces, there are a few
changes to consider:


-  oneMKL has a dependency on the Intel oneAPI DPC++ Compiler and Intel
   oneAPI DPC++ Library. Applications must be built with the Intel
   oneAPI DPC++ Compiler, the DPC++ headers made available, and the
   application linked with oneMKL using the DPC++ linker.
-  DPC++ interfaces in oneMKL use ``cl::sycl::buffer`` objects for input
   data (vectors, matrices, etc.).
-  Some DPC++ interfaces in oneMKL support the use of Unified Shared
   Memory (USM) pointers for input data in place of the
   ``cl::sycl::buffer`` objects.
-  DPC++ interfaces in oneMKL are overloaded based on the floating point
   types. For example, there are several general matrix multiply APIs,
   accepting single precision real arguments (float), double precision
   real arguments (double), half precision real arguments (half), and
   complex arguments of different precision using the standard library
   types ``std::complex<float>``, ``std::complex<double>``.
-  A two-level namespace structure for oneMKL is added for DPC++
   interfaces:


.. container:: tablenoborder


   .. list-table:: 
      :header-rows: 1

      * -     Namespace     
        -     Description     
      * -     \ ``mkl``\     
        -     Contains common elements between various domains in    oneMKL    
      * -     \ ``mkl::blas``\     
        -     Contains dense vector-vector, matrix-vector, and    matrix-matrix low level operations    
      * -     \ ``mkl::lapack``\     
        -     Contains higher-level dense matrix operations like matrix    factorizations and eigensolvers    
      * -     \ ``mkl::rng``\     
        -     Contains random number generators for various probability    density functions    
      * -     \ ``mkl::vm``\     
        -     Contains vector math routines     
      * -     \ ``mkl::dft``\     
        -     Contains fast fourier transform operations     
      * -     \ ``mkl::sparse``\     
        -     Contains sparse matrix operations like sparse    matrix-vector multiplication and sparse triangular solver    



