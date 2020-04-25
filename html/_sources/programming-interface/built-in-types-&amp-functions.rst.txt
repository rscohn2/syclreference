.. _built-in-types-&amp-functions:

Built-in Types & Functions
==========================


The DPC++ built-in functions provide low level capabilities that can
execute on the host and device with some level of compatibility. Section
4.13 of the SYCL Specification details all the various built-in types
and functions available.


One task taken care of by the implementation is the mapping of C++
fundamental types such as int, short, long such that the types agree
between the host and the device.


The built-in scalar data types are summarized in the SYCL Specification.
In general, the built-in types cover floating point, double, half
precision, char, signed char, unsigned char, short, unsigned short, int,
unsigned int, long, unsigned long, long long, unsigned long long, and
signed integer. Lastly, the built-in types can be post fixed with 2, 3,
4, 8, or 16, which indicated a vector of the post fixed type. For
example, ``float3`` indicates a type consisting of three floating point
elements addressed as one object. A ``float3`` is common in image
processing algorithms for representing RGB data.


The built-in functions are either defined as part of lower level classes
or part of the basic math functions. These built-in functions enable
vendors to provide differentiated built-in functions specific to the
architecture while also enabling basic functionality for generic
implementations.


The categories of built-in functions are summarized as:


-  Work-item functions – pertaining to ``nd_item`` and ``group`` classes
-  Basic Math functions – low level math and comparison functions
-  General math functions – Transcendental, trigonomic, and geometric
   functions
-  Vector load and store – reading and writing ``vec`` class
-  Synchronization – ``nd_item`` related barriers
-  Output – ``stream`` class for output

