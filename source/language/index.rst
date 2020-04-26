==========
 Language
==========

SYCL programs are C++ programs. No extensions are added to the language.

.. todo:: C++ version mininum


Keywords
========

SYCL does not add any keywords to the C++ language.

Preprocessor Directives and Macros
==================================


Standard C++ preprocessing directives and macros are supported by the
compiler. In addition, the SYCL Specification defines the SYCL specific
preprocessor directives and macros.


The following preprocessor macros are supported by the compiler.


==============================  =================  ========
Macro                           Value              Description
==============================  =================  ========
``SYCL_DUMP_IMAGES``            |true| or |false|  Instructs the runtime to dump the device image       
``SYCL_USE_KERNEL_SPV``         <device binary>    Employ device binary to fulfill kernel launch request       
``SYCL_PROGRAM_BUILD_OPTIONS``  <options>          Used to pass additional options for device program building.    
==============================  =================  ========


Standard Library Classes Required for the Interface
===================================================


The SYCL specification documents a facility to enable vendors to provide
custom optimized implementations. Implementations require aliases for
several STL interfaces. These are summarized as follows:

.. todo:: add STL interfaces
