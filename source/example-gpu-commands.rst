.. _example-gpu-commands:

Example GPU Commands
====================


The examples below illustrate how to create and use static libraries
with device code on Linux.


Produce a fat object with device code:


::


   dpcpp -c static_lib.cpp


Create a fat static library out of it using the ar tool:


::


   ar cr libstlib.a static_lib.o


Compile application sources:


::


   dpcpp -c a.cpp


Link the application with the static library:


::


   dpcpp -foffload-static-lib=libstlib.a a.o -o a.exe

