.. _identify-kernels-to-offload:

Identify Kernels to Offload
===========================


To best utilize the compute cycles available on the devices of a
heterogeneous platform, it is important to identify the tasks that are
compute intensive and that can benefit from parallel execution. Consider
an application that executes solely on a CPU, but there may be some
tasks suitable to execute on a GPU. This can be determined using the
offload performance prediction capabilities of Intel Advisor.


Intel Advisor can create performance characterizations of the workload
as it may execute on an accelerator. It consumes the information from
profiling the workload and provides performance estimates, bottleneck
characterization, and offload data transfer estimates.


Typically, kernels with high compute, a large dataset, and limited
memory transfers are best suited for offload to a device.

