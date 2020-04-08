.. _migrating-from-cpp-to-sycl-dpcpp:

Migrating from C++ to SYCL/DPC++
================================


SYCL is a single-source style programming model based on C++. It builds
on features of C++11 and has additional support for C++14 and enables
C++17 Parallel STL programs to be accelerated on OpenCL™ devices. Some
of the supported C++ features include templates, classes, operator
overloading, lambda, and static polymorphism.


When accelerating an existing C++ application on OpenCL devices, SYCL
provides seamless integration as most of the C++ code remains intact.
Refer to sections within `oneAPI Programming
Model <oneapi-programming-model.html>`__ for SYCL
constructs to enable device side compilation.

