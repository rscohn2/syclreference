.. _image:

Image
=====


A DPC++ ``image`` encapsulates a 1-, 2-, or 3-dimensional set of data
shared between host and devices. Creating an image requires the number
of dimensions of the array as well as the order and type of the
underlying data.


The class contains multiple constructors with different combinations of
orders, types, ranges, allocators, and property lists.


-  The memory employed by the image is already existing host memory. In
   this case, a pointer to the memory is passed to the constructor.
-  Temporary memory is allocated for the image by employing the
   constructors that do not include a ``hostPointer`` parameter.
-  An allocator object is passed, which provides an alternative memory
   allocator to be used for allocating the temporary memory for the
   buffer.
-  When host memory use is desired (``use_host_ptr``), use of the
   mutex_class is desired (``use_mutex``), and if a single context only
   (``context_bound``) is desired, special arguments, termed properties,
   are provided to the constructor.


Once a buffer is allocated, query member functions to learn more. These
member functions include


-  ``get_range`` – obtain the range object associated with the image
-  ``get_pitch`` - obtain the range associated with a one-dimensional
   image
-  ``get_count`` – obtain the number of elements in the image
-  ``get_size`` – obtain the size of the image (in bytes)
-  ``get_allocator`` – obtain the allocator that was provided in
   creating the image
-  ``get_access`` – obtain an accessor to the image with the specified
   access mode and target

