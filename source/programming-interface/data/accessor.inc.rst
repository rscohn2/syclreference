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

.. class:: template <typename dataT, int dimensions, access::mode accessmode, access::target accessTarget = access::target::global_buffer, access::placeholder isPlaceholder = access::placeholder::false_t> accessor

	   :tparam dataT:
	   :tparam dimensions:
	   :tparam accessmode:
	   :tparam accessTarget:
	   :tparam isPlacehodler:

   .. type:: value_type = dataT
	     reference = dataT &
	     const_reference = const dataT &

   .. rubric:: Constructors
	       
   .. function:: template <typename AllocatorT> \
		   accessor(buffer<dataT, 1, AllocatorT> &bufferRef, \
		            const property_list &propList = {})
		 template <typename AllocatorT> \
		   accessor(buffer<dataT, 1, AllocatorT> &bufferRef, handler &commandGroupHandlerRef, const property_list &propList = {})
		 template <typename AllocatorT> \
		   accessor(buffer<dataT, dimensions, AllocatorT> &bufferRef, const property_list &propList = {})
		 template <typename AllocatorT> \
		   accessor(buffer<dataT, dimensions, AllocatorT> &bufferRef, \
		            handler &commandGroupHandlerRef, const property_list &propList = {})
		 template <typename AllocatorT> \
		   accessor(buffer<dataT, dimensions, AllocatorT> &bufferRef, \
		            range<dimensions> accessRange, const property_list &propList = {})
		 template <typename AllocatorT> \
		   accessor(buffer<dataT, dimensions, AllocatorT> &bufferRef, \
		            range<dimensions> accessRange, id<dimensions> accessOffset, const property_list &propList = {})
		 template <typename AllocatorT> \
		   accessor(buffer<dataT, dimensions, AllocatorT> &bufferRef, \
		            handler &commandGroupHandlerRef, range<dimensions> accessRange, const property_list &propList = {})
		 template <typename AllocatorT> \
                   accessor(buffer<dataT, dimensions, AllocatorT> &bufferRef, \
		            handler &commandGroupHandlerRef, range<dimensions> accessRange, id<dimensions> accessOffset, const property_list &propList = {})

		 :tparam AllocatorT:
		 :arg bufferRef:
		 :arg propList:
		 :arg commandGroupHandlerRef:
		 :arg accessRange:
		 :arg accessOffset:
		 
   .. function:: constexpr bool is_placeholder() const

		 :returns:

   .. function:: size_t get_size() const

		 :returns:

   .. function:: size_t get_count() const

		 :returns:

   .. function:: range<dimensions> get_range() const

		 :tparam dimensions:
		 :returns:

		 Available only when: :expr:`dimensions > 0`

   .. function:: id<dimensions> get_offset() const

		 :tparam dimensions:
		 :returns:

		 Available only when: :expr:`dimensions > 0`

   .. function:: dataT &operator[](id<dimensions> index) const
		 dataT operator[](id<dimensions> index) const
		 dataT &operator[](size_t index) const
		 dataT operator[](size_t index) const
                 atomic<dataT, access::address_space::global_space> operator[](id<dimensions> index) const
		 atomic<dataT, access::address_space::global_space> operator[](size_t index) const

		 :arg index: :expr:`size_t` when :expr:`dimensions == 1` else an :type:`id`
		 :returns:

		 Describe when reference is not const

   .. function:: operator dataT &() const
                 operator dataT() const
		 operator atomic<dataT, access::address_space::global_space> () const

		 :returns:

		 Describe when reference is not const or atomic
		 
   .. function:: dataT *get_pointer() const
                 global_ptr<dataT> get_pointer() const
		 constant_ptr<dataT> get_pointer() const

		 :returns:

		 Available only when: :expr:`accessTarget == access::target::host_buffer`
                 Available only when: accessTarget == access::target::global_buffer
		 Available only when: accessTarget == access::target::constant_buffer
  
