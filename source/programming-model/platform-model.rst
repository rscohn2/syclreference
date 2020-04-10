.. _platform-model:

Platform Model
==============


The platform model for oneAPI is based upon the SYCL\* platform model.
It specifies a host controlling one or more devices. A host is the
computer, typically a CPU-based system executing the primary portion
of a program, specifically the application scope and the command group
scope. The host coordinates and controls the compute work that is
performed on the devices. A device is an accelerator, a specialized
component containing compute resources that can quickly execute a
subset of operations typically more efficiently than the CPUs in the
system.  Each device contains one or more compute units that can
execute several operations in parallel. Each compute unit contains one
or more :term:`Processing Elements <Processing Element>` that serve as
the individual engine for computation.


A system can instantiate and execute several platforms simultaneously,
which is desirable because a particular platform may only target a
subset of the available hardware resources on a system. However, in the
typical case, a system will have one platform comprised of one or more
supported devices, and the compute resources made available by those
devices.


The following figure provides a visual depiction of the relationships in
the platform model. One host communicates with one or more devices. Each
device can contain one or more compute units. Each compute unit can
contain one or more processing elements.


| 
| |image0|


The platform model is general enough to be mapped to several different
types of devices and lends to the functional portability of the
programming model. The hierarchy on the device is also general and can
be mapped to several different types of accelerators from FPGAs to GPUs
and ASICs as long as these devices support the minimal requirements of
the oneAPI programming model. Consult the `Intel oneAPI Base Toolkit
System
Requirements <https://software.intel.com/en-us/articles/intel-oneapi-base-toolkit-system-requirements>`__
for more information.


.. |image0| image:: /image/GUID-91DDF658-E91E-4017-A8FB-0D957B408C2C-low.png
   :width: 800px

