.. _api-based-code:

API-Based Code
==============


The following code shows usage of an API call (``a * x + y``) employing
the Intel oneAPI Math Kernel Library function ``mkl::blas::axpy`` to
multiply ``a`` times ``x`` and add ``y`` across vectors of floating
point numbers. It takes advantage of the oneAPI programming model to
perform the addition on an accelerator.


::


   #include <vector> // std::vector()
   #include <cstdlib> // std::rand()
   #include <CL/sycl.hpp>
   #include "mkl_sycl.hpp"


   int main(int argc, char* argv[]) {


       double alpha = 2.0;
       int n_elements = 1024;


       int incx = 1;
       std::vector<double> x;
       x.resize(incx * n_elements);
       for (int i=0; i<n_elements; i++)
           x[i*incx] = 4.0 * double(std::rand()) / RAND_MAX - 2.0;   
           // rand value between -2.0 and 2.0


       int incy = 3;
       std::vector<double> y;
       y.resize(incy * n_elements);
       for (int i=0; i<n_elements; i++)
           y[i*incy] = 4.0 * double(std::rand()) / RAND_MAX - 2.0;   
           // rand value between -2.0 and 2.0


       cl::sycl::device my_dev;
       try {
           my_dev = cl::sycl::device(cl::sycl::gpu_selector());
       } catch (...) {
           std::cout << "Warning, failed at selecting gpu device. 
            Continuing on default(host) device." << std::endl;
       }


       // Catch asynchronous exceptions
       auto exception_handler = [] (cl::sycl::exception_list 
           exceptions) {
           for (std::exception_ptr const& e : exceptions) {
               try {
                   std::rethrow_exception(e);
                } catch(cl::sycl::exception const& e) {
                   std::cout << "Caught asynchronous SYCL 
               exception:\n"
                   << e.what() << std::endl;
               }
           }
       };


       cl::sycl::queue my_queue(my_dev, exception_handler);


       cl::sycl::buffer<double, 1> x_buffer(x.data(), x.size());
       cl::sycl::buffer<double, 1> y_buffer(y.data(), y.size());


       // perform y = alpha*x + y
       try {
           mkl::blas::axpy(my_queue, n_elements, alpha, x_buffer, 
           incx, y_buffer, incy);
       }


       catch(cl::sycl::exception const& e) {
           std::cout << "\t\tCaught synchronous SYCL exception:\n"
                     << e.what() << std::endl;
       }


       // copy y_buffer data back to y vector
       auto y_accessor = y_buffer.template 
         get_access<cl::sycl::access::mode::read>();
       for (int i=0; i<y.size(); ++i)
           y[i] = y_accessor[i];


       std::cout << "The axpy (y = alpha * x + y) computation is 
           complete!" << std::endl;


       return 0;
   }


To compile and build the application:


#. Ensure that the MKLROOT environment variable is set appropriately
   (``echo ${MKLROOT}``). If it is not set appropriately, source the
   ``setvars.sh`` script or run the ``setvars.bat`` script or set the
   variable to the folder that contains the ``lib`` and ``include``
   folders. For more information about the ``setvars.sh`` script, see
   `Get Started with Intel oneAPI Toolkits for
   Linux\* <https://software.intel.com/en-us/get-started-with-intel-oneapi-linux>`__
   or `Get Started with Intel oneAPI Toolkits for
   Windows\* <https://software.intel.com/en-us/get-started-with-intel-oneapi-windows>`__.


#. Build the application using the following command:


   ::


      dpcpp -I${MKLROOT}/include -Icommon  -DMKL_ILP64 -w -c axpy.cpp -o axpy.o


#. Link the application using the following command:


   ::


      dpcpp -I${MKLROOT}/include -DMKL_ILP64 -w axpy.o -foffload-static-lib="${MKLROOT}/lib/intel64"/libmkl_sycl.a -Wl,-export-dynamic -Wl,--start-group "${MKLROOT}/lib/intel64"/libmkl_intel_ilp64.a "${MKLROOT}/lib/intel64"/libmkl_sequential.a "${MKLROOT}/lib/intel64"/libmkl_core.a -Wl,--end-group -lsycl -lpthread -lm -ldl -o axpy.out


#. Run the application using the following command:


   ::


      ./axpy.out

