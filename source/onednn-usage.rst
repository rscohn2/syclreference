.. _onednn-usage:

oneDNN Usage
============


oneDNN supports systems based on Intel 64 architecture or compatible
processors. A full list of supported CPU and graphics hardware is
available from the Intel oneAPI Deep Neural Network Library System
Requirements.


oneDNN detects the instruction set architecture (ISA) in the runtime and
uses online generation to deploy the code optimized for the latest
supported ISA.


Several packages are available for each operating system to ensure
interoperability with CPU or GPU runtime libraries used by the
application.


.. container:: tablenoborder


   .. list-table:: 
      :header-rows: 1

      * -     Configuration     
        -     Dependency     
      * -     \ ``cpu_dpcpp_gpu_dpcpp``\     
        -     DPC++ runtime     
      * -     \ ``cpu_iomp``\     
        -     OpenMP\* runtime     
      * -     \ ``cpu_gomp``\     
        -     GNU\* OpenMP runtime     
      * -     \ ``cpu_vcomp``\     
        -     Microsoft\* Visual C++ OpenMP runtime     
      * -     \ ``cpu_tbb``\     
        -     Intel oneAPI Threading Building Blocks     




The packages do not include library dependencies and these need to be
resolved in the application at build time with oneAPI toolkits or
third-party tools.


When used in the DPC++ environment, oneDNN relies on the DPC++ runtime
to interact with CPU or GPU hardware. oneDNN may be used with other code
that uses DPC++. To do this, oneDNN provides API extensions to
interoperate with underlying SYCL objects.


One of the possible scenarios is executing a DPC++ kernel for a custom
operation not provided by oneDNN. In this case, oneDNN provides all
necessary APIs to seamlessly submit a kernel, sharing the execution
context with oneDNN: using the same device and queue.


The interoperability API is provided for two scenarios:


-  Construction of oneDNN objects based on existing DPC++ objects
-  Accessing DPC++ objects for existing oneDNN objects


The mapping between oneDNN and DPC++objects is summarized in the tables
below.


.. container:: tablenoborder


   .. list-table:: 
      :header-rows: 1

      * -     oneDNN Objects     
        -     DPC++ Objects     
      * -     Engine     
        -     cl::sycl::device and cl::sycl::context     
      * -     Stream     
        -     cl::sycl::queue     
      * -     Memory     
        -     cl::sycl::buffer<uint8_t, 1>     




.. container:: Note


   .. rubric:: Note
      :class: NoteTipHead

   Internally, library memory objects use 1D uint8_t SYCL buffers,
   however SYCL buffers of a different type can be used to initialize
   and access memory. In this case, buffers will be reinterpreted to the
   underlying type ``cl::sycl::buffer<uint8_t, 1>``.


.. container:: tablenoborder


   .. list-table:: 
      :header-rows: 1

      * -     oneDNN Object     
        -     Constructing from DPC++ Object     
        -     Extracting DPC++ Object     
      * -     Engine     
        -     \ ``mkldnn::engine(kind, sycl_dev, sycl_ctx)``\     
        -        \ ``mkldnn::engine::get_sycl_device()``\       \ ``mkldnn::engine::get_sycl_context()``\    
      * -     Stream     
        -     \ ``mkldnn::stream(engine, sycl_queue)``\     
        -     \ ``mkldnn::stream::get_sycl_queue()``\     
      * -     Memory     
        -        \ ``mkldnn::memory(memory_desc, engine, sycl_buf)``\    
        -     \ ``mkldnn::memory::get_sycl_buffer()``\     




Building applications with oneDNN requires a compiler. The Intel oneAPI
DPC++ Compiler is available as part of the Intel oneAPI Base Toolkit and
the Intel C++ Compiler is available as part of the Intel oneAPI HPC
Toolkit.

