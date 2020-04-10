.. _glossary:

Glossary
========


.. container:: section
   :name: GUID-EC4E9EC9-D6E1-4335-BB37-A416B4CE2E1B


   .. rubric:: Accelerator
      :class: sectiontitle

   Specialized component containing compute resources that can quickly
   execute a subset of operations. Examples include CPU, FPGA, GPU.


   See also: Device


.. container:: section
   :name: GUID-712A6F1D-C72F-4BA5-BC1A-22A0B37928F0


   .. rubric:: Accessor
      :class: sectiontitle

   Communicates the desired location (host, device) and mode (read,
   write) of access.


.. container:: section
   :name: GUID-9AF2F25B-9267-4D5D-9D1E-0980899871D3


   .. rubric:: Application Scope
      :class: sectiontitle

   Code that executes on the host.


.. container:: section
   :name: GUID-9FAA1711-7BD8-4825-8CDD-DDE886DD7676


   .. rubric:: Buffers
      :class: sectiontitle

   Memory object that communicates the type and number of items of that
   type to be communicated to the device for computation.


.. container:: section
   :name: GUID-8988FB87-72DD-457A-BC47-6A7533E5E40D


   .. rubric:: Command Group Scope
      :class: sectiontitle

   Code that acts as the interface between the host and device.


.. container:: section
   :name: GUID-82027CEE-2635-4296-BAE6-7991071C79C1


   .. rubric:: Command Queue
      :class: sectiontitle

   Issues command groups concurrently.


.. container:: section
   :name: GUID-7A7B7A91-9296-4AE7-995A-B582D02926B8


   .. rubric:: Compute Unit
      :class: sectiontitle

   A grouping of processing elements into a ‘core’ that contains shared
   elements for use between the processing elements and with faster
   access than memory residing on other compute units on the device.


.. container:: section
   :name: GUID-7086F0B5-C415-4092-9456-F2F656FAF56B


   .. rubric:: Device
      :class: sectiontitle

   An accelerator or specialized component containing compute resources
   that can quickly execute a subset of operations. A CPU can be
   employed as a device, but when it is, it is being employed as an
   accelerator. Examples include CPU, FPGA, GPU.


   See also: Accelerator


.. container:: section
   :name: GUID-5850BA45-8186-4247-9840-71CC9295E94D


   .. rubric:: Device Code
      :class: sectiontitle

   Code that executes on the device rather than the host. Device code is
   specified via lambda expression, functor, or kernel class.


.. container:: section
   :name: GUID-73CC02FB-EEB6-42FC-A8A6-C1E0D50F7103


   .. rubric:: Fat Binary
      :class: sectiontitle

   Application binary that contains device code for multiple devices.
   The binary includes both the generic code (SPIR-V representation) and
   target specific executable code.


.. container:: section
   :name: GUID-5ACBBE45-33F2-4120-9C0E-5FA9D24BEF57


   .. rubric:: Fat Library
      :class: sectiontitle

   Archive or library of object code that contains object code for
   multiple devices. The fat library includes both the generic object
   (SPIR-V representation) and target specific object code.


.. container:: section
   :name: GUID-1555A054-E7A0-422F-A660-241DB93F68E9


   .. rubric:: Fat Object
      :class: sectiontitle

   File that contains object code for multiple devices. The fat object
   includes both the generic object (SPIR-V representation) and target
   specific object code.


.. container:: section
   :name: GUID-8607E98A-D86E-4275-9B0E-5A295F5A63F1


   .. rubric:: Host
      :class: sectiontitle

   A CPU-based system (computer) that executes the primary portion of a
   program, specifically the application scope and command group scope.


.. container:: section
   :name: GUID-EBF66CBC-66FE-440D-AD1D-74A2EAF8DD48


   .. rubric:: Host Code
      :class: sectiontitle

   Code that is compiled by the host compiler and executes on the host
   rather than the device.


.. container:: section
   :name: GUID-A8E210CA-4E55-4A95-AE6F-2122DC9BBDD9


   .. rubric:: Images
      :class: sectiontitle

   Formatted opaque memory object that is accessed via built-in
   function. Typically pertains to pictures comprised of pixels stored
   in format like RGB.


.. container:: section
   :name: GUID-ACCEE155-6AE2-4B91-AFE1-DAAC8425E9BB


   .. rubric:: Kernel Scope
      :class: sectiontitle

   Code that executes on the device.


.. container:: section
   :name: GUID-334B8798-0849-42CB-8E1D-2C89F99BB1D2


   .. rubric:: ND-range
      :class: sectiontitle

   Short for N-Dimensional Range, a group of kernel instances, or work
   item, across one, two, or three dimensions.


.. container:: section
   :name: GUID-0D47356B-5EB2-4B7E-9815-E7251D31A0FF


   .. rubric:: Processing Element
      :class: sectiontitle

   Individual engine for computation that makes up a compute unit.


.. container:: section
   :name: GUID-7BA433CB-2393-48A6-A1FC-9FD653BE0EBD


   .. rubric:: Single Source
      :class: sectiontitle

   Code in the same file that can execute on a host and accelerator(s).


.. container:: section
   :name: GUID-C79205F1-0915-4E1C-A5B1-858867D2B937


   .. rubric:: SPIR-V
      :class: sectiontitle

   Binary intermediate language for representing graphical-shader stages
   and compute kernels.


.. container:: section
   :name: GUID-FD58BBE4-01DC-4552-B4F7-78E34755EA3E


   .. rubric:: Sub-groups
      :class: sectiontitle

   Sub-groups are an Intel extension.


.. container:: section
   :name: GUID-3B480D18-BCDA-4513-B905-DAF05B652EF5


   .. rubric:: Work-groups
      :class: sectiontitle

   Collection of work-items that execute on a compute unit.


.. container:: section
   :name: GUID-1407D2E3-3B05-4FAB-B520-C307EE31B87B


   .. rubric:: Work-item
      :class: sectiontitle

   Basic unit of computation in the oneAPI programming model. It is
   associated with a kernel which executes on the processing element.

