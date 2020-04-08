.. _evaluations-and-data-races:

Evaluations and Data Races
==========================


The debugger may be configured to stop all other threads in an inferior
(all-stop mode) on an event or to leave other threads running (non-stop
mode). It does not stop other inferiors. Data that is shared between
host and device, between two devices, or that is shared between threads
(when the debugger is in non-stop mode) may be modified while the
debugger is trying to access it, for example, in an expression
evaluation.


To guarantee that the debugger’s data accesses do not race with debugger
accesses, all threads that may access that data need to be stopped for
the duration of this command.


.. container:: Note


   .. rubric:: Note
      :class: NoteTipHead

   Non-stop mode is not supported on GPU devices.

