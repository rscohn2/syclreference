.. _offline-compilation-for-gpu:

Offline Compilation for GPU
===========================


.. container:: Note


   .. rubric:: Note
      :class: NoteTipHead

   This is an experimental feature with limited functionality.


The following example command produces ``app.out`` for a specific GPU
target:


::


   dpcpp -fsycl-targets=spir64_gen-unknown-linux-sycldevice -Xsycl-target-backend=spir64_gen-unknown-linux-sycldevice "-device skl" a.cpp b.cpp -o app.out

