.. _dpcpp-classes-class-templates-and-defines:

DPC++ Classes, Class Templates, and Defines
===========================================


The following table summarizes the DPC++ classes, class templates, and
defines of the programming model. In addition, the specific include
file for the definition of these items are mentioned along with a
description of each.


.. container:: tablenoborder


   .. list-table:: 
      :header-rows: 1

      * -     Class     
        -     Include file(s)     
        -     Description     
      * -        \ `Accessor <accessor.html>`__\    
        -     accessor.hpp, accessor2.hpp     
        -     Enables and specifies access to buffers, images, and    device local memory    
      * -        \ `Atomic <atomic.html>`__\    
        -     atomic.hpp     
        -     Operations and member functions to guarantee synchronized    access to data values    
      * -        \ `Buffer <buffer.html>`__\    
        -     buffer.hpp     
        -     Encapsulates memory for communication between host and    device(s)    
      * -     \ `Built-in    functions <built-in-types-&amp-functions.html>`__\    
        -     builtin.hpp     
        -     Math functions that can be employed efficiently across    host and devices    
      * -     \ `Command Group    Handler <command-group-handler.html>`__\    
        -     handler.hpp, handler2.hpp     
        -     Encapsulates commands executed in command group scope       
      * -        \ `Context <context.html>`__\    
        -     context.hpp     
        -     Encapsulates a platform and collection of devices       
      * -        \ `Device <device.html>`__\    
        -     device.hpp     
        -     Encapsulates attributes, features, and capabilities of an    accelerator    
      * -     \ `Device    event <device-event.html>`__\    
        -     device_event.hpp     
        -     Encapsulates functions used to wait for other operations       
      * -     \ `Device    selector <device-selector.html>`__\    
        -     device_selector.hpp     
        -     Enables selection of a device for execution of command    groups    
      * -        \ `Event <event.html>`__\    
        -     event.hpp     
        -     Encapsulates objects used to coordinate memory transfers    and kernel execution    
      * -        \ `Exception <exception.html>`__\    
        -     exception.hpp     
        -     Notifications used by the program to handle outlier    occurrences such as error conditions.    
      * -        \ `Group <group.html>`__\    
        -     group.hpp     
        -     Template class encapsulates work-groups     
      * -        \ `Id <id.html>`__\    
        -     id.hpp     
        -     Encapsulates a vector of dimensions for accessing    individual items in a global or local range    
      * -        \ `Image <image.html>`__\    
        -     image.hpp     
        -     Encapsulates memory for communication between host and    device(s) in an optimized format    
      * -        \ `Item <item.html>`__\    
        -     item.hpp     
        -     Encapsulates a function object executing within a range       
      * -        \ `Kernel <kernel.html>`__\    
        -     kernel.hpp     
        -     Encapsulates a kernel object which is the function that    executes on the device    
      * -        \ `Multi-pointer <multi-pointer.html>`__\    
        -     multi_ptr.hpp     
        -     Abstraction around low-level pointer to enable pointer    like access across host and devices    
      * -        \ `Nd_item <nd_item.html>`__\    
        -     nd_item.hpp     
        -     Encapsulates each work-item in an ND-range     
      * -        \ `Nd_range <nd_range.html>`__\    
        -     nd_range.hpp     
        -     Encapsulates the index space for 1-,2-, or 3- dimensional    data    
      * -        \ `Platform <platform.html>`__\    
        -     platform.hpp     
        -     Encapsulates the oneAPI host and devices on the system       
      * -        \ `Program <program.html>`__\    
        -     program.hpp     
        -     Encompasses a program that employs the oneAPI programming    model, communicating if source code is compiled or linked    
      * -     \ `Property    Interface <property-interface.html>`__\    
        -     property_list.hpp     
        -     Enables passing extra parameters to buffer, image, and    device classes    
      * -        \ `Queue <queue.html>`__\    
        -     queue.hpp     
        -     Object and methods for executing command queues     
      * -        \ `Range <range.html>`__\    
        -     range.hpp     
        -     Encapsulates the iteration domain of a work-group in 1-,    2-, or 3-dimensions    
      * -     \ `Standard library    classes <standard-library-classes-required-for-the-interface.html>`__\    
        -     stl.hpp     
        -     Interfaces for C++ standard classes     
      * -        \ `Stream <stream.html>`__\    
        -    
        -     Methods for outputting oneAPI data types     
      * -     \ `Vec and Swizzled    Vec <vec-and-swizzled-vec.html>`__\    
        -     types.hpp     
        -     Vec class representing a vector of data elements.    Swizzled vec class enables selection of combinations of elements in a   vec object.    
      * -        \ `Version <version.html>`__\    
        -     version.hpp     
        -     Defines compiler version     




The following sections provide further details on these items. These
sections do not provide the exhaustive details found in the SYCL
Specification. Instead, these sections provide:


-  A summary that includes a description and the purpose
-  Comments on the different constructors, if applicable
-  Member function information, if applicable
-  Special cases to consider with the DPC++ implementation compared to
   the SYCL Specification


For further details on SYCL, see the `SYCL
Specification <https://www.khronos.org/registry/SYCL/specs/sycl-1.2.1.pdf>`__.

.. toctree::
   :maxdepth: 4

   
   accessor
   atomic
   buffer
   command-group-handler
   context
   device
   device-event
   device-selector
   event
   exception
   group
   id
   image
   item
   kernel
   multi-pointer
   nd_item
   nd_range
   platform
   program
   queue
   range
   stream
   vec-and-swizzled-vec
   built-in-types-&amp-functions
   property-interface
   standard-library-classes-required-for-the-interface
   version
