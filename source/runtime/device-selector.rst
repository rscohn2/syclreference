.. _device-selector:

Device Selector
===============


The DPC++ ``device_selector`` class enables the runtime selection of a
particular device to execute kernels based upon user-provided
heuristics. Construction is either via a zero argument constructor or by
providing a reference to another ``device_selector`` object. An instance
of a ``device_selector`` can also be assigned to another instance.


The following code sample shows use of the standard ``device_selectors``
and a derived ``device_selector`` that employs a device selector
heuristic. In the example, the selected device prioritizes a CPU device
because the integer rating returned is higher than if the device is a
GPU or other accelerator.


::


   #include <CL/sycl.hpp>
   using namespace cl::sycl;


   class my_device_selector : public device_selector {
   public:
     int operator()(const device &dev) const override{
       int rating = 0;
       if (dev.is_gpu()) rating = 1;
       else if (dev.is_cpu()) rating = 2;
       return rating; 
   };
   };
   int main() {


     default_selector d_selector;
     queue Queue(d_selector);


     cpu_selector d_selector2;
     queue Queue2(d_selector2);


     std::cout << "Executing on "
       << Queue.get_device().get_info<info::device::name>()
       << std::endl;
     std::cout << "Executing on "
       << Queue2.get_device().get_info<info::device::name>()
       << std::endl;


     device device1 = Queue.get_device() ;
     device device2 = Queue2.get_device() ;


     my_device_selector h_selector;
     queue Queue3(h_selector);


     std::cout << "Executing on "
       << Queue3.get_device().get_info<info::device::name>()
       << std::endl;


     return 0;
   } 


A brief description of the key lines in the sample code is as follows:


-  Lines 15-16 - use the ``default_selector`` to select a device to
   initialize a command queue


   |image0|


-  Lines 18-19 - use the ``cpu_selector`` to select a device to
   initialize a command queue


   |image1|


-  Lines 4-11 and lines 31-32 - use a derived ``device_selector`` and a
   selection heuristic


   |image2|


.. |image0| image:: /image/GUID-59C34DBD-2FF9-4558-B6D0-EC8545FC2147-low.png
   :width: 622px
   :height: 40px
.. |image1| image:: /image/GUID-BD535AEF-87BC-4A7C-94AA-00BD6C00F26D-low.png
   :width: 622px
   :height: 40px
.. |image2| image:: /image/GUID-72713C3C-FC00-471C-A822-3CEB1ABB330D-low.png
   :width: 622px
   :height: 262px

