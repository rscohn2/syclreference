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

.. enum-class:: addressing_mode

   .. enumerators:: mirrored_repeat
		    repeat
		    clamp_to_edge
		    clamp
		    none

.. enum-class:: filtering_mode

   .. enumerators:: nearest
		    linear

.. enum-class:: coordinate_normalization_mode

   .. enumerators:: normalized
		    unnormalized


.. class:: sampler

   .. function:: sampler(coordinate_normalization_mode normalizationMode, \
		         addressing_mode addressingMode, filtering_mode filteringMode, \
                         const property_list &propList = {})
		 sampler(cl_sampler clSampler, const context &syclContext)

      :arg normalizationMode:
      :arg addressingMode:
      :arg filteringMode:
      :arg propList:
      :arg clSampler:
      :arg syclContext:

  .. rubric:: Property Interface Members

  .. function:: addressing_mode get_addressing_mode() const
		
  .. function:: filtering_mode get_filtering_mode() const
		
  .. function:: coordinate_normalization_mode get_coordinate_normalization_mode() const
