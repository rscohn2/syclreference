.. _debugger-features:

Debugger Features
=================


GDB is based on GDB 8.3 with multi-target extensions that adds support
for Intel accelerator targets. It supports all GDB features that are
applicable to the respective target and allows debugging the host
application plus all supported devices within the same debug session.


Device code is presented as one or more additional inferiors. Inferiors
are GDB’s internal representation of each program execution. GDB
automatically detects offloads to a supported device and creates a new
inferior to debug device functions offloaded to that device. This
feature is implemented using GDB’s Python\* scripting extension. It is
important that the correct -data-directory is specified when invoking
GDB.


The first version adds support for current Intel Graphics Technology and
thus allows debugging device functions offloaded to Host, CPU, GPU, and
FPGA emulation devices.


GDB plugs into Eclipse on Linux\* host and Microsoft\* Visual Studio\*
on Windows\* host.

