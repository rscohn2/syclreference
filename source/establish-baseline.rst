.. _establish-baseline:

Establish Baseline
==================


Establish a baseline that includes a metric such as elapsed time, time
in a compute kernel, or floating point operations per second that can be
used to measure the performance improvement and that provides a means to
verify the correctness of the results.


A simple method is to employ the chrono library routines in C++, placing
timer calls before and after the workload executes.

