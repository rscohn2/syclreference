.. _oneapi-programming-model:

===================
 Programming Model
===================


The oneAPI programming model is based upon the `SYCL\*
Specification <https://www.khronos.org/registry/SYCL/specs/sycl-1.2.1.pdf>`__.
The specification presents a general heterogeneous compute capability by
detailing four models. These models categorize the actions a developer
needs to perform to employ one or more devices as an accelerator.
Aspects of these models appear in every program that employs the oneAPI
programming model. These models are summarized as:


- :ref:`platform-model`: Specifies the :term:`Host` and :term:`Device`.
- :ref:`execution-model`: Specifies the :term:`Command Queue` and
  issuing commands for execution on the device(s).
- :ref:`memory-model`: Defines how the host and devices interact with
  memory.
- :ref:`kernel-programming-model`: Defines the code that executes on
  the device(s). This code is known as the kernel.


The programming language for oneAPI is Data Parallel C++ (DPC++) and
employs modern features of the C++ language to enact its parallelism. In
fact, when writing programs that employ the oneAPI programming model,
the programmer routinely uses language features such as C++ lambdas,
templates, parallel_for, and closures.


.. container:: Note


   .. rubric:: Tip
      :class: NoteTipHead

   If you are unfamiliar with these C++11 and later language features,
   consult other C++ language references and gain a basic understanding
   before continuing.


When evaluating and learning oneAPI, keep in mind that the programming
model is general enough to accommodate multiple classes of accelerators;
therefore, there may be a greater number of API calls required to access
the accelerators than more constrained APIs, such as those only
accessing one type of accelerator.


One of the primary motivations for DPC++ is to provide a higher-level
programming language than OpenCL™ C code, which it is based upon.
Readers familiar with OpenCL programs will see many similarities to and
differences from OpenCL code. This chapter points out similarities and
differences where appropriate. This chapter also points to portions of
the SYCL Specification for further information.

.. toctree::
   :maxdepth: 4

   
   sample-program
   platform-model
   execution-model
   memory-model
   kernel-programming-model
