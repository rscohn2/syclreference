.. _example-cpu-commands:

Example CPU Commands
====================


The commands below implement the scenario when part of the device code
resides in a static library.


Produce a fat object with device code:


::


   dpcpp -c static_lib.cpp


Create a fat static library out of it using the ``ar`` tool:


::


   ar cr libstlib.a static_lib.o


Compile application sources:


::


   dpcpp -c a.cpp


Link the application with the static library:


::


   dpcpp -foffload-static-lib=libstlib.a a.o -o a.exe

