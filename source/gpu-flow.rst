.. _gpu-flow:

GPU Flow
========


The GPU Flow is like the CPU flow except that different back ends and
target triples are used.


Target triple for GPU offline compiler is
``spir64_gen-unknown-linux-sycldevice``.


.. container:: Note


   .. rubric:: Note
      :class: NoteTipHead

   GPU offline compilation currently requires an additional option,
   which specifies the desired GPU architecture.

.. toctree::
   :maxdepth: 4

   
   example-gpu-commands
   offline-compilation-for-gpu