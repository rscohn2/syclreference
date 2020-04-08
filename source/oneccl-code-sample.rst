.. _oneccl-code-sample:

oneCCL Code Sample
==================


oneCCL sample code, such as ``ccl_sample.cpp``, is available from the
Intel oneAPI Base Toolkit GitHub repository
https://github.com/intel/BaseKit-code-samples or from the Intel oneAPI
DL Framework Developer Toolkit GitHub repository
https://github.com/intel/DLFDKit-code-samples.


Use the following command to compile the code:


::


   dpcpp -I$CCL_ROOT/include -L$CCL_ROOT/lib/ -lccl ./ccl_sample.cpp –o ccl_sample

