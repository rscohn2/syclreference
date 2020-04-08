.. _onevpl-usage:

oneVPL Usage
============


oneVPL can use any of multiple accelerators. As a fallback it can use
purely CPU based operations; however, to use other accelerator based
hardware, the relevant drivers must be installed. Required drivers
currently include:


-  Intel® Graphics Driver (for support of Graphics Controller)


The oneVPL API is defined using a classic C++ style interface, which
allows the caller to select how the accelerator should be used at
runtime. However, oneVPL is expected to be used in programs that also
use other data parallel operations, and as such it is designed to be
used in a SYCL/DPC++ program.


The main interface between oneVPL and data parallel algorithms is the
vplMemory library. vplMemory is used for handling frames to simplify
transporting memory buffers. vplMemory provides reference counted
buffers that can be moved between differing hardware contexts for
parallel processing on demand.

