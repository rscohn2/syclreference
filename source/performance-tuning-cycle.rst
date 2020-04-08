.. _performance-tuning-cycle:

Performance Tuning Cycle
========================


The goal of the performance tuning cycle is to improve the time to
solution whether that be interactive response time or elapsed time of a
batch job. In the case of a heterogeneous platform, there are compute
cycles available on the devices that execute independently from the
host. Taking advantage of these resources offers a performance boost.


The performance tuning cycle includes the following steps detailed in
the next sections:


#. Establish a baseline
#. Identify kernels to offload
#. Offload the kernels
#. Optimize
#. Repeat until objectives are met

.. toctree::
   :maxdepth: 4

   
   establish-baseline
   identify-kernels-to-offload
   offload-kernels
   optimize
   recompile-run-profile-and-repeat