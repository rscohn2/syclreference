.. _intel-oneapi-collective-communications-library-oneccl:

Intel oneAPI Collective Communications Library (oneCCL)
=======================================================


Intel oneAPI Collective Communications Library (oneCCL) is a scalable
and high-performance communication library for Deep Learning (DL) and
Machine Learning (ML) workloads. It develops the ideas that originated
in Intel® Machine Learning Scaling Library and expands the design and
API to encompass new features and use cases.


oneCCL features include:


-  Built on top of lower-level communication middleware – MPI and
   libfabrics
-  Optimized to drive scalability of communication patterns by enabling
   the productive trade-off of compute for communication performance
-  Enables a set of DL-specific optimizations, such as prioritization,
   persistent operations, out of order execution, etc.
-  DPC++-aware API to run across various hardware targets, such as CPUs
   and GPUs
-  Works across various interconnects: Intel® Omni-Path Architecture
   (Intel® OPA), InfiniBand*, and Ethernet

.. toctree::
   :maxdepth: 4

   
   oneccl-usage
   oneccl-code-sample