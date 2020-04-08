.. _standard-intel-oneapi-dpcpp-compiler-options:

Standard Intel oneAPI DPC++ Compiler Options
============================================


The following standard options are available. The options are not
separated by host only and device only compilation.


.. container:: tablenoborder


   .. list-table:: 
      :header-rows: 1

      * -     Option     
        -     Description     
      * -  ``-fsycl-targets=T1,...,Tn`` 
        -     Makes Intel oneAPI DPC++ Compiler generate code for    devices represented by comma-separated list of triples. Some triples   can represent offline compilation.    
      * -  ``-foffload-static-lib=<lib>`` 
        -     Link with fat static library.       Link with    ``<lib>``, which is a fat static archive containing fat objects that   correspond to the target device. When linking, ``clang`` will extract   the device code from the objects contained in the library and link it   with other device objects coming from the individual fat objects   passed on the command line.    
      * -  ``-fsycl-device-only`` 
        -     Generate a device only binary.     
      * -  ``-Xsycl-target-backend=T "options"`` 
        -     Specifies options that are passed to the backend in the    device compilation tool chain for target T.    
      * -  ``-fsycl-link`` 
        -     Perform a partial link of device binaries. This is then    wrapped by the offload wrapper, allowing the device binaries to be   linked by the host compiler/linker.    
      * -  ``-fsycl-link=<value>`` 
        -     Perform a partial link of device binaries, to be used    with FPGA. The <value> can be of the following:    
      * -  ``-fintelfpga`` 
        -     Option specific to performing ahead of time compilation    with FPGA. Functionally equivalent to using   ``-fsycltargets=spir64-unknown-<os>-sycldevice``, adding compiling   with dependency and debug information enabled.    
      * -  ``-Xs "options"-Xs<arg>`` 
        -     Similar to ``-Xsycl-target-backend``, passing "options"    to the backend tool. The ``-Xs<arg>`` variant works as follows:      



