.. _device:

Device
======


The ``device`` class represents the capabilities of the accelerators in
a system, as detailed in :ref:`execution-model`. The
class contains member functions for constructing devices and obtaining
information about the device. One form of constructor requires zero
arguments. The constructor can also take a device selector argument that
chooses which type of accelerator to employ, such as CPU, GPU, or FPGA.
Lastly, construction can be via OpenCL software technology by code using
``cl_device_id`` for interoperability.


The device class contains member functions for querying information
about the device, which is useful for DPC++ programs where multiple
devices are created. Some calls return basic information, such as
``is_host()``, ``is_cpu()``, ``is_gpu()``. For more detailed
information, the function ``get_info`` sets a series of attributes with
pertinent information about the device including:


-  The local and global work item IDs
-  The preferred width for built in types, native ISA types, and clock
   frequency
-  Cache width and sizes
-  Device support attributes, such as unified memory support,
   endianness, and (if the device is online) compiler capable
-  Name, vendor, and version of the device


.. include:: device.inc.rst

.. include:: device-info.inc.rst
