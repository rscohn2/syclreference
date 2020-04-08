.. _onemkl-code-sample:

oneMKL Code Sample
==================


To demonstrate a typical workflow for the oneMKL with DPC++ interfaces,
the following example source code snippets perform a double precision
matrix-matrix multiplication on a GPU device.


::


   // standard SYCL header
   #include <CL/sycl.hpp>
   // include std::exception class
   #include <exception>
   // declarations for Intel oneAPI Math Kernel Library SYCL apis
   #include "mkl_sycl.hpp"
   int main(int argc, char *argv[]) {
       //
       // User obtain data for A,B,C matrices along with setting m,n,k, ldA, ldB, ldC.
       //
       // A, B and C should be stored in containers like std::vector that contain a 
       // data() and size() member function
       //
       // create gpu device 
       cl::sycl::device my_device;
       try {
           my_device = cl::sycl::device(cl::sycl::gpu_selector());
       }
       catch (...) {
           std::cout << "Warning, gpu device not found! Defaulting back to host device from default constructor. " << std::endl;
       }
       // create asynchronous exceptions handler to be attached to queue
       auto my_exception_handler = [](cl::sycl::exception_list exceptions) {
           for (std::exception_ptr const& e : exceptions) {
               try {
                   std::rethrow_exception(e);
               }
               catch (cl::sycl::exception const& e) {
                   std::cout << "Caught asynchronous SYCL exception:\n"
                       << e.what() << std::endl;
               }
               catch (std::exception const& e) {
                   std::cout << "Caught asynchronous STL exception:\n"
                       << e.what() << std::endl;
               }
           }
       };
       // create execution queue on my gpu device with exception handler attached
       cl::sycl::queue my_queue(my_device, my_exception_handler);
       // create sycl buffers of matrix data for offloading between device and host
       cl::sycl::buffer<double, 1> A_buffer(A.data(), A.size());
       cl::sycl::buffer<double, 1> B_buffer(B.data(), B.size());
       cl::sycl::buffer<double, 1> C_buffer(C.data(), C.size());
       // add mkl::blas::gemm to execution queue and catch any synchronous exceptions
       try {
           mkl::blas::gemm(my_queue, mkl::transpose::nontrans, mkl::transpose::nontrans, m, n, k, alpha, A_buffer, ldA, B_buffer,
              ldB, beta, C_buffer, ldC);
       }
       catch (cl::sycl::exception const& e) {
           std::cout << "\t\tCaught synchronous SYCL exception during GEMM:\n"
               << e.what() << std::endl;
       }
       catch (std::exception const& e) {
           std::cout << "\t\tCaught synchronous STL exception during GEMM:\n"
               << e.what() << std::endl;
       }
       // ensure any asynchronous exceptions caught are handled before proceeding
       my_queue.wait_and_throw();
       //
       // post process results
       //
       // Access data from C buffer and print out part of C matrix
       auto C_accessor = C_buffer.template get_access<cl::sycl::access::mode::read>();
       std::cout << "\t" << C << " = [ " << C_accessor[0] << ", "
           << C_accessor[1] << ", ... ]\n";
       std::cout << "\t    [ " << C_accessor[1 * ldC + 0] << ", "
           << C_accessor[1 * ldC + 1] << ",  ... ]\n";
       std::cout << "\t    [ " << "... ]\n";
       std::cout << std::endl;
       

       return 0;
   }


Consider that (double precision valued) matrices A(of size m-by-k), B(
of size k-by-n) and C(of size m-by-n) are stored in some arrays on the
host machine with leading dimensions ldA, ldB, and ldC, respectively.
Given scalars (double precision) alpha and beta, compute the
matrix-matrix multiplication (``mkl::blas::gemm``):


C = alpha \* A \* B + beta \* C


Include the standard SYCL headers and the oneMKL SYCL specific header
that declares the desired ``mkl::blas::gemm`` API:


::


   // standard sycl header
   #include <CL/sycl.hpp>


   // declarations for oneAPI MKL DPC++ BLAS apis
   #include "mkl_blas_sycl.hpp"     


Next, load or instantiate the matrix data on the host machine as usual
and then create the sycl device, create an asynchronous exception
handler, and finally create the queue on the device with that exception
handler. Exceptions that occur on the host can be caught using standard
C++ exception handling mechanisms; however, exceptions that occur on a
device are considered asynchronous errors and stored in an exception
list to be processed later by this user-provided exception handler.


::


   // create gpu device 
   cl::sycl::device my_device;
   try {
     my_device = cl::sycl::device(cl::sycl::gpu_selector());
   } catch (...) {
     std::cout << "Warning, gpu device not found! Defaulting back to host device from default constructor. " << std::endl;
   }


   // create asynchronous exceptions handler to be attached to queue
   auto my_exception_handler = [](cl::sycl::exception_list exceptions) {
     for (std::exception_ptr const& e : exceptions) {
       try { 
         std::rethrow_exception(e); 
       }
       catch (cl::sycl::exception const& e) {
         std::cout << "Caught asynchronous SYCL exception:\n"
                   << e.what() << std::endl;
       }
     }
   };


   // create execution queue on my gpu device with exception handler attached
   cl::sycl::queue my_queue(my_device, my_exception_handler);


The matrix data is now loaded into the sycl buffers, which enables
offloading to desired devices and then back to host when complete.
Finally, the ``mkl::blas::gemm`` API is called with all the buffers,
sizes, and transpose operations, which will enqueue the matrix multiply
kernel and data onto the desired queue.


::


   // create sycl buffers of matrix data for offloading between device and host
   cl::sycl::buffer<double, 1> A_buffer(A.data(), A.size());
   cl::sycl::buffer<double, 1> B_buffer(B.data(), B.size());
   cl::sycl::buffer<double, 1> C_buffer(C.data(), C.size());


   // add mkl::blas::gemm to execution queue and catch any synchronous exceptions
   try {
     mkl::blas::gemm(my_queue, mkl::transpose::nontrans, mkl::transpose::nontrans, 
                     m, n, k, alpha, A_buffer, ldA, B_buffer, ldB, beta, C_buffer, ldC);
   }
   catch (cl::sycl::exception const& e) {
     std::cout << "\t\tCaught synchronous SYCL exception during GEMM:\n"
       << e.what() << std::endl;
   }


At some time after the gemm kernel has been enqueued, it will be
executed. The queue is asked to wait for all kernels to execute and then
pass any caught asynchronous exceptions to the exception handler to be
thrown. The SYCL runtime will handle transfer of the buffer’s data
between host and GPU device and back. By the time an accessor is created
for the C_buffer, the buffer data will have been silently transferred
back to the host machine. In this case, the accessor is used to prints
out a 2x2 submatrix of C_buffer.


::


   // Access data from C buffer and print out part of C matrix
   auto C_accessor = C_buffer.template get_access<cl::sycl::access::mode::read>();
   std::cout << "\t" << C << " = [ " << C_accessor[0]           << ", " 
                                                       << C_accessor[1]           << ", ... ]\n"; 
   std::cout << "\t    [ "                       << C_accessor[1 * ldC + 0] << ", " 
                                                       << C_accessor[1*ldC + 1]   << ",  ... ]\n";
   std::cout << "\t    [ "                       << "... ]\n";
   std::cout << std::endl;


Note that the resulting data is still in the C_buffer object and, unless
it is explicitly copied elsewhere (like back to the original C
container), it will only remain available through accessors until the
C_buffer is out of scope.

