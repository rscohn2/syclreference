.. _create-the-static-library:

Create the Static Library
=========================


Prepare the compiler and compile the source as described in the `Get
Started
Guide <https://software.intel.com/en-us/get-started-with-dpcpp-compiler>`__.


::


   dpcpp app1.cpp app2.cpp -c


On Linux: ``ar cr libapp.a app1.o app2.o``


On Windows: ``lib -out:libapp.lib app1.obj app2.obj``

