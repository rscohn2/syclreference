.. _cpp-language-requirements:

C++ Language Requirements
=========================


The host code can be compiled by C++11 and later compilers and take
advantage of supported C++11 and later language features. The device
code requires a compiler that accepts all C++03 language features and
the following C++11 features:


-  Lamdba expressions
-  Variadic templates
-  Alias templates
-  rvalue references
-  std::function, std::string, std::vector


In addition, the device code cannot use the following features:


-  Virtual Functions
-  Virtual Inheritance
-  Exceptions handling – throws and catches between host and device
-  Run Time Type Information (RTTI)
-  Object management employing new and delete operators


The device code is specified via one of three language constructs:
lambda expression, functor, or kernel class. The separation of host code
and device code via these language constructs is natural and
accomplished without language extensions. These different forms of
expressing kernels give the developer flexibility in enmeshing the host
code and device code. For example:


-  To put the kernel code in line with the host code, consider employing
   a lambda expression.
-  To have the device code separate from the host code, but still
   maintain the single source property, consider employing a functor.
-  To port code from OpenCL programs or to ensure a more rigid
   separation between host and device code, consider employing the
   kernel class.


The Device code inside a lambda expression, functor, or kernel object
can then specify the amount of parallelism to request through several
mechanisms.


-  ``single_task`` – execute a single instance of the kernel with a
   single work item.
-  ``parallel_for`` – execute a kernel in parallel across a range of
   processing elements. Typically, this version of parallel_for is
   employed on “embarrassingly parallel” workloads.
-  ``parallel_for_work_group`` – execute a kernel in parallel across a
   hierarchical range of processing elements using local memory and
   barriers.


The following code sample shows two combinations of invoking kernels:


#. single_task and C++ lambda (lines 33-40)
#. parallel_for and functor (lines 8-20 and line 50)


These constructs enclose the aforementioned kernel scope. For details,
see the SYCL Specification.


::


   #include <vector>
   #include <CL/sycl.hpp>


   #define SIZE 1024


   namespace sycl = cl::sycl;


   template <typename T> class Vassign {
     T val;
     sycl::accessor<T, 1, sycl::access::mode::read_write,
                    sycl::access::target::global_buffer> access;


   public:
     Vassign(T val_, sycl::accessor<T, 1, sycl::access::mode::read_write,
             sycl::access::target::global_buffer> &access_) : val(val_),
             access(access_) {}


     void operator()(sycl::id<1> id) { access[id] = 1; }


   };


   int main() {
     std::array<int, SIZE> a;


     for (int i = 0; i<SIZE; ++i) {
       a[i] = i;
     }
     {
     sycl::range<1> a_size{SIZE};
     sycl::buffer<int, 1>  a_device(a.data(), a_size);
     sycl::queue d_queue;


     d_queue.submit([&](sycl::handler &cgh) {
       auto a_in = a_device.get_access<sycl::access::mode::write>(cgh);


       cgh.single_task<class ex1>([=]() {
         a_in[0] = 2;
       });
     });
     }


     {
     sycl::range<1> a_size{SIZE};
     sycl::buffer<int, 1>  a_device(a.data(), a_size);
     sycl::queue d_queue;
     d_queue.submit([&](sycl::handler &cgh) {
       auto a_in = a_device.get_access<sycl::access::mode::read_write,
                     sycl::access::target::global_buffer>(cgh);
       Vassign<int> F(0, a_in);
       cgh.parallel_for(sycl::range<1>(SIZE), F);
     });
     }
   } 

