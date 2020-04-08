.. _migrating-between-cpu-gpu-and-fpga:

Migrating Between CPU, GPU, and FPGA
====================================


In DPC++, a platform consists of a host device connected to zero or more
devices, such as CPU, GPU, FPGA, or other kinds of accelerators and
processors.


When a platform has multiple devices, design the application to offload
some or most of the work to the devices. There are different ways to
distribute work across devices in the oneAPI programming model:


#. Initialize device selector – SYCL provides a set of classes called
   selectors that allow manual selection of devices in the platform or
   let oneAPI runtime heuristics choose a default device based on the
   compute power available on the devices.


#. Splitting datasets – With a highly parallel application with no data
   dependency, explicitly divide the datasets to employ different
   devices. The following code sample is an example of dispatching
   workloads across multiple devices. Use ``dpcpp snippet.cpp`` to
   compile the code.


   ::


      int main() {
         int data[1024];
         for (int i = 0; i < 1024; i++)
             data[i] = i;
             try {
                 cpu_selector cpuSelector;
                 queue cpuQueue(cpuSelector);
                 gpu_selector gpuSelector;
                 queue gpuQueue(gpuSelector);
                 buffer<int, 1> buf(data, range<1>(1024));
                 cpuQueue.submit([&](handler& cgh) {
                     auto ptr = 
                     buf.get_access<access::mode::read_write>(cgh);
                     cgh.parallel_for<class divide>(range<1>(512), 
                         [=](id<1> index) {
                         ptr[index] -= 1;
                     });
                 });
                 gpuQueue.submit([&](handler& cgh1) {
                     auto ptr = 
                     buf.get_access<access::mode::read_write>(cgh1);
                     cgh1.parallel_for<class offset1>(range<1>(1024), 
                         id<1>(512), [=](id<1> index) {
                             ptr[index] += 1;
                     });
                 });
                 cpuQueue.wait();
                 gpuQueue.wait();
            }
            catch (exception const& e) {
                std::cout << 
                "SYCL exception caught: " << e.what() << '\n';
                return 2;
            }
            return 0;
      }


#. Target multiple kernels across devices – If the application has scope
   for parallelization on multiple independent kernels, employ different
   queues to target devices. The list of SYCL supported platforms can be
   obtained with the list of devices for each platform by calling
   ``get_platforms()`` and ``platform.get_devices()`` respectively. Once
   all the devices are identified, construct a queue per device and
   dispatch different kernels to different queues. The following code
   sample represents dispatching a kernel on multiple SYCL devices.


   ::


      #include <stdio.h>
      #include <vector>
      #include <CL/sycl.hpp>
      using namespace cl::sycl;
      using namespace std;
      int main()
      {
             size_t N = 1024;
             vector<float> a(N, 10.0);
             vector<float> b(N, 10.0);
             vector<float> c_add(N, 0.0);
             vector<float> c_mul(N, 0.0);
         {
             buffer<float, 1> abuffer(a.data(), range<1>(N), 
               { property::buffer::use_host_ptr() });
             buffer<float, 1> bbuffer(b.data(), range<1>(N), 
               { property::buffer::use_host_ptr() });
             buffer<float, 1> c_addbuffer(c_add.data(), range<1>(N), 
              { property::buffer::use_host_ptr() });
             buffer<float, 1> c_mulbuffer(c_mul.data(), range<1>(N), 
               { property::buffer::use_host_ptr() });
          try {
                   gpu_selector gpuSelector;
                   auto queue = cl::sycl::queue(gpuSelector);
                   queue.submit([&](cl::sycl::handler& cgh) {
                          auto a_acc = abuffer.template
                            get_access<access::mode::read>(cgh);
                          auto b_acc = bbuffer.template 
                            get_access<access::mode::read>(cgh);
                          auto c_acc_add = c_addbuffer.template  
                            get_access<access::mode::write>(cgh);
                          cgh.parallel_for<class VectorAdd>
                           (range<1>(N), [=](id<1> it) {
                               //int i = it.get_global();
                                   c_acc_add[it] = a_acc[it] + b_acc[it];
                                        });
                                 });
                   cpu_selector cpuSelector;
                   auto queue1 = cl::sycl::queue(cpuSelector);
                   queue1.submit([&](cl::sycl::handler& cgh) {
                          auto a_acc = abuffer.template  
                              get_access<access::mode::read>(cgh);
                          auto b_acc = bbuffer.template  
                              get_access<access::mode::read>(cgh);
                          auto c_acc_mul = c_mulbuffer.template 
                              get_access<access::mode::write>(cgh);
                          cgh.parallel_for<class VectorMul>
                           (range<1>(N), [=](id<1> it) {
                                c_acc_mul[it] = a_acc[it] * b_acc[it];
                                        });
                                 });
                    }
                    catch (cl::sycl::exception e) {
      /* In the case of an exception being throw, print the
      error message and
                           * return 1. */
                           std::cout << e.what();
                           return 1;
                    }
             }
             for (int i = 0; i < 8; i++) {
                    std::cout << c_add[i] << std::endl;
                    std::cout << c_mul[i] << std::endl;
             }
             return 0;
      }

