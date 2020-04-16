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

.. class:: template <int dimensions = 1> id

	   :tparam dimensions:

   .. function:: id()
		 id(size_t dim0)
		 id(size_t dim0, size_t dim1)
		 id(size_t dim0, size_t dim1, size_t dim2)
		 id(const range<dimensions> &range)
		 id(const item<dimensions> &item)

		 :arg dim0:
		 :arg dim1:
		 :arg dim2:
		 :arg range:
		 :arg item:
		    

   .. function:: size_t get(int dimension) const

		 :returns:
		    
   .. function:: size_t &operator[](int dimension)

		 :returns:
		    
   .. function:: size_t operator[](int dimension) const

		 :returns:

   .. function:: friend id operator+(const id &lhs, const id &rhs)
		 friend id operator-(const id &lhs, const id &rhs)
		 friend id operator*(const id &lhs, const id &rhs)
		 friend id operator/(const id &lhs, const id &rhs)
		 friend id operator%(const id &lhs, const id &rhs)
		 friend id operator<<(const id &lhs, const id &rhs)
		 friend id operator>>(const id &lhs, const id &rhs)
		 friend id operator&(const id &lhs, const id &rhs)
		 friend id operator|(const id &lhs, const id &rhs)
		 friend id operator^(const id &lhs, const id &rhs)
		 friend id operator&&(const id &lhs, const id &rhs)
		 friend id operator||(const id &lhs, const id &rhs)
		 friend id operator<(const id &lhs, const id &rhs)
		 friend id operator>(const id &lhs, const id &rhs)
		 friend id operator<=(const id &lhs, const id &rhs)
		 friend id operator>=(const id &lhs, const id &rhs)

   .. function:: friend id operator+(const id &lhs, const size_t &rhs)
		 friend id operator-(const id &lhs, const size_t &rhs)
		 friend id operator*(const id &lhs, const size_t &rhs)
		 friend id operator/(const id &lhs, const size_t &rhs)
		 friend id operator%(const id &lhs, const size_t &rhs)
		 friend id operator<<(const id &lhs, const size_t &rhs)
		 friend id operator>>(const id &lhs, const size_t &rhs)
		 friend id operator&(const id &lhs, const size_t &rhs)
		 friend id operator|(const id &lhs, const size_t &rhs)
		 friend id operator^(const id &lhs, const size_t &rhs)
		 friend id operator&&(const id &lhs, const size_t &rhs)
		 friend id operator||(const id &lhs, const size_t &rhs)
		 friend id operator<(const id &lhs, const size_t &rhs)
		 friend id operator>(const id &lhs, const size_t &rhs)
		 friend id operator<=(const id &lhs, const size_t &rhs)
		 friend id operator>=(const id &lhs, const size_t &rhs)

   .. function:: friend id operator+(const size_t &lhs, const id &rhs)
		 friend id operator-(const size_t &lhs, const id &rhs)
		 friend id operator*(const size_t &lhs, const id &rhs)
		 friend id operator/(const size_t &lhs, const id &rhs)
		 friend id operator%(const size_t &lhs, const id &rhs)
		 friend id operator<<(const size_t &lhs, const id &rhs)
		 friend id operator>>(const size_t &lhs, const id &rhs)
		 friend id operator&(const size_t &lhs, const id &rhs)
		 friend id operator|(const size_t &lhs, const id &rhs)
		 friend id operator^(const size_t &lhs, const id &rhs)
		 friend id operator&&(const size_t &lhs, const id &rhs)
		 friend id operator||(const size_t &lhs, const id &rhs)
		 friend id operator<(const size_t &lhs, const id &rhs)
		 friend id operator>(const size_t &lhs, const id &rhs)
		 friend id operator<=(const size_t &lhs, const id &rhs)
		 friend id operator>=(const size_t &lhs, const id &rhs)

   .. function:: friend id operator+=(id &lhs, const id &rhs)
		 friend id operator*=(id &lhs, const id &rhs)
		 friend id operator/=(id &lhs, const id &rhs)
		 friend id operator%=(id &lhs, const id &rhs)
		 friend id operator<<=(id &lhs, const id &rhs)
		 friend id operator>>=(id &lhs, const id &rhs)
		 friend id operator&=(id &lhs, const id &rhs)
		 friend id operator|=(id &lhs, const id &rhs)
		 friend id operator^=(id &lhs, const id &rhs)

   .. function:: friend id operator+=(id &lhs, const size_t &rhs)
		 friend id operator*=(id &lhs, const size_t &rhs)
		 friend id operator/=(id &lhs, const size_t &rhs)
		 friend id operator%=(id &lhs, const size_t &rhs)
		 friend id operator<<=(id &lhs, const size_t &rhs)
		 friend id operator>>=(id &lhs, const size_t &rhs)
		 friend id operator&=(id &lhs, const size_t &rhs)
		 friend id operator|=(id &lhs, const size_t &rhs)
		 friend id operator^=(id &lhs, const size_t &rhs)
