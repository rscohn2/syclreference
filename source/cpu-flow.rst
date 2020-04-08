.. _cpu-flow:

CPU Flow
========


Use of a CPU is recommended for use cases with branch operations,
instruction pipelining, dynamic context switch, and so on.


DPC++ supports online and offline compilation modes for the CPU target.
Online compilation is the same as for all other targets.

.. toctree::
   :maxdepth: 4

   
   example-cpu-commands
   online-compilation-for-cpu
   offline-compilation-for-cpu
   optimization-flags-for-cpu-architectures
   host-and-kernel-interaction-on-cpu