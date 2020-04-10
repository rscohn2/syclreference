.. _glossary:

Glossary
========

.. glossary::

   Accelerator
     Specialized component containing compute resources that can quickly
     execute a subset of operations. Examples include CPU, FPGA, GPU. See
     also: :term:`Device`

   Accessor
     Communicates the desired location (host, device) and mode (read,
     write) of access.

   Application Scope
     Code that executes on the host.

   Buffers
     Memory object that communicates the type and number of items of that
     type to be communicated to the device for computation.

   Command Group Scope
     Code that acts as the interface between the host and device.

   Command Queue
     Issues command groups concurrently.

   Compute Unit
     A grouping of processing elements into a ‘core’ that contains shared
     elements for use between the processing elements and with faster
     access than memory residing on other compute units on the device.

   Device
     An accelerator or specialized component containing compute resources
     that can quickly execute a subset of operations. A CPU can be
     employed as a device, but when it is, it is being employed as an
     accelerator. Examples include CPU, FPGA, GPU. See also: :term:`Accelerator`

   Device Code
     Code that executes on the device rather than the host. Device code is
     specified via lambda expression, functor, or kernel class.

   Fat Binary
     Application binary that contains device code for multiple devices.
     The binary includes both the generic code (SPIR-V representation) and
     target specific executable code.

   Fat Library
     Archive or library of object code that contains object code for
     multiple devices. The fat library includes both the generic object
     (SPIR-V representation) and target specific object code.

   Fat Object
     File that contains object code for multiple devices. The fat object
     includes both the generic object (SPIR-V representation) and target
     specific object code.

   Host
     A CPU-based system (computer) that executes the primary portion of a
     program, specifically the application scope and command group scope.

   Host Code
     Code that is compiled by the host compiler and executes on the host
     rather than the device.

   Images
     Formatted opaque memory object that is accessed via built-in
     function. Typically pertains to pictures comprised of pixels stored
     in format like RGB.

   Kernel Scope
     Code that executes on the device.

   ND-range
     Short for N-Dimensional Range, a group of kernel instances, or work
     item, across one, two, or three dimensions.

   Processing Element
     Individual engine for computation that makes up a compute unit.

   Single Source
     Code in the same file that can execute on a host and accelerator(s).

   SPIR-V
     Binary intermediate language for representing graphical-shader stages
     and compute kernels.

   Sub-group
     Sub-groups are an Intel extension.

   Work-group
     Collection of work-items that execute on a compute unit.

   Work-item
     Basic unit of computation in the oneAPI programming model. It is
     associated with a kernel which executes on the processing element.
