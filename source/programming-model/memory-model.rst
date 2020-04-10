.. _memory-model:

Memory Model
============


The memory model for oneAPI is based upon the SYCL\* memory model. It
defines how the host and devices interact with memory. It coordinates
the allocation and management of memory between the host and devices.
The memory model is an abstraction that aims to generalize across and
be adaptable to the different possible host and device
configurations. In this model, memory resides upon and is owned by
either the host or the device and is specified by declaring a memory
object. There are two different types of memory objects,
:term:`Buffers` and :term:`Images`.  Interaction of these memory
objects between the host and device is accomplished via an
:term:`Accessor`, which communicates the desired location of access,
such as host or device, and the particular mode of access, such as
read or write.

Consider a case where memory is allocated on the host through a
traditional malloc call. Once the memory is allocated on the host, a
buffer object is created, which enables the host allocated memory to be
communicated to the device. The ``buffer`` class communicates the type
and number of items of that type to be communicated to the device for
computation. Once a buffer is created on the host, the type of access
allowed on the device is communicated via an ``accessor`` object, which
specifies the type of access to the buffer. The general steps are
summarized as:

#. Instantiate a ``buffer`` or ``image`` object.

   The host or device memory for the ``buffer`` or ``image`` is
   allocated as part of the instantiation or is wrapped around
   previously allocated memory on the host.

#. Instantiate an ``accessor`` object.

   The ``accessor`` specifies the required location of access, such as
   host or device, and the particular mode of access, such as read or
   write. It represents dependencies between uses of memory objects.

The following code sample is exercising different memory objects and
accessors.


::


   #include <vector>
   #include <CL/sycl.hpp>
   namespace sycl = cl::sycl;


   #define SIZE 64


   int main() {
     std::array<int, SIZE> a, c;
     std::array<sycl::float4, SIZE> b;
     for (int i = 0; i<SIZE; ++i) {
       a[i] = i;
       b[i] = (float)-i;
        c[i] = i;
     }


     {
     sycl::range<1> a_size{SIZE};


     sycl::queue d_queue;


     sycl::buffer<int>  a_device(a.data(), a_size);
     sycl::buffer<int>  c_device(c.data(), a_size);
     sycl::image<2>  b_device(b.data(),sycl::image_channel_order::rgba,
       sycl::image_channel_type::fp32, sycl::range<2>(8, 8));


     d_queue.submit([&](sycl::handler &cgh) {
       sycl::accessor<int, 1, sycl::access::mode::discard_write,
         sycl::access::target::global_buffer> c_res(c_device, cgh);
       sycl::accessor<int, 1, sycl::access::mode::read,
         sycl::access::target::constant_buffer> a_res(a_device, cgh);
       sycl::accessor<sycl::float4, 2, sycl::access::mode::write,
         sycl::access::target::image> b_res(b_device, cgh);


       sycl::float4 init = {0.f, 0.f, 0.f, 0.f};


       cgh.parallel_for<class ex1>(a_size,[=](sycl::id<1> idx) {
         c_res[idx] = a_res[idx];
         b_res.write(sycl::int2(0,0), init);
       });


     });


     }
     return 0;
   } 


-  Lines 8 and 9 contain the host allocations of arrays ``a``, ``b``, &
   ``c``. The declaration of ``b`` is as a ``float4`` because it will be
   accessed as an image on the device side.
-  Lines 27 and 28 create an accessor for ``c_device`` that has an
   access mode of ``discard_write`` and a target of ``global_buffer``.
-  Lines 29 and 30 create an accessor for ``a_device`` that has an
   access mode of ``read`` and a target of ``constant_buffer``.
-  Lines 31 and 32 create an accessor for ``b_device`` that has an
   access mode of ``write`` and a target of ``image``.


The accessors specify where and how the kernel will access these memory
objects. The runtime is responsible for placing the memory objects in
the correct location. Therefore, the runtime may copy data between host
and device to meet the semantics of the accessor target.


Designate accessor targets to optimize the locality of access for a
particular algorithm. For example, specify that local memory should be
employed if much of the kernel access would benefit from memory that
resides closer to the processing elements.


If the kernel attempts to violate the communicated accessor by either
attempting to write on a read accessor or read on a write accessor, a
compiler diagnostic is emitted. Not all combinations of access targets
and access modes are compatible. For details, see the SYCL
Specification.

.. toctree::
   :maxdepth: 4

   
   memory-objects
   accessors
   synchronization
   unified-shared-memory
   memory-types
