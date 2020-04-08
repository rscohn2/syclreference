.. _optimize:

Optimize
========


oneAPI enables functional code that can execute on multiple
accelerators; however, the code may not be the most optimal across the
accelerators. A three-step optimization strategy is recommended to meet
performance needs:


#. Pursue general optimizations that apply across accelerators.
#. Optimize aggressively for the prioritized accelerators.
#. Optimize the host code in conjunction with step 1 and 2.


Optimization is a process of eliminating bottlenecks, i.e. the sections
of code that are taking more execution time relative other sections of
the code. These sections could be executing on the devices or the host.
During optimization, employ a profiling tool such as Intel VTune
Profiler to find these bottlenecks in the code.


This section discusses the first step of the strategy - Pursue general
optimizations that apply across accelerators. Device specific
optimizations and best practices for specific devices (step 2) and
optimizations between the host and devices (step 3) are detailed in
device-specific optimization guides, such as the `Intel oneAPI DPC++
FPGA Optimization
Guide <https://software.intel.com/en-us/download/oneapi-fpga-optimization-guide>`__.
This section assumes that the kernel to offload to the accelerator is
already determined. It also assumes that work will be accomplished on
one accelerator. This guide does not speak to division of work between
host and accelerator or between host and potentially multiple and/or
different accelerators.


General optimizations that apply across accelerators can be classified
into four categories:


#. High-level optimizations
#. Loop-related optimizations
#. Memory-related optimizations
#. DPC++-specific optimizations


The following sections summarize these optimizations only; specific
details on how to code most of these optimizations can be found online
or in commonly available code optimization literature. More detail is
provided for the DPC++ specific optimizations.


.. container:: section
   :name: GUID-C8E012E3-C505-4F8D-B8CD-115808A88AE3


   .. rubric:: High-level Optimization Tips
      :class: sectiontitle

   -  Increase the amount of parallel work. More work than the number of
      processing elements is desired to help keep the processing
      elements more fully utilized.
   -  Minimize the code size of kernels. This helps keep the kernels in
      the instruction cache of the accelerator, if the accelerator
      contains one.
   -  Load balance kernels. Avoid significantly different execution
      times between kernels as the long-running kernels may become
      bottlenecks and affect the throughput of the other kernels.
   -  Avoid expensive functions. Avoid calling functions that have high
      execution times as they may become bottlenecks.


.. container:: section
   :name: GUID-F260A736-C5D9-4B93-B6C4-1ABCAD55499A


   .. rubric:: Loop-related Optimizations
      :class: sectiontitle

   -  Prefer well-structured, well-formed, and simply exit condition
      loops – these are loops have a single exit and a single condition
      when comparing against an integer bound.
   -  Prefer loops with linear indexes and constant bounds – these are
      loops that employ an integer index into an array, for example, and
      have bounds that are known at compile-time.
   -  Declare variables in deepest scope possible. Doing so can help
      reduce memory or stack usage.
   -  Minimize or relax loop-carried data dependencies. Loop-carried
      dependencies can limit parallelization. Remove dependencies if
      possible. If not, pursue techniques to maximize the distance
      between the dependency and/or keep the dependency in local memory.
   -  Unroll loops with pragma unroll.


.. container:: section
   :name: GUID-491AE65B-3C65-49E6-82F8-79D68980295A


   .. rubric:: Memory-related Optimizations
      :class: sectiontitle

   -  When possible, favor greater computation over greater memory use.
      The latency and bandwidth of memory compared to computation can
      become a bottleneck.
   -  When possible, favor greater local and private memory use over
      global memory use.
   -  Avoid pointer aliasing.
   -  Coalesce memory accesses. Grouping memory accesses helps limit the
      number of individual memory requests and increases utilization of
      individual cache lines.
   -  When possible, store variables and arrays in private memory for
      high-execution areas of code.
   -  Beware of loop unrolling effects on concurrent memory accesses.
   -  Avoid a write to a global that another kernel reads. Use a pipe
      instead.


.. container:: section
   :name: GUID-83FBB5E4-2320-42D8-914A-9CE495C6B38D


   .. rubric:: DPC++-specific Optimizations
      :class: sectiontitle

   -  When possible, specify a work-group size. The attribute,
      ``[[cl::reqd_work_group_size(X, Y, Z)]]``, where X, Y, and Z are
      integer dimension in the ND-range, can be employed to set the
      work-group size. The compiler can take advantage of this
      information to optimize more aggressively.
   -  Consider use of the ``-Xsfp-relaxed`` option when possible. This
      option relaxes the order of arithmetic floating-point operations.
   -  Consider use of the ``-Xsfpc`` option when possible. This option
      removes intermediary floating-point rounding operations and
      conversions whenever possible and carries additional bits to
      maintain precision.
   -  Consider use of the ``-Xsno-accessor-aliasing`` option. This
      option ignores dependencies between accessor arguments in a SYCL\*
      kernel.

