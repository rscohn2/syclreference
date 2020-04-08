.. _breakpoints:

Breakpoints
===========


Unless specified otherwise, breakpoints are set for all threads in all
inferiors. GDB takes care to automatically insert and remove breakpoints
into device code as new device modules are created and new device
functions are launched.


Breakpoint conditions are evaluated inside the debugger. The use of
conditional breakpoints may incur a noticeable performance overhead as
threads may frequently be stopped and resumed again to evaluate the
breakpoint condition.

