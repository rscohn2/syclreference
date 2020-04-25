.. _synchronization:

Synchronization
===============


It is possible to access a ``buffer`` without employing an ``accessor``,
however it should be the rare case. To do so safely, a ``mutex_class``
should be passed when a ``buffer`` is instantiated. For further details
on this method, see the SYCL Specification.


.. container:: section
   :name: GUID-4EC23CFD-8346-4EC6-8DB3-8588834586BB


   .. rubric:: Access Targets
      :class: sectiontitle

   .. container:: tablenoborder


      .. list-table:: 
         :header-rows: 1

         * -     Target     
           -     Description     
         * -     \ ``host_buffer``\     
           -     Access the buffer on the host.     
         * -     \ ``global_buffer``\     
           -     Access the buffer through global memory on the device.          
         * -     \ ``constant_buffer``\     
           -     Access the buffer from constant memory on the device.       This may enable some optimization.    
         * -     \ ``local``\     
           -     Access the buffer from local memory on the device.          
         * -     \ ``image``\     
           -     Access the image     
         * -     \ ``image_array``\     
           -     Access an array of images     
         * -     \ ``host_image``\     
           -     Access the image on the host.     




.. container:: section
   :name: GUID-3387EC6B-5800-4989-85CC-A5B7A7909E25


   .. rubric:: Access Modes
      :class: sectiontitle

   .. container:: tablenoborder


      .. list-table:: 
         :header-rows: 1

         * -     Memory Access Mode     
           -     Description     
         * -     \ ``read``\     
           -     Read-only     
         * -     \ ``write``\     
           -     Write-only     
         * -     \ ``read_write``\     
           -     Read and write     
         * -     \ ``discard_write``\     
           -     Write-only access. Previous value is discarded          
         * -     \ ``discard_read_write``\     
           -     Read and write. Previous value is discarded     
         * -     \ ``atomic``\     
           -     Provide atomic, one at a time, access.     



