.. _fpga-device-selection-in-the-host-code:

FPGA Device Selection in the Host Code
======================================


To explicitly set an FPGA emulator device or FPGA hardware device,
include the following header file in the host code:


::


   CL/sycl/intel/fpga_extensions.hpp


Declare the device selector type as one of the following:


-  


   .. container::
      :name: LI_E3D355F88EEE4630B8BFF1CCEF12BCDC


      For the FPGA emulator, use the following:


      ::


         intel::fpga_emulator_selector device_selector;


-  


   .. container::
      :name: LI_87D05053230240D5B40A1C1E5CE04DC0


      For the FPGA hardware device, use the following:


      ::


         intel::fpga_selector device_selector;


Consider the following sample code:


::


   #include <CL/sycl/intel/fpga_extensions.hpp>
   using namespace cl::sycl;
   ...
       #ifdef FPGA_EMULATOR
       intel::fpga_emulator_selector device_selector;
       #else
       intel::fpga_selector device_selector;
       #endif
       queue deviceQueue(device_selector);
   ...


.. container:: Note


   .. rubric:: Note
      :class: NoteTipHead

   -  If runtime cannot find ``fpga_emulator_selector`` or
      ``fpga_selector`` in the host code, an error message is displayed.
   -  To enable debugging of kernel code, optimizations are disabled by
      default for the FPGA emulator device. This can lead to suboptimal
      execution speed when emulating kernel code. Pass the ``-Xsg0``
      compiler option to disable debugging and enable optimizations
      leading to faster emulator execution.

