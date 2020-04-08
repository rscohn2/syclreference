.. _openmp-offload-interoperability:

OpenMP\* Offload Interoperability
=================================


The oneAPI programming model provides a unified compiler based on
LLVM/Clang with support for OpenMP\* offload. This allows seamless
integration that allows the use of OpenMP constructs to either
parallelize host side applications or offload to a target device.


DPC++ is based on TBB runtime when executing device code on the CPU;
hence, using both OpenMP and DPC++ on a CPU can lead to oversubscribing
of threads. Performance analysis of workloads executing on the system
could help determine if this is occurring.

