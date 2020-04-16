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

.. class:: template <int dimensions = 1> nd_item
	   
   .. function:: id<dimensions> get_global_id() const
		 size_t get_global_id(int dimension) const

   .. function:: size_t get_global_linear_id() const

   .. function:: id<dimensions> get_local_id() const
		 size_t get_local_id(int dimension) const

   .. function:: size_t get_local_linear_id() const

   .. function:: group<dimensions> get_group() const
		 size_t get_group(int dimension) const

   .. function:: size_t get_group_linear_id() const

   .. function:: range<dimensions> get_group_range() const
		 size_t get_group_range(int dimension) const

   .. function:: range<dimensions> get_global_range() const
		 size_t get_global_range(int dimension) const

   .. function:: range<dimensions> get_local_range() const
		 size_t get_local_range(int dimension) const

   .. function:: id<dimensions> get_offset() const

   .. function:: nd_range<dimensions> get_nd_range() const

   .. function:: void barrier(access::fence_space accessSpace = access::fence_space::global_and_local) const

   .. function:: template <access::mode accessMode = access::mode::read_write> \
		 void mem_fence(access::fence_space accessSpace = access::fence_space::global_and_local) const

   .. function:: template <typename dataT> \
		   device_event async_work_group_copy(local_ptr<dataT> dest, \
                                                      global_ptr<dataT> src, \
						      size_t numElements) const
		 template <typename dataT> \
		   device_event async_work_group_copy(global_ptr<dataT> dest, \
		                                      local_ptr<dataT> src, \
						      size_t numElements) const
                 template <typename dataT> \
		   device_event async_work_group_copy(local_ptr<dataT> dest, \
                                                      global_ptr<dataT> src, \
						      size_t numElements, \
						      size_t srcStride) const
                 template <typename dataT> \
                   device_event async_work_group_copy(global_ptr<dataT> dest, \
		                                      local_ptr<dataT> src, \
						      size_t numElements, \
						      size_t destStride) const

   .. function:: template <typename... eventTN> void wait_for(eventTN... events) const
