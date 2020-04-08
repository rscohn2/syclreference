.. _operating-system-differences:

Operating System Differences
============================


On Linux, the GDB debug engine is used to debug both the host process
and all device code. Once Eclipse has been configured to launch GDB, the
debug experience should be similar to debugging a client/server
application with standard GDB. GDB (Python) scripts have access to both
the host and the device part.


On Windows, the Microsoft debug engine is used to debug the host process
and GDB is used to debug the device code. The parts are combined in
Visual Studio and presented in a single debug session. GDB (Python)
scripts only have access to the device part.

