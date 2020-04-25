.. _program:

Program
=======


A DPC++ ``program`` class encapsulates a program, either a host program
or an OpenCL program. The ``program`` object is employed when
compilation or linkage of the program is desired.


Constructors for a ``program`` object require a context at a minimum.


Member functions of the ``program`` class include:


-  ``get`` – obtain an OpenCL ``program`` object from the program
-  ``is_host`` – determines if the program is targeted for the host
-  ``compile_with_kernel_type`` – enables compilation of a kernel
-  ``compile_with_source`` – compiles OpenCL kernel
-  ``build_with_kernel_type`` – builds kernel function
-  ``build_with_source`` – builds kernel function from source
-  ``link`` – link the object files
-  ``has_kernel`` – determines if the program has a valid kernel
   function
-  ``get_kernel`` – obtains the kernel from the program
-  ``get_binaries`` – obtain a vector of compiled binaries for each
   device in the program
-  ``get_context`` – obtain the context the program was built with
-  ``get_devices`` – obtain a vector of the compiled binary sizes for
   each device

.. include:: program.inc.rst
