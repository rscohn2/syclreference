.. _context:

Context
=======


A context encapsulates a platform and a collection of devices. For more
information, see :ref:`platform-model`.


The class contains multiple constructors enabling creation from
platforms, devices, and context as arguments.


The class contains member functions for querying information about the
instantiated context:


-  ``get_platform()`` – obtain the platform associated with the context
-  ``get_device()`` – obtain the device associated with the context
-  ``is_host()`` – return true if context is a host context

.. include:: context.inc.rst
