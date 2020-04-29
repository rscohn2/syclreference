=====================
Programming Interface
=====================

For further details on SYCL, see the `SYCL
Specification <https://www.khronos.org/registry/SYCL/specs/sycl-1.2.1.pdf>`__.

Header File
===========

A single header file must be included::

  #include "sycl.hpp"

Namespaces
==========

Unless otherwise noted, all symbols should be prefixed with the
``cl::sycl`` namespace. ``buffer`` is ``cl::sycl::buffer``, and
``info::device::name`` is ``cl::sycl::info::device::name``.


Interfaces
==========

.. toctree::

   runtime/index
   data/index
