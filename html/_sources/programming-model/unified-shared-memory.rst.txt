.. _unified-shared-memory:

Unified Shared Memory
=====================


An extension to the standard SYCL memory model is unified shared memory,
which enables the sharing of memory between the host and device without
explicit accessors in the source code. Instead, manage access and
enforces dependencies with explicit functions to wait on events or
signaling a ``depends_on`` relationship between events.


Another characteristic of unified shared memory is that it provides a
C++ pointer-based alternative to the buffer programming model. Unified
shared memory provides both explicit and implicit models for managing
memory. In the explicit model, programmers are responsible for
specifying when data should be copied between memory allocations on the
host and allocations on a device. In the implicit model, the underlying
runtime and device drivers are responsible for automatically migrating
memory between the host and a device. Since unified shared memory does
not rely on accessors, dependencies between operations must be specified
using events. Programmers may either explicitly wait on event objects or
use the ``depends_on`` method inside a command group to specify a list
of events that must complete before a task may begin.

