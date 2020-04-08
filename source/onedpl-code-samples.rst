.. _onedpl-code-samples:

oneDPL Code Samples
===================


Parallel STL for DPC++ extends the standard C++17 parallel algorithms
with


-  DPC++ execution policy
-  ``dpstd::begin``, ``dpstd::end`` functions


To compile the code samples:


#. Set the environment variables.


#. Run the following command:


   ::


      dpcpp test.cpp -o test


.. container:: section
   :name: GUID-9C357EBB-4959-4038-B96F-F1063D935F83


   .. rubric:: DPC++ Execution Policy
      :class: sectiontitle

   The DPC++ execution policy specifies where and how a Parallel STL
   algorithm runs. It encapsulates a standard C++ 17 execution policy by
   inheritance (currently, only ``parallel_unsequenced_policy`` is
   supported), a SYCL device or queue, and an optional kernel name.


   To set up the policy:


   #. Add ``#include <dpstd/execution>``.


   #. Create a policy object providing a standard policy type and a
      special class (a unique kernel name; it is optional if the host
      code to invoke the kernel is compiled with the Intel oneAPI DPC++
      Compiler) as template arguments and one of the following
      constructor arguments:


      -  A SYCL queue
      -  A SYCL device
      -  A SYCL device selector
      -  An existing policy providing a new kernel name


      ::


          using namespace dpstd::execution;
          auto policy_a = sycl_policy<parallel_unsequenced_policy, class PolicyA> {cl::sycl::queue{ }};
          std::for_each(policy_a, ...);
          auto policy_b = sycl_policy<parallel_unsequenced_policy, class PolicyB> {cl::sycl::device{cl::sycl::gpu_selector{}}};
          std::for_each(policy_b, ...);
          auto policy_c = sycl_policy<parallel_unsequenced_policy, class PolicyC> {cl::sycl::default_selector{}};
          std::for_each(policy_c, ...);
          auto policy_d = make_sycl_policy<class PolicyD>(sycl); // sycl is predefined object of sycl_policy class using default kernel name
          std::for_each(policy_d, ...); 
          auto policy_e = make_sycl_policy<class PolicyE>(cl::sycl::queue{}); 
          std::for_each(policy_e, ...);


.. container:: section
   :name: GUID-4140AA0F-C5C0-4D9C-A53C-8A75BA09AD83


   .. rubric:: dpstd::begin, dpstd::end Functions
      :class: sectiontitle

   ``dpstd::begin``, ``dpstd::end`` are special helper functions that
   allow passing of SYCL buffers to Parallel STL algorithms. These
   functions accept a SYCL buffer and return an object of an unspecified
   type that satisfies the following requirements:


   #. Is CopyConstructible, CopyAssignable, and comparable with
      operators == and !=
   #. The following expressions are valid: a + n, a - n, –a - b, where a
      and b are objects of the type, and n is an integer value
   #. Contains ``get_buffer()`` method that returns the SYCL buffer
      passed to ``dpstd::begin``, ``dpstd::end`` functions.


   To use the functions, add ``#include <dpstd/iterators.h>`` to your
   code.


   The following example shows how to process a SYCL buffer with a
   Parallel STL algorithm:


   ::


      #include <CL/sycl.hpp>
      #include <dpstd/execution>
      #include <dpstd/algorithm>
      #include <dpstd/iterators.h>
      int main(){
          cl::sycl::queue q;
          cl::sycl::buffer<int> buf { 1000 };
          auto buf_begin = dpstd::begin(buf);
          auto buf_end   = dpstd::end(buf);
          auto policy = dpstd::execution::make_sycl_policy<class fill>(q);
          std::fill(policy, buf_begin, buf_end, 42);
          return 0;
        }


   .. container:: Note


      .. rubric:: Note
         :class: NoteTipHead

      Parallel STL algorithms can be called with ordinary (host-side)
      iterators, as in the code below. In that case, a temporary SYCL
      buffer is created and the data is copied to this buffer. After the
      processing of the temporary buffer on a device is complete, the
      data is copied back to the host. Working with SYCL buffers is
      recommended to reduce data copying between host and device.


   ::


      #include <vector>
      #include <dpstd/execution>
      #include <dpstd/algorithm>
      int main(){
           std::vector<int> vec( 1000000 );
           auto policy = dpstd::execution::make_sycl_policy<
           class fill>(dpstd::execution::sycl);
           std::fill(policy, vec.begin(), vec.end(), 42);
        // each element of vec will be equal to 42
           return 0;
      }


.. container:: section
   :name: GUID-3AD458FC-019B-4E1B-9167-E72E5467D315


   .. rubric:: Verified C++ Standard API
      :class: sectiontitle

   Several C++ Standard APIs can be employed in device kernels similar
   to how they are employed in code for a typical CPU-based platform.
   The following code demonstrates such use for ``std::swap`` function:


   ::


      #include <CL/sycl.hpp>
      #include <utility>
      #include <iostream>
      constexpr cl::sycl::access::mode sycl_read_write,
        cl::sycl::access::mode::read_write;
      class KernelSwap;
      void kernel_test() {
        cl::sycl::queue deviceQueue;
        cl::sycl::range<1> numOfItems{2};
        cl::sycl::cl_int swap_num[2] = {4, 5};
        std::cout << swap_num[0] << ", " << swap_num[1] << std::endl;
        {
          cl::sycl::buffer<cl::sycl::cl_int, 1>
            swap_buffer(swap_num, numOfItems);
          deviceQueue.submit([&](cl::sycl::handler &cgh) {
            auto swap_accessor = swap_buffer.get_access<
              sycl_read_write>(cgh);
            cgh.single_task<class KernelSwap>([=]() {
              int & num1 = swap_accessor[0];
              int & num2 = swap_accessor[1];
              std::swap(num1, num2);
            });
          });
        }
          std::cout << swap_num[0] << ", " << swap_num[1] << std::endl;
      }
      int main() {
        kernel_test();
        return 0;
      }

