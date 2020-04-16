.. _device-event:

Device Event
============


The DPC++ ``device_event`` class encapsulates wait objects within
kernels. The ``device_event`` objects are used to coordinate
asynchronous operations in kernels. The constructor and its arguments
are unspecified and implementation dependent. The wait member function
causes execution to stop until the operation associated with the wait is
complete.

.. include:: device-event.inc.rst
