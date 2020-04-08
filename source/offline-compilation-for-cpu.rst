.. _offline-compilation-for-cpu:

Offline Compilation for CPU
===========================


.. container:: Note


   .. rubric:: Note
      :class: NoteTipHead

   This is an experimental feature with limited functionality.


Use this command to produce ``app.out``, which only runs on an x86
device.


::


   dpcpp -fsycl-targets=spir64_x86_64-unknown-linux-sycldevice a.cpp b.cpp -o app.out

