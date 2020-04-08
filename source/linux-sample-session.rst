.. _linux-sample-session:

Linux Sample Session
====================


::


   dpcpp -g -lsycl -o sample sample.cpp
   export SYCL_PROGRAM_BUILD_OPTIONS="-g -cl-opt-disable"
   gdb ./ sample


   GNU gdb (GDB) 8.3
   Copyright (C) 2019 Free Software Foundation, Inc.; (C) 2019 Intel Corp.
   License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
   This is free software: you are free to change and redistribute it.
   There is NO WARRANTY, to the extent permitted by law.
   Type "show copying" and "show warranty" for details.
   This GDB was configured as "x86_64-pc-linux-gnu".
   Type "show configuration" for configuration details.


   For information about how to find Technical Support, Product Updates,
   User Forums, FAQs, tips and tricks, and other support information, please visit:
   <http://www.gnu.org/software/gdb/bugs/>.
   For help, type "help".
   Type "apropos word" to search for commands related to "word"...
   Reading symbols from ./sample...
   (gdb) break 34
   Breakpoint 1 at 0x40da58: file sample.cpp, line 34.
   (gdb) run
   Starting program: ./sample
   [Thread debugging using libthread_db enabled]
   Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
   [New Thread 0x7ffff5127700 (LWP 1695)]


   Thread 1 "sample" hit Breakpoint -20, 0x00007ffff7fe7670 in isDebuggerActive () from libigfxdbgxchg64.so
   [New inferior 2]
   Added inferior 2 on target 1 (native)
   Intelgt auto-attach: a gdbserver will be attached using host`s inferior pid, i.e. 1695.
   [Switching to inferior 2 [<null>] (<noexec>)]
   Attached; pid = 1695
   Remote debugging using stdio
   warning: No executable has been specified and target does not support
   determining executable automatically.  Try using the "file" command.
   0x00000000ffffd020 in ?? ()
   [Switching to inferior 1 [process 1695] (sample)]
   [Switching to thread 1.1 (Thread 0x7ffff7fdbec0 (LWP 1695))]
   #0  0x00007ffff7fe7670 in isDebuggerActive () from libigfxdbgxchg64.so
   Intelgt auto-attach: a new inferior (Num: 2) has been added and an Intel GT gdbserver has been created to listen to GT debug events.


   Thread 1.1 "sample" hit Breakpoint -20, 0x00007ffff7fe7670 in isDebuggerActive () from libigfxdbgxchg64.so
   [New Thread 1073741824]
   Reading default.gtelf from remote target...
   warning: File transfers from remote targets can be slow. Use "set sysroot" to access files locally instead.
   Reading /tmp/_ZTSN2cl4sycl6kernelE.dbgelf from remote target...
   [New Thread 1073741840]
   [New Thread 1073741888]
   [New Thread 1073742080]
   [New Thread 1073742096]
   [New Thread 1073742144]
   [New Thread 1073742336]
   [New Thread 1073742352]
   [New Thread 1073742400]
   [New Thread 1073745920]
   [New Thread 1073745936]
   [New Thread 1073745984]
   [New Thread 1073746176]
   [New Thread 1073746240]
   [New Thread 1073746432]
   [New Thread 1073746496]
   [Switching to Thread 1073741824 lane 0]


   Thread 2.2:0 hit Breakpoint 1, main::$_0::operator()(cl::sycl::handler&) const::{lambda(cl::sycl::id<1>)#1}::operator()(cl::sycl::id<1>) const (this=0x0, wiID=...) at sample.cpp:34
   34              accessorOut[wiID] = in_elem + 100;
   (gdb) info inferiors
   Num  Description       Connection                               Executable
   1    process 1695        1 (native)                               sample
   * 2    Remote target     2 (remote gdbserver-gt --attach - 1695)
    (gdb) list
   29
   30            cgh.parallel_for<class kernel> (dataRange, [=] (id<1> wiID)
   31            {
   32              int dim0 = wiID[0];
   33              int in_elem = accessorIn[wiID];
   34              accessorOut[wiID] = in_elem + 100;
   35            });
   36          });
   37        }
   38
   (gdb) print in_elem
   $1 = 0
    (gdb) disassemble $pc, +36
   Dump of assembler code from 0xfffdd570 to 0xfffdd594:
   => 0x00000000fffdd570 <_ZTSN2cl4sycl6kernelE(int*, cl::sycl::range<1>, cl::sycl::range<1>, cl::sycl::id<1>, int*, cl::sycl::range<1>, cl::sycl::range<1>, cl::sycl::id<1>)+83312>:      (W)      send (16|M0)             r8:uw    r75     0xA         0x22C1103  {Breakpoint} //    wr:1h+?, rd:2, Scratch Block Read (2grfs from 0x103)
      0x00000000fffdd580 <_ZTSN2cl4sycl6kernelE(int*, cl::sycl::range<1>, cl::sycl::range<1>, cl::sycl::id<1>, int*, cl::sycl::range<1>, cl::sycl::range<1>, cl::sycl::id<1>)+83328>:               send (8|M0)              r8:d     r8:uq   0xC         0x41401FF  //    wr:2+?, rd:1, A64 Scattered Read msc:1, to 0x0
      0x00000000fffdd590 <_ZTSN2cl4sycl6kernelE(int*, cl::sycl::range<1>, cl::sycl::range<1>, cl::sycl::id<1>, int*, cl::sycl::range<1>, cl::sycl::range<1>, cl::sycl::id<1>)+83344>:               add (8|M0)               r8.0<1>:d     r8.0<8;8,1>:d     100:w
   End of assembler dump.

