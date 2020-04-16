.. _buffer:

Buffer
======

A DPC++ ``buffer`` encapsulates a 1-, 2-, or 3-dimensional array that is
shared between host and devices. Creating a buffer requires the number
of dimensions of the array as well as the type of the underlying data.


The class contains multiple constructors with different combinations of
ranges, allocators, and property lists.


-  The memory employed by the buffer is already existing in host memory.
   In this case, a pointer to the memory is passed to the constructor.
-  Temporary memory is allocated for the buffer by employing the
   constructors that do not include a ``hostData`` parameter.
-  An allocator object is passed, which provides an alternative memory
   allocator to be used for allocating the temporary memory for the
   buffer. Special arguments, termed properties, can be provided to the
   constructor for cases where host memory use is desired
   (``use_host_ptr``), use of the mutex_class is desired
   (``use_mutex``), and single context only (``context_bound``) is
   desired.


Once a buffer is allocated, query member functions to learn more. These
member functions include:


-  ``get_range`` – obtain the range object associated with the buffer
-  ``get_count`` – obtain the number of elements in the buffer
-  ``get_size`` – obtain the size of the buffer in bytes
-  ``get_allocator`` – obtain the allocator that was provided in
   creating the buffer
-  ``is_sub_buffer`` – return if buffer is a sub-buffer or not

.. include:: buffer.inc.rst
