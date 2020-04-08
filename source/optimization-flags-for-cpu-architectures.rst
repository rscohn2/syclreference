.. _optimization-flags-for-cpu-architectures:

Optimization Flags for CPU Architectures
========================================


In offline compilation mode, optimization flags can be used to produce
code aimed to run better on a specific CPU architecture. Those are
passed via the ``-Xsycl-target-backend dpcpp`` option:


::


   dpcpp -fsycl-targets=spir64_x86_64-unknown-linux-sycldevice -Xsycl-target-backend=spir64_x86_64-unknown-linux-sycldevice “<CPU optimization flags>” a.cpp b.cpp -o app.out


Supported CPU optimization flags are:


::


   -simd=<instruction_set_arch> Set target instruction set architecture:
   'sse42' for Intel® Streaming SIMD Extensions 4.2
   'avx' for Intel® Advanced Vector Extensions
   'avx2' for Intel® Advanced Vector Extensions 2
   'skx' for Intel® Advanced Vector Extensions 512


.. container:: Note


   .. rubric:: Note
      :class: NoteTipHead

   The set of supported optimization flags may be changed in future
   releases.

