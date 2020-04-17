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
   
.. class:: device

   .. rubric:: Constructors
		       
   .. function:: device()
		 explicit device(cl_device_id deviceId)
		 explicit device(const device_selector &deviceSelector)
			 
   .. function:: cl_device_id get() const

		 :returns:
		    
   .. function:: bool is_host() const

		 :returns: true if a :term:`host device`
		    
   .. function:: bool is_cpu() const

		 :returns: true if device uses a CPU
		    
   .. function:: bool is_gpu() const

		 :returns: true if device uses a GPU
		    
   .. function:: bool is_accelerator() const

		 :returns:
		    
   .. function:: platform get_platform() const

		 :returns:
		    
   .. function:: template <info::device param> typename info::param_traits<info::device, param>::return_type get_info() const

   .. function:: bool has_extension(const string_class &extension) const

   .. function:: template <info::partition_property prop> vector_class<device> create_sub_devices(size_t nbSubDev) const

		 Available only when :expr:`prop == info::partition_property::partition_equally`

   .. function:: template <info::partition_property prop> vector_class<device> create_sub_devices(const vector_class<size_t> &counts) const

		 Available only when :expr:`prop == info::partition_property::partition_by_counts`

   .. function:: template <info::partition_property prop> vector_class<device> create_sub_devices(info::affinity_domain affinityDomain) const

		 Available only when :expr:`prop == info::partition_property::partition_by_affinity_domain`

   .. function:: static vector_class<device> get_devices(info::device_type deviceType = info::device_type::all)
