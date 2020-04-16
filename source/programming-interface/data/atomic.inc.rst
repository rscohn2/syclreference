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

.. enum-class:: memory_order

   .. enumerator:: relaxed

.. class:: template <typename T, access::address_space addressSpace = access::address_space::global_space> atomic

	   :tparam T:
	   :tparam addressSpace:

   .. function:: template <typename pointerT> atomic(multi_ptr<pointerT, addressSpace> ptr)

		 :tparam pointerT:
		 :arg ptr:

   .. function:: void store(T operand, memory_order memoryOrder = memory_order::relaxed)
		 T load(memory_order memoryOrder = memory_order::relaxed) const
		 T exchange(T operand, memory_order memoryOrder = memory_order::relaxed)

		 :arg operand:
		 :arg memoryOrder:
		 
   .. function:: bool compare_exchange_strong(T &expected, T desired, memory_order successMemoryOrder = memory_order::relaxed, memory_order failMemoryOrder = memory_order::relaxed)

		 :arg expected:
		 :arg desired:
		 :arg successMemoryOrder:
		 :arg failMemoryOrder:
		  
		 Available only when: :expr:`T` != float

   .. function:: T fetch_add(T operand, memory_order memoryOrder = memory_order::relaxed)
                 T fetch_sub(T operand, memory_order memoryOrder = memory_order::relaxed)
		 T fetch_and(T operand, memory_order memoryOrder = memory_order::relaxed)
		 T fetch_or(T operand, memory_order memoryOrder = memory_order::relaxed)
		 T fetch_xor(T operand, memory_order memoryOrder = memory_order::relaxed)
		 T fetch_min(T operand, memory_order memoryOrder = memory_order::relaxed)
		 T fetch_max(T operand, memory_order memoryOrder = memory_order::relaxed)

		 :arg operand:
		 :arg memoryOrder:

		 Available only when: :expr:`T` != float
