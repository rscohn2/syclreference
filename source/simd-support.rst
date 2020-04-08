.. _simd-support:

SIMD Support
============


.. container:: Note


   .. rubric:: Note
      :class: NoteTipHead

   This feature is only supported on GPU devices via GDB command line
   interface.


The debugger enables debugging of SIMD device code. Some commands, (for
example ``info register``, ``list``, or stepping commands) operate on
the underlying thread and therefore on all SIMD lanes at the same time.
Other commands (for example ``print``) operate on the currently selected
SIMD lane.


The ``info threads`` command groups similar active SIMD lanes. The
currently selected lane, however, is always shown in a separate row. If
all SIMD lanes of a thread are inactive, the whole thread is marked as
(inactive). The output appears as follows:


::


   (gdb) info threads
     Id           Target Id           Frame
     1.1          Thread <id omitted>     <frame omitted>
     1.2          Thread <id omitted>     <frame omitted>
     2.1          Thread 1610612736    (inactive)
   * 2.2:1        Thread 1073741824    <frame> at array-transform.cpp:54
     2.2:[3 5 7]  Thread 1073741824    <frame> at array-transform.cpp:54
     2.3:[1 3 5 7] Thread 1073741888    <frame> at array-transform.cpp:54
     2.4:[1 3 5 7] Thread 1073742080    <frame> at array-transform.cpp:54
     2.5:[1 3 5 7] Thread 1073742144    <frame> at array-transform.cpp:54
     2.6:[1 3 5 7] Thread 1073742336    <frame> at array-transform.cpp:54
     2.7:[1 3 5 7] Thread 1073745920    <frame> at array-transform.cpp:54
     2.8:[1 3 5 7] Thread 1073746176    <frame> at array-transform.cpp:54
     2.9:[1 3 5 7] Thread 1073746432    <frame> at array-transform.cpp:54 [...]


When a thread stops, such as after hitting a breakpoint, the debugger
chooses the SIMD lane. Use the ``thread`` command to switch to a
different lane.


.. container:: Note


   .. rubric:: Note
      :class: NoteTipHead

   SIMD lane switching is only supported via GDB command line. When
   stopped at a breakpoint in Visual Studio, GDB sets the correct SIMD
   lane, but there is not a way to change the lane using Visual Studio.


The SIMD lane is specified by an optional lane number separated by ‘:’
from the thread number. To switch to lane 2 of the current thread or to
switch to lane 5 in thread 3 in inferior 2, use:


::


   (gdb) thread :2
   (gdb) thread 2.3:5


respectively. When not specifying a SIMD lane, GDB preserves the
previously selected lane or, lacking a previously selected lane, chooses
one. When single-stepping a thread, the debugger also tries to preserve
the currently selected SIMD lane.


When using the ``thread apply`` command, the specified command is
applied to all active lanes of a thread sequentially. For example, the
step command in ``thread apply`` is issued as many times as the number
of active SIMD lanes in the thread. If ``thread 2`` has three active
lanes, ``thread apply 2 step`` results in ``thread 2`` making the step
three times.

