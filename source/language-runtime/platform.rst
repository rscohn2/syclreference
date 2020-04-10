.. _platform:

Platform
========


The DPC++ platform class encapsulates the host and device functionality
employed by a DPC++ program.


The constructors either construct a host platform, or for backwards
compatibility, an OpenCL platform. One version of the constructor takes
a ``device_selector`` object employed to choose the particular device
for execution.


Member functions for the platform class include:


-  ``get`` – obtain an OpenCL platform from the platform
-  ``get_info`` – obtain information on the platform
-  ``has_extension`` – query the platform for specific support of an
   extension
-  ``is_host`` – is the platform a host platform
-  ``get_devices`` – return all devices associated with the platform


The member function ``get_info`` returns specific information as a
string about the platform, including:


-  Profile – returns if platform supports for full or embedded profile
-  Version – returns version number information
-  Name – returns the name of the platform
-  Vendor – returns the vendor of the platform
-  Extensions – returns a vector of strings that list the supported
   extensions

