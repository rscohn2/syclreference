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

.. type:: template <typename ElementType> \
	    global_ptr = multi_ptr<ElementType, access::address_space::global_space>
	  template <typename ElementType> \
	    local_ptr = multi_ptr<ElementType, access::address_space::local_space>
	  template <typename ElementType> \
	    constant_ptr = multi_ptr<ElementType, access::address_space::constant_space>
          template <typename ElementType> \
	    private_ptr = multi_ptr<ElementType, access::address_space::private_space>
