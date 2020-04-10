.. _sample-program:

Sample Program
==============


The following code sample contains a program that employs the oneAPI
programming model to compute a vector addition. The program computes the
formula ``c = a + b`` across arrays, ``a`` and ``b``, each containing
1024 elements, and places the result in array ``c``. The following
discussion focuses on sections of code identified by line number in the
sample. The intent with this discussion is to highlight the required
functionality inherent when employing the programming model.


.. note::

   Keep in mind that this sample code is intended to illustrate the four
   models that comprise the oneAPI programming model; it is not intended
   to be a typical program or the simplest in nature.


.. literalinclude:: /examples/vector-add.cpp
   :linenos:

A DPC++ program has the :term:`Single Source` property, which means
the :term:`Host Code` and the :term:`Device Code` can be placed in
the same file so that the compiler treats them as the same compilation
unit. This can potentially result in performance optimizations across
the boundary between host and device code. The single source property
differs from a programming model like OpenCL software technology where
the host code and device code are typically in different files, and
the host and device compiler are different entities, which means no
optimization can occur between the host and device code
boundary. Therefore, when scrutinizing a DPC++ program, the first step
is to understand the delineation between host code and device code. To
be more specific, DPC++ programs are delineated into different scopes
similar to programming language scope, which is typically expressed
via ``{`` and ``}`` in many languages.

The three types of scope in a DPC++ program include:


- :term:`Application Scope`: Code that executes on the host
- :term:`Command Group Scope`: Code that acts as the interface between
  the host and device
- :term:`Kernel Scope`: Code that executes on the device


In this example, command group scope comprises lines 45 through 54 and
includes coordination and data passing operations required in the
program to enact control and communication between the host and the
device.


|image0|


Kernel scope, which is nested in the command group scope, comprises
lines 50 to 52. Application scope consists of all the other lines not in
command group or kernel scope. Syntactically, definitions are included
from the top level include file; ``sycl.hpp`` and ``namespace``
declarations can be added for convenience.


The function of each of the lines and its classification into one of the
four models are detailed as follows:


-  Lines 2 and 6 – ``include`` and ``namespace`` – programs employing
   the oneAPI programming model require the ``include`` of
   ``cl/sycl.hpp``. It is recommended to employ the ``namespace``
   statement at line 6 to save typing repeated references into the
   ``cl::sycl`` namespace.


   |image1|


-  Lines 20 to 36 – Platform model – programs employing the oneAPI
   programming model can query the host for available platforms and can
   either select one to employ for execution or allow the oneAPI runtime
   to choose a default platform. A platform defines the relationship
   between the host and device(s). The platform may have a number of
   devices associated with it and a program can specify which device(s)
   to employ for execution or allow the oneAPI runtime to choose a
   default device.


   |image2|


-  Lines 39 and 45 – Execution model – programs employing the oneAPI
   programming model define command queues that issue command groups.
   The command groups control execution on the device.


   |image3|


-  Lines 41 to 43 and lines 46 to 48 – Memory model – programs employing
   the oneAPI programming model may use buffers and accessors to manage
   memory access between the host and devices. In this example, the
   arrays, ``a``, ``b``, and ``c`` are defined and allocated on the
   host. Buffers, ``a_device``, ``b_device``, and ``c_device``, are
   declared to hold the values from ``a``, ``b``, and ``c`` respectively
   so the device can compute the vector addition. The accessors,
   ``a_in`` and ``b_in``, denote that ``a_device`` and ``b_device`` are
   to have read only access on the device. The accessor ``c_res``
   denotes that ``c_device`` is to allow write access from the device.


   |image4|


- Line 50 to 52 – Kernel Programming Model – The C++ language
  ``parallel_for`` statement denotes that the code enclosed in its
  scope will execute in parallel across the :term:`Processing Elements
  <Processing Element>` of the device. This example code employs a C++
  lambda to represent the kernel.


   |image5|


-  Line 17 and 56 – Scope and Synchronization – Memory operations
   between the buffers and actual host memory execute in an asynchronous
   fashion. To ensure synchronization, the command queue is placed
   inside another scope at line 17 and 56 which tells the runtime to
   synchronize before the scope is exited as part of the buffer’s
   destructors being executed. This practice is used in many programs.


When compiled and executed, the sample program computes the 1024 element
vector add in parallel on the accelerator. This assumes the accelerator
has multiple compute elements capable of executing in parallel. This
sample illustrates the models that the software developer will need to
employ in their program. The next sections discuss in more details those
four models: the Platform model, the Execution model, the Memory model,
and the Kernel model.


.. |image0| image:: /image/GUID-D971E8B3-6DE1-407B-B5DE-66656531746A-low.png
   :width: 622px
   :height: 181px
.. |image1| image:: /image/GUID-D2597DA3-4AB5-48B6-9DC8-9ADEF5DA116F-low.png
   :width: 622px
   :height: 90px
.. |image2| image:: /image/GUID-3FC06310-C983-4891-B125-B2E6F05D6E47-low.png
   :width: 622px
   :height: 307px
.. |image3| image:: /image/GUID-C7465487-3179-41E7-B108-6A7839DF68EE-low.png
   :width: 622px
   :height: 129px
.. |image4| image:: /image/GUID-F7842513-F1B5-4138-BF03-07643FCCCE30-low.png
   :width: 622px
   :height: 147px
.. |image5| image:: /image/GUID-10CE50B9-6F91-4968-BDD4-14D157078452-low.png
   :width: 622px
   :height: 54px

