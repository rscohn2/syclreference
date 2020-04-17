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

.. _`SYCL specification`: https://www.khronos.org/sycl/

.. namespace-push:: info

.. enum-class:: device

   See `SYCL specification`_

   .. enumerator:: \
      device_type
      vendor_id
      max_compute_units
      max_work_item_dimensions
      max_work_item_sizes
      max_work_group_size
      preferred_vector_width_char
      preferred_vector_width_short
      preferred_vector_width_int
      preferred_vector_width_long
      preferred_vector_width_float
      preferred_vector_width_double
      preferred_vector_width_half
      native_vector_width_char
      native_vector_width_short
      native_vector_width_int
      native_vector_width_long
      native_vector_width_float
      native_vector_width_double
      native_vector_width_half
      max_clock_frequency
      address_bits
      max_mem_alloc_size
      image_support
      max_read_image_args
      max_write_image_args
      image2d_max_height
      image2d_max_width
      image3d_max_height
      image3d_max_width
      image3d_max_depth
      image_max_buffer_size
      image_max_array_size
      max_samplers
      max_parameter_size
      mem_base_addr_align
      half_fp_config
      single_fp_config
      double_fp_config
      global_mem_cache_type
      global_mem_cache_line_size
      global_mem_cache_size
      global_mem_size
      max_constant_buffer_size
      max_constant_args
      local_mem_type
      local_mem_size
      error_correction_support
      host_unified_memory
      profiling_timer_resolution
      is_endian_little
      is_available
      is_compiler_available
      is_linker_available
      execution_capabilities
      queue_profiling
      built_in_kernels
      platform
      name
      vendor
      driver_version
      profile
      version
      opencl_c_version
      extensions
      printf_buffer_size
      preferred_interop_user_sync
      parent_device
      partition_max_sub_devices
      partition_properties
      partition_affinity_domains
      partition_type_property
      partition_type_affinity_domain
      reference_count

.. enum-class:: device_type

   .. enumerator:: cpu

      Maps to OpenCL CL_DEVICE_TYPE_CPU

   .. enumerator:: gpu

      Maps to OpenCL CL_DEVICE_TYPE_GPU

   .. enumerator:: acc

      Maps to OpenCL CL_DEVICE_TYPE_ACCELERATOR

   .. enumerator:: cus

      Maps to OpenCL CL_DEVICE_TYPE_CUSTOM

   .. enumerator:: aut

      Maps to OpenCL CL_DEVICE_TYPE_DEFAULT

   .. enumerator:: host
   .. enumerator:: all

      Maps to OpenCL CL_DEVICE_TYPE_ALL


.. enum-class:: partition_property

   See `SYCL specification`_

   .. enumerator:: \		
      no_partition
      partition_equally
      partition_by_counts
      partition_by_affinity_domain


.. enum-class:: partition_affinity_domain

   See `SYCL specification`_

   .. enumerator:: \		
      not_applicable
      numa
      L4_cache
      L3_cache
      L2_cache
      L1_cache
      next_partitionable


.. enum-class:: local_mem_type

   See `SYCL specification`_

   .. enumerator:: \
      none
      local
      global

.. enum-class:: fp_config

   See `SYCL specification`_

   .. enumerator:: \		
      denorm
      inf_nan
      round_to_nearest
      round_to_zero
      round_to_inf
      fma
      correctly_rounded_divide_sqrt
      soft_float

.. enum-class:: global_mem_cache_type

   See `SYCL specification`_

   .. enumerator:: \
      none
      read_only
      read_write

.. enum-class:: execution_capability

   See `SYCL specification`_

   .. enumerator:: \
      exec_kernel
      exec_native_kernel

      
