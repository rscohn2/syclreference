=========
 Outline
=========

* Programming model

  * DPC++
  * Sample program
  * Host & kernels
  * Platform model
  * Execution model
  * Memory model

    * USM
    * Buffers & accessors

* oneAPI Programs

  * Single source
  * Fat binaries
  * Libraries
  * Compiling

* Language

  * Based on C++
  * Core concepts

    * Data
      
      * Buffer/accessor & USM

    * Launching work on the device
      
      * Call group handler
      * parallel_for
      
    * Syncronization
      
  * Sample

    * Header files and namespaces

* Libraries

  * Generic principles of libraries

    * Queues to target device
    * buffer/USM pointer are device data handles
    * Events to synchronize

  * Libraries for multiple domains
    
    * DPL
    * TBB
    * MKL
  
  * Domain specific
    
    * Video: VPL
    * Machine learning: DAL
    * Deep learning: DNN/CCL

* DPC++ API reference

  * Host APIs

    * Event
    * Buffer
    * queue
      
  * Kernel APIs
    
