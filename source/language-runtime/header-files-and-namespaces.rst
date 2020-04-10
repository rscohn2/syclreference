.. _header-files-and-namespaces:

Header Files and Namespaces
===========================


The compiler header files are in a subdirectory of the Intel oneAPI
DPC++ Compiler installation. For example:


::


   <install_dir>/compiler/latest/<os>/lib/


where ``<install_dir>`` is the directory where the Intel oneAPI Base
Toolkit is installed and ``<os>`` is either ``windows`` or ``linux``.


Within the header files, the names correspond with the primary DPC++
classes for implementing the language.


The Intel-specific extensions to SYCL\* that DPC++ is based upon are
located in the following location:


On Windows:
<install_dir>\compiler\latest\windows\lib\clang\10.0.0\include\CL\sycl\intel


On Linux:
<install_dir>/compiler/latest/linux/compiler/lib/clang/10.0.0/include/CL/sycl/intel

