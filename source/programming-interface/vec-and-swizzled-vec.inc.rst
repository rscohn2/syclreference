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

.. enum-class:: rounding_mode

   .. enumerator:: automatic
		   rte
		   rtz
		   rtp
		   rtn
.. struct:: elem

   .. member:: static constexpr int x = 0
   .. member:: static constexpr int y = 1
   .. member:: static constexpr int z = 2
   .. member:: static constexpr int w = 3
   .. member:: static constexpr int r = 0
   .. member:: static constexpr int g = 1
   .. member:: static constexpr int b = 2
   .. member:: static constexpr int a = 3
   .. member:: static constexpr int s0 = 0
   .. member:: static constexpr int s1 = 1
   .. member:: static constexpr int s2 = 2
   .. member:: static constexpr int s3 = 3
   .. member:: static constexpr int s4 = 4
   .. member:: static constexpr int s5 = 5
   .. member:: static constexpr int s6 = 6
   .. member:: static constexpr int s7 = 7
   .. member:: static constexpr int s8 = 8
   .. member:: static constexpr int s9 = 9
   .. member:: static constexpr int sA = 10
   .. member:: static constexpr int sB = 11
   .. member:: static constexpr int sC = 12
   .. member:: static constexpr int sD = 13
   .. member:: static constexpr int sE = 14
   .. member:: static constexpr int sF = 15

.. class:: template <typename dataT, int numElements> vec

   .. type:: element_type = dataT

   .. function:: vec()
	      explicit vec(const dataT &arg)
	      template <typename... argTN> vec(const argTN&... args)
	      vec(const vec<dataT, numElements> &rhs)
	      template <typename convertT, rounding_mode roundingMode = rounding_mode::automatic> \
	        vec<convertT, numElements> convert() const

   .. function:: operator dataT() const

		 Available only when: numElements == 1

   .. function:: size_t get_count() const

   .. function:: size_t get_size() const

   .. function:: template <typename asT> asT as() const

   .. function:: template<int... swizzleIndexes> \
		   __swizzled_vec__ swizzle() const

   .. function::  __swizzled_vec__ x_ACCESS() const
		  __swizzled_vec__ y_ACCESS() const
		  __swizzled_vec__ z_ACCESS() const
		  __swizzled_vec__ w_ACCESS() const

		  Available only when numElements <= 4

   .. function:: __swizzled_vec__ r() const
		 __swizzled_vec__ g() const
		 __swizzled_vec__ b() const
		 __swizzled_vec__ a() const

		 Available only numElements == 4
  
   .. function::  __swizzled_vec__ s0() const
		  __swizzled_vec__ s1() const
		  __swizzled_vec__ s2() const
		  __swizzled_vec__ s3() const
		  __swizzled_vec__ s4() const
		  __swizzled_vec__ s5() const
		  __swizzled_vec__ s6() const
		  __swizzled_vec__ s7() const
		  __swizzled_vec__ s8() const
		  __swizzled_vec__ s9() const
		  __swizzled_vec__ sA() const
		  __swizzled_vec__ sB() const
		  __swizzled_vec__ sC() const
		  __swizzled_vec__ sD() const
		  __swizzled_vec__ sE() const
		  __swizzled_vec__ sF() const

   .. function:: __swizzled_vec__ lo() const
		 __swizzled_vec__ hi() const
		 __swizzled_vec__ odd() const
		  __swizzled_vec__ even() const

   .. function:: template <access::address_space addressSpace> \
		   void load(size_t offset, multi_ptr<const dataT, addressSpace> ptr)
		 template <access::address_space addressSpace> \
		   void store(size_t offset, multi_ptr<dataT, addressSpace> ptr) const

		   load and store member functions

   .. function:: friend vec operatorOP(const vec &lhs, const vec &rhs)
		 friend vec operatorOP(const vec &lhs, const dataT &rhs)

		 OP is: +, -, \*, /, %

   .. function:: friend vec &operatorOP(vec &lhs, const vec &rhs)
		 friend vec &operatorOP(vec &lhs, const dataT &rhs)

		 OP is: +=, -=, \*=, /=, %=

   .. function:: friend vec &operatorOP(vec &lhs)
		 friend vec operatorOP(vec& lhs, int)

		 OP is: ++, --


   .. function:: friend vec operator&(const vec &lhs, const vec &rhs)
		 friend vec operator&(const vec &lhs, const dataT &rhs)
		 friend vec operator|(const vec &lhs, const vec &rhs)
		 friend vec operator|(const vec &lhs, const dataT &rhs)
		 friend vec operator^(const vec &lhs, const vec &rhs)
		 friend vec operator^(const vec &lhs, const dataT &rhs)

   .. function:: friend vec &operator&=(vec &lhs, const vec &rhs)
		 friend vec &operator&=(vec &lhs, const dataT &rhs)
		 friend vec &operator|=(vec &lhs, const vec &rhs)
		 friend vec &operator|=(vec &lhs, const dataT &rhs)
		 friend vec &operator^=(vec &lhs, const vec &rhs)
		 friend vec &operator^=(vec &lhs, const dataT &rhs)

   .. function:: friend vec<RET, numElements> operator&&(const vec &lhs, const vec &rhs)
		 friend vec<RET, numElements> operator&&(const vec& lhs, const dataT &rhs)
		 friend vec<RET, numElements> operator||(const vec &lhs, const vec &rhs)
		 friend vec<RET, numElements> operator||(const vec& lhs, const dataT &rhs)

   .. function:: friend vec operator<<(const vec &lhs, const vec &rhs)
		 friend vec operator<<(const vec &lhs, const dataT &rhs)
		 friend vec operator>>(const vec &lhs, const vec &rhs)
		 friend vec operator>>(const vec &lhs, const dataT &rhs)

   .. function:: friend vec &operator<<=(vec &lhs, const vec &rhs)
		 friend vec &operator<<=(vec &lhs, const dataT &rhs)
		 friend vec &operator>>=(vec &lhs, const vec &rhs)
		 friend vec &operator>>=(vec &lhs, const dataT &rhs)

   .. function:: friend vec<RET, numElements> operator==(const vec &lhs, const vec &rhs)
		 friend vec<RET, numElements> operator==(const vec &lhs, const dataT &rhs)
		 friend vec<RET, numElements> operator!=(const vec &lhs, const vec &rhs)
		 friend vec<RET, numElements> operator!=(const vec &lhs, const dataT &rhs)
		 friend vec<RET, numElements> operator<(const vec &lhs, const vec &rhs)
		 friend vec<RET, numElements> operator<(const vec &lhs, const dataT &rhs)
		 friend vec<RET, numElements> operator>(const vec &lhs, const vec &rhs)
		 friend vec<RET, numElements> operator>(const vec &lhs, const dataT &rhs)
		 friend vec<RET, numElements> operator<=(const vec &lhs, const vec &rhs)
		 friend vec<RET, numElements> operator<=(const vec &lhs, const dataT &rhs)
		 friend vec<RET, numElements> operator>=(const vec &lhs, const vec &rhs)
		 friend vec<RET, numElements> operator>=(const vec &lhs, const dataT &rhs)

   .. function:: vec<dataT, numElements> &operator=(const vec<dataT, numElements> &rhs)
		 vec<dataT, numElements> &operator=(const dataT &rhs)

   .. function:: friend vec operator~(const vec &v)
		 friend vec<RET, numElements> operator!(const vec &v)

   .. function:: friend vec operatorOP(const dataT &lhs, const vec &rhs)

		 OP is: +, -, \*, /, %

   .. function:: friend vec operator&(const dataT &lhs, const vec &rhs)
		 friend vec operator|(const dataT &lhs, const vec &rhs)
		 friend vec operator^(const dataT &lhs, const vec &rhs)
    
   .. function:: friend vec<RET, numElements> operator&&(const dataT &lhs, const vec &rhs)
		 friend vec<RET, numElements> operator||(const dataT &lhs, const vec &rhs)

   .. function:: friend vec operator<<(const dataT &lhs, const vec &rhs)
		 friend vec operator>>(const dataT &lhs, const vec &rhs)

   .. function:: friend vec<RET, numElements> operator==(const dataT &lhs, const vec &rhs)
		 friend vec<RET, numElements> operator!=(const dataT &lhs, const vec &rhs)
		 friend vec<RET, numElements> operator<(const dataT &lhs, const vec &rhs)
		 friend vec<RET, numElements> operator>(const dataT &lhs, const vec &rhs)
		 friend vec<RET, numElements> operator<=(const dataT &lhs, const vec &rhs)
		 friend vec<RET, numElements> operator>=(const dataT &lhs, const vec &rhs)
