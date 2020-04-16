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

.. class:: queue

   .. rubric:: Constructors

   .. function:: explicit queue(const property_list &propList = {})
                 explicit queue(const async_handler &asyncHandler, \
                                const property_list &propList = {})
		 explicit queue(const device_selector &deviceSelector, \
                               const property_list &propList = {})
                 explicit queue(const device_selector &deviceSelector, \
                                const async_handler &asyncHandler, \
				const property_list &propList = {})
                 explicit queue(const device &syclDevice, \
                                const property_list &propList = {})
                 explicit queue(const device &syclDevice, \
		                const async_handler &asyncHandler, \
                                const property_list &propList = {})
                 explicit queue(const context &syclContext, \
		                const device_selector &deviceSelector, \
				const property_list &propList = {})
                 explicit queue(const context &syclContext, \
		                const device_selector &deviceSelector, \
				const async_handler &asyncHandler, \
				const property_list &propList = {})
		explicit queue(const context &syclContext, \
		               const device &syclDevice, \
			       const property_list &propList = {})
	        explicit queue(const context &syclContext, \
		               const device &syclDevice, \
			       const async_handler &asyncHandler, \
			       const property_list &propList = {})
                explicit queue(cl_command_queue clQueue, \
		               const context& syclContext, \
			       const async_handler &asyncHandler = {})


   .. rubric:: Property Interface Members

   .. function:: cl_command_queue get() const

		 :returns:

   .. function:: context get_context() const

		 :returns:

   .. function:: device get_device() const

		 :returns:
		    
   .. function:: bool is_host() const

		 :returns:

   .. function:: template <info::queue param> \
                   typename info::param_traits<info::queue, param>::return_type get_info() const

		 :tparam param:
		 :returns:

   .. function:: template <typename T> event submit(T cgf)
		 template <typename T> event submit(T cgf, const queue &secondaryQueue)
		 
		 :tparam T:
		 :arg cgf:
		 :arg secondaryQueue:
		 :returns:

   .. function:: void wait()

   .. function:: void wait_and_throw()

   .. function:: void throw_asynchronous()
