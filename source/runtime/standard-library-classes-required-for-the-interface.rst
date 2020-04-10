.. _standard-library-classes-required-for-the-interface:

Standard Library Classes Required for the Interface
===================================================


Programming for oneAPI employs a variety of vectors, strings, functions,
and pointer objects common in STL programming.


The SYCL specification documents a facility to enable vendors to provide
custom optimized implementations. Implementations require aliases for
several STL interfaces. These are summarized as follows:


-  ``vector_class`` – ``std::vector<>``
-  ``string_class`` – ``std::string``
-  ``function_class`` – ``std::function<>``
-  ``mutex_class`` – ``std::mutex``
-  ``shared_ptr_class`` – ``std::shared_ptr<>``
-  ``unique_ptr_class`` – ``std::unique_ptr<>``
-  ``weak_ptr_class`` – ``std::weak_ptr<>``
-  ``hash_class`` – ``std::hash``
-  ``exception_ptr_class`` – ``std::exception_ptr``

