..
  // Copyright (c) 2011-2020 The Khronos Group, Inc.
  //
  // Licensed under the Apache License, Version 2.0 (the License);
  // you may not use this file except in compliance with the License.
  // You may obtain a copy of the License at
  //
  //     http://www.apache.org/licenses/LICENSE-2.0
  //
  // Unless required by applicable law or agreed to in writing, software
  // distributed under the License is distributed on an AS IS BASIS,
  // WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  // See the License for the specific language governing permissions and
  // limitations under the License.

.. class:: handler

   .. function:: template <typename dataT, int dimensions, access::mode accessMode, access::target accessTarget> void require(accessor<dataT, dimensions, accessMode, accessTarget, access::placeholder::true_t> acc)

		 :tparam dataT:
		 :tparam dimensions:
		 :tparam accessMode:
		 :tparam accessTarget:
		 

   .. rubric:: OpenCL interoperability interface

   .. function:: template <typename T> void set_arg(int argIndex, T && arg)

		  :tparam T:
		  :arg argIndex:
		  :arg arg:

   .. function:: template <typename... Ts> void set_args(Ts &&... args)

   .. rubric:: Kernel dispatch API

   .. note::
      Note: In all Kernel dispatch functions, 
      when using a functor with a globally visible name
      the template parameter:"typename kernelName" can be ommitted
      and the kernelType can be used instead.

   .. function:: template <typename KernelName, typename KernelType> void single_task(KernelType kernelFunc)
		 void single_task(kernel syclKernel)

		 :tparam KernelName:
		 :tparam KernelType:
		 :arg kernelFunc:
		 :arg syclKernel:

   .. function:: template <typename KernelName, typename KernelType, int dimensions> void parallel_for(range<dimensions> numWorkItems, KernelType kernelFunc)
		 template <typename KernelName, typename KernelType, int dimensions> void parallel_for(range<dimensions> numWorkItems, id<dimensions> workItemOffset, KernelType kernelFunc)
		 template <typename KernelName, typename KernelType, int dimensions> void parallel_for(nd_range<dimensions> executionRange, KernelType kernelFunc)
		 template <int dimensions> void parallel_for(range<dimensions> numWorkItems, kernel syclKernel)
		 template <int dimensions> void parallel_for(range<dimensions> numWorkItems, id<dimensions> workItemOffset, kernel syclKernel)
		 template <int dimensions> void parallel_for(nd_range<dimensions> ndRange, kernel syclKernel)

		 :tparam KernelName:
		 :tparam KernelType:
		 :tparam dimensions:
		 :arg numWorkItems:
		 :arg workItemOffset:
		 :arg executionRange:
		 :arg ndRange:
                 :arg kernelFunc:
                 :arg syclKernel:

   .. function:: template <typename KernelName, typename WorkgroupFunctionType, int dimensions> void parallel_for_work_group(range<dimensions> numWorkGroups, WorkgroupFunctionType kernelFunc)
		 template <typename KernelName, typename WorkgroupFunctionType, int dimensions> void parallel_for_work_group(range<dimensions> numWorkGroups, range<dimensions> workGroupSize, WorkgroupFunctionType kernelFunc)

		 :tparam KernelName:
		 :tparam WorkgroupFunctionType:
		 :tparam dimensions:
		 :arg numWorkGroups:
                 :arg kernelFunc:

   .. rubric:: Explicit memory operation APIs

   .. function:: template <typename T_src, int dim_src, access::mode mode_src, access::target tgt_src, access::placeholder isPlaceholder, typename T_dest> void copy(accessor<T_src, dim_src, mode_src, tgt_src, isPlaceholder> src, shared_ptr_class<T_dest> dest)
		 template <typename T_src, typename T_dest, int dim_dest, access::mode mode_dest, access::target tgt_dest, access::placeholder isPlaceholder> void copy(shared_ptr_class<T_src> src, accessor<T_dest, dim_dest, mode_dest, tgt_dest, isPlaceholder> dest)
		 template <typename T_src, int dim_src, access::mode mode_src, access::target tgt_src, access::placeholder isPlaceholder, typename T_dest> void copy(accessor<T_src, dim_src, mode_src, tgt_src, isPlaceholder> src, T_dest *dest)
		 template <typename T_src, typename T_dest, int dim_dest, access::mode mode_dest, access::target tgt_dest, access::placeholder isPlaceholder> void copy(const T_src *src, accessor<T_dest, dim_dest, mode_dest, tgt_dest, isPlaceholder> dest)
		 template <typename T_src, int dim_src, access::mode mode_src, access::target tgt_src, access::placeholder isPlaceholder_src, typename T_dest, int dim_dest, access::mode mode_dest, access::target tgt_dest, access::placeholder isPlaceholder_dest> void copy(accessor<T_src, dim_src, mode_src, tgt_src, isPlaceholder_src> src, accessor<T_dest, dim_dest, mode_dest, tgt_dest, isPlaceholder_dest> dest)

		 :tparam T_src:
		 :tparam dim_src:
		 :tparam mode_src:
		 :tparam tgt_src:
		 :tparam isPlaceholder:
		 :tparam isPlaceholder_src:
		 :tparam T_dest:
		 :tparam dim_dest:
		 :tparam mode_dest:
		 :tparam tgt_dest:
		 :tparam isPlaceholder_dest:
		 :arg src:
		 :arg dest:

   .. function:: template <typename T, int dim, access::mode mode, access::target tgt, access::placeholder isPlaceholder> void update_host(accessor<T, dim, mode, tgt, isPlaceholder> acc)

		 :tparam T:
		 :tparam dim:
		 :tparam mode:
		 :tparam tgt:
		 :tparam isPlaceholder:
		 :arg acc:

   .. function:: template <typename T, int dim, access::mode mode, access::target tgt, access::placeholder isPlaceholder> void fill(accessor<T, dim, mode, tgt, isPlaceholder> dest, const T& src)

		 :tparam T:
		 :tparam dim:
		 :tparam mode:
		 :tparam tgt:
		 :tparam isPlaceholder:
		 :arg dest:
		 :arg src:
