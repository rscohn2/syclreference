.. _introduction-to-oneapi-programming:

Introduction to oneAPI Programming
==================================


Obtaining high compute performance on today’s modern computer
architectures requires code that is optimized, power efficient, and
scalable. The demand for high performance continues to increase due to
needs in AI, video analytics, data analytics, as well as in traditional
high performance computing (HPC).


Modern workload diversity has resulted in a need for architectural
diversity; no single architecture is best for every workload. A mix of
scalar, vector, matrix, and spatial (SVMS) architectures deployed in
CPU, GPU, AI, and FPGA
`accelerators <glossary.html>`__
is required to extract the needed performance.


Today, coding for CPUs and accelerators requires different languages,
libraries, and tools. That means each hardware platform requires
completely separate software investments and provides limited
application code reusability across different target architectures.


The oneAPI programming model simplifies the programming of CPUs and
accelerators using modern C++ features to express parallelism with a
programming language called Data Parallel C++ (DPC++). The DPC++
language enables code reuse for the host (such as a CPU) and
accelerators (such as a GPU) using a single source language, with
execution and memory dependencies clearly communicated. Mapping within
the DPC++ code can be used to transition the application to run on the
hardware, or set of hardware, that best accelerates the workload. A host
is available to simplify development and debugging of device code, even
on platforms that do not have an accelerator available.


.. note::

   Not all programs can benefit from the single programming model
   offered by oneAPI. It is important to understand if your program can
   benefit and how to design, implement, and use the oneAPI programming
   model for your program.

.. toctree::
   :maxdepth: 4

   
   oneapi-programming-model-overview
   related-documentation
