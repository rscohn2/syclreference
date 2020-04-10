.. _execution-model:

Execution Model
===============


The execution model is based upon the SYCL\* execution model. It defines
and specifies how code, termed kernels, execute on the host and the
devices.


The host execution model coordinates execution and data management
between the host and devices via command groups. The command groups,
which are groupings of commands like kernel invocation and accessors,
are submitted to queues for execution. Accessors, which are formally
part of the memory model, also communicate ordering requirements of
execution. A program employing the execution model declares and
instantiates queues. Queues can execute with an in-order or out-of-order
policy controllable by the program. In-order execution is an Intel
extension.


The device execution model specifies how computation is accomplished
on the accelerator. Compute ranging from small one-dimensional data to
large multidimensional data sets are allocated across a hierarchy of
:term:`ND-range`, :term:`Work-group`, :term:`Sub-group`, and
:term:`Work-item`, which are all specified when the work is submitted
to the command queue.  It is important to note that the actual kernel
code represents the work that is executed for one work-item. The code
outside of the kernel controls just how much parallelism is executed;
the amount and distribution of the work is controlled by specification
of the sizes of the ND-range and work-group.


The following figure depicts the relationship between an ND-range,
work-group, sub-group, and work-item. The total amount of work is
specified by the ND-range size. The grouping of the work is specified by
the work-group size. The example shows the ND-range size of X \* Y \* Z,
work-group size of X’ \* Y’ \* Z’, and subgroup size of X’. Therefore,
there are X \* Y \* Z work-items. There are (X \* Y \* Z) / (X’ \* Y’ \*
Z’) work-groups and (X \* Y \* Z) / X’ subgroups.


| 
| |image0|


When kernels are executed, the location of a particular work-item in the
larger ND-range, work-group, or sub-group is important. For example, if
the work-item is assigned to compute on specific pieces of data, a
method of specification is necessary. Unique identification of the
work-item is provided via intrinsic functions such as those in the
``nd_item`` class (``global_id``, ``work_group_id``, and ``local_id``).


The following code sample launches a kernel and displays the
relationships of the previously discussed ``ND-range``, ``work-group``,
and ``work-item``.


::


   #include<CL/sycl.hpp>
   #include<iostream>
   #define N 6
   #define M 2
   using namespace cl::sycl;
   int main()
   {
      queue defaultqueue;
      buffer<int,2> buf(range<2>(N,N));
    defaultqueue.submit([&](handler &cgh){
      auto bufacc = buf.get_access<access::mode::read_write>(cgh);
      cgh.parallel_for<class ndim>(nd_range<2>(range<2>(N,N),
        range<2>(M,M)), [=](nd_item<2> i){
        id<2> ind = i.get_global_id();
        bufacc[ind[0]][ind[1]] = ind[0]+ind[1];
      });
    });
    auto bufacc1 = buf.get_access<access::mode::read>();
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++)
        std::cout<<bufacc1[i][j]<<"\t";
      std::cout<<"\n";
    }
    return 0;
   }


.. container:: section
   :name: GUID-96EF050D-13F4-4E1B-B9C6-6AA0B7E4B84E


   .. rubric:: ND-Range Parallelism Example
      :class: sectiontitle

   The following discusses the relationships in the use of the ND-range
   in the previous code sample.


   -  At line 12 is the ``nd-range`` declaration. ``nd_range<2>``
      specifies a two-dimensional index space.
   -  The global range is specified by the first argument,
      ``range<2>(N,N)``, which specifies the overall index space as 2
      dimensions with size ``N`` by ``N``.
   -  The second argument, ``range<2>(M,M)`` specifies the local
      work-group range as 2 dimensions with size ``M`` by ``M``.
   -  Line 13 employs ``nd_item<2>`` to reference each work-item in the
      ND-range, and calls ``get_global_id`` to determine the index in
      the global buffer, ``bufacc``.


   The ``sub-group`` is an extension to the SYCL execution model and
   sits hierarchically between the ``work_group`` and ``work_item``. The
   ``sub_group`` was created to align with typical hardware resources
   that contain a vector unit to execute several similar operations in
   parallel and in lock step.


.. |image0| image:: /image/GUID-761368A6-499F-4FED-9CC5-19069FBEE179-low.png
   :width: 468px
   :height: 453px

