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

.. struct:: template <typename propertyT> is_property

.. struct:: template <typename propertyT, typename syclObjectT> is_property_of

.. class:: T 

   .. function:: template <typename propertyT> bool has_property() const
		 
   .. function:: template <typename propertyT> propertyT get_property() const


.. class:: property_list

   .. function:: template <typename... propertyTN> property_list(propertyTN... props)
