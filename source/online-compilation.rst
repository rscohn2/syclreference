.. _online-compilation:

Online Compilation
==================


Online compilation is the compilation of the kernel code during the
execute step. This mode of execution can have significant performance
benefits, as the compiler may generate more efficient code. As an
example, the device kernel may take advantage of a larger SIMD width
made available on the underlying hardware it executes on, or some kernel
parameters, such as data tile size or loop count, may be set to specific
constants to help when applying typical compiler optimizations like loop
unrolling.


Online compilation results in compiling the SPIR-V binary image to
native device code. SPIR-V is the default portable device code format,
which can run on any compatible device.


The oneAPI runtime does not perform the online compilation. Instead, it
requests underlying runtimes for the requested devices to perform the
compilation job via lower-level interfaces. For example, it will
ultimately use the ``clCreateProgramWithIL`` API on an OpenCL device to
take SPIR-V as input and compile it to native code.


Offline-compiled device code is injected into the runtime system though
a different API. In the OpenCL platform case, the API is
``clCreateProgramWithBinary``.


Online compilation of a SPIR-V binary image embedded into the fat binary
is usually triggered when one of the kernels constituting the module is
requested to run. The request ``cl::sycl::handler::parallel_for`` always
has information about the device where the kernel is to be executed;
hence the runtime knows what device(s) to target. When one kernel is
requested to run, the entire SPIR-V module it belongs to is compiled.

