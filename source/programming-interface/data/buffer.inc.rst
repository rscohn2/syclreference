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
   

.. class:: template <typename T, int dimensions = 1, typename AllocatorT = cl::sycl::buffer_allocator> buffer

   :tparam T: buffer element type
   :tparam dimensions: dimensionality of the data
   :tparam AllocatorT: STL allocator
		 
   .. type:: value_type = T
             reference = value_type &
             const_reference = const value_type &
             allocator_type = AllocatorT

	     Standard types

   .. function:: buffer(const range<dimensions> &bufferRange, const property_list &propList = {})
                 buffer(const range<dimensions> &bufferRange, AllocatorT allocator, const property_list &propList = {})
                 buffer(T *hostData, const range<dimensions> &bufferRange, const property_list &propList = {})
                 buffer(T *hostData, const range<dimensions> &bufferRange, AllocatorT allocator, const property_list &propList = {})
                 buffer(const T *hostData, const range<dimensions> &bufferRange, const property_list &propList = {})
                 buffer(const T *hostData, const range<dimensions> &bufferRange, AllocatorT allocator, const property_list &propList = {})
                 buffer(const shared_ptr_class<T> &hostData, const range<dimensions> &bufferRange, AllocatorT allocator, const property_list &propList = {})
                 buffer(const shared_ptr_class<T> &hostData, const range<dimensions> &bufferRange, const property_list &propList = {})
                 template <class InputIterator> buffer<T, 1>(InputIterator first, InputIterator last, AllocatorT allocator, const property_list &propList = {})
                 template <class InputIterator> buffer<T, 1>(InputIterator first, InputIterator last, const property_list &propList = {})
                 buffer(buffer<T, dimensions, AllocatorT> b, const id<dimensions> &baseIndex, const range<dimensions> &subRange)

		 Constructors.

		 :arg bufferRange: Dimensions of buffer
		 :arg propList: Properties for buffer
		 :arg hostData: Home for data
		 :arg allocator: STL allocator for data
		 :arg first: first and last are STL iterators used to initialize the buffer
	         :arg last: first and last are STL iterators used to initialize the buffer
	         :arg b: Use buffer :expr:`b` to initialize
		 :arg baseIndex: Index in :expr:`b`
		 :arg subRange: Range of data in :expr:`b`
		 
   .. function:: buffer(cl_mem clMemObject, const context &syclContext, event availableEvent = {})

		 :arg clMemObject:
		 :arg syclContext:
		 :arg availableEvent:

		 Simplified buffer constructor when :expr:`dimensions == 1`.

   .. function:: range<dimensions> get_range() const

		 :returns:

   .. function:: size_t get_count() const

		 :returns:

   .. function:: size_t get_size() const

		 :returns:

   .. function:: AllocatorT get_allocator() const

		 :returns:

   .. function:: template <access::mode mode, access::target target = access::target::global_buffer> \
		   accessor<T, dimensions, mode, target> get_access(handler &commandGroupHandler)
                 template <access::mode mode> accessor<T, dimensions, mode, access::target::host_buffer> get_access()
                 template <access::mode mode, access::target target = access::target::global_buffer> \
		   accessor<T, dimensions, mode, target> get_access(handler &commandGroupHandler, range<dimensions> accessRange, id<dimensions> accessOffset = {})
                 template <access::mode mode> accessor<T, dimensions, mode, access::target::host_buffer> \
		   get_access(range<dimensions> accessRange, id<dimensions> accessOffset = {})

                 :tparam mode:
                 :tparam target:
		 :arg handler:
		 :arg accessRange:
		 :arg accessOffset:
		 :returns:

   .. function:: template <typename Destination = std::nullptr_t> void set_final_data(Destination finalData = nullptr)

		 :tparam Destination:
		 :arg finalData:

   .. function:: void set_write_back(bool flag = true)

		 :arg flag:

   .. function:: bool is_sub_buffer() const

		 :returns:

   .. function:: template <typename ReinterpretT, int ReinterpretDim> buffer<ReinterpretT, ReinterpretDim, AllocatorT> \
		   reinterpret(range<ReinterpretDim> reinterpretRange) const

		 :tparam ReinterpretT:
		 :tparam ReinterpretDim:
		 :arg reinterpretRange:
		 :returns:

.. namespace-push:: property::buffer

.. class:: use_host_ptr

   .. function:: use_host_ptr()
			 
.. class:: use_mutex

   .. function:: use_mutex(mutex_class &mutexRef)

		 :param mutexRef:

   .. function::  mutex_class *get_mutex_ptr() const

		  :returns:

.. class:: context_bound

   .. function:: context_bound(context boundContext)

		 :param boundContext:

   .. function:: context get_context() const

		 :returns:

.. namespace-pop::
