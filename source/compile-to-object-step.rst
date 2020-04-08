.. _compile-to-object-step:

Compile to Object Step
======================


During the compile to object step, the source files are compiled and the
output is the fat objects - one per input source. To support `single
source compilation <single-source-compilation.html>`__,
an integration header file is created for each source. In the
compilation model figure above, these are named ``a.h`` and ``b.h``
respectively; however, in practice they will have a uniquely generated
name to avoid conflict with any actual ``a.h`` or ``b.h`` file. The
integration header enables the host code to invoke the device code and
execute it on different devices with the necessary communication and
coordination enabled through the oneAPI programming model.


Once the integration header is created, the compile to object step is
performed by the appropriate compiler:


-  Host Compiler - The host code is compiled by the host compiler. The
   host compiler is set by default during installation. The output is an
   object file that represents the host code. It includes the
   integration header to interoperate with the device code.
-  SPIR-V device compiler – The device code is compiled by the SPIR-V
   compiler to generate a SPIR-V intermediate representation of the
   code. The output is a target-independent object file, which is a
   SPIR-V binary intermediate representation of the device code.
-  Specific device compiler – The device code is compiled by a specific
   device compiler to generate a target specific object file. This is
   part of an offline compilation scenario. The target is specified
   using the ``-Xsycl_targets`` option.


Once the host object file and the specified target object files have
been created, they are grouped together using the bundler tool into a
fat object file. In the example command above, there is no specific
device compiler employed; only the SPIR-V device compiler is invoked to
create target independent object files. Note that when compilation and
linkage are done in a single step, then no fat objects are created, thus
avoiding bundling/unbundling overhead.

