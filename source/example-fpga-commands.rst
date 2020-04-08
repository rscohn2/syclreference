.. _example-fpga-commands:

Example FPGA Commands
=====================


Generating an emulation image:


::


   dpcpp -fintelfpga <source_file>.cpp 


Generating a static report:


::


   dpcpp -fintelfpga <source_file>.cpp -fsycl-link -Xshardware


Generating an FPGA hardware image (Linux only):


::


   dpcpp -fintelfpga <source_file>.cpp -c -o <file_name>.o 


::


   dpcpp -fintelfpga <file_name>.o -Xshardware


Running an FPGA image on the Intel® Programmable Acceleration Card (PAC)
with Intel® Arria® 10 GX FPGA:


::


   ./<fpga_hw_image_file_name>


For more information about command syntax, see `FPGA Offline
Compilation <offline-compilation-for-fpga.html>`__.

