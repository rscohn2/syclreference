.. _onedal-code-sample:

oneDAL Code Sample
==================


The following code sample demonstrates oneDAL-specific features:


::


   #include "daal_sycl.h"
   #include <iostream>
   using namespace daal;
   using namespace daal::algorithms;
   using namespace daal::data_management;
   int main(int argc, char const *argv[])
   {
     // Set the desired execution context
     cl::sycl::queue queue { cl::sycl::gpu_selector() };
     services::SyclExecutionContext ctx(queue);
     services::Environment::getInstance()->setDefaultExecutionContext(ctx);
     float input[6] = { 1.5f, 2.7f, 3.0f, 6.0f, 2.0f, 4.0f };
     cl::sycl::buffer<float, 1> a { input, cl::sycl::range<1>(6) };
     auto data = SyclHomogenNumericTable<>::create(a, 2, 3);
     covariance::Batch<> algorithm;
     algorithm.input.set(covariance::data, data);
     algorithm.parameter.outputMatrixType = covariance::correlationMatrix;
     algorithm.compute();
     NumericTablePtr table = algorithm.getResult()->get(covariance::correlation);
     // Get the DPC++ buffer from table
     BlockDescriptor<float> block;
     const size_t startRowIndex = 0;
     const size_t numberOfRows = table->getNumberOfRows();
     table->getBlockOfRows(startRowIndex, numberOfRows, readOnly, block);
     cl::sycl::buffer<float, 1> buffer = block.getBuffer().toSycl();
     table->releaseBlockOfRows(block);
     // Printing result to the console
     auto accessor = buffer.get_access<cl::sycl::access::mode::read>();
     for (int row = 0; row < table->getNumberOfRows(); row++)
     {
       for (int col = 0; col < table->getNumberOfColumns(); col++)
       {
         std::cout << accessor[row*table->getNumberOfColumns()+col] << ", ";
       }
       std::cout << std::endl;
     }
     return 0;
   }


A typical command line to build a oneDAL application is:


::


   dpcpp main.cpp -ldaal_core -ldaal_thread -foffload-static-lib=$DAALROOT/lib/intel64/libdaal_sycl.a

