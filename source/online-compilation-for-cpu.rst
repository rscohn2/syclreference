.. _online-compilation-for-cpu:

Online Compilation for CPU
==========================


No specifics for CPU target. The command below produces a fat binary
with a SPIR-V image, which can be run with online compilation on any
compatible device, including a CPU.


::


   dpcpp a.cpp b.cpp -o app.out

