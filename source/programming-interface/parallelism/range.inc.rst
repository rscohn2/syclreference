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

.. class:: template <int dimensions = 1> range

   .. function:: range(size_t dim0)
		 range(size_t dim0, size_t dim1)
		 range(size_t dim0, size_t dim1, size_t dim2)

		 :arg dim0:
		 :arg dim1:
		 :arg dim2:

   .. function:: size_t get(int dimension) const

		 :arg dimension:
		 :returns:
		    
   .. function:: size_t &operator[](int dimension)
		 size_t operator[](int dimension) const

		 :arg dimension:
		 :returns:

   .. function:: size_t size() const

   .. function:: friend range operator+(const range &lhs, const range &rhs)
		 friend range operator-(const range &lhs, const range &rhs)
		 friend range operator*(const range &lhs, const range &rhs)
		 friend range operator/(const range &lhs, const range &rhs)
		 friend range operator%(const range &lhs, const range &rhs)
		 friend range operator<<(const range &lhs, const range &rhs)
		 friend range operator>>(const range &lhs, const range &rhs)
		 friend range operator&(const range &lhs, const range &rhs)
		 friend range operator|(const range &lhs, const range &rhs)
		 friend range operator^(const range &lhs, const range &rhs)
		 friend range operator&&(const range &lhs, const range &rhs)
		 friend range operator||(const range &lhs, const range &rhs)
		 friend range operator<(const range &lhs, const range &rhs)
		 friend range operator>(const range &lhs, const range &rhs)
		 friend range operator<=(const range &lhs, const range &rhs)
		 friend range operator>=(const range &lhs, const range &rhs)

   .. function:: friend range operator+(const range &lhs, const size_t &rhs)
		 friend range operator-(const range &lhs, const size_t &rhs)
		 friend range operator*(const range &lhs, const size_t &rhs)
		 friend range operator/(const range &lhs, const size_t &rhs)
		 friend range operator%(const range &lhs, const size_t &rhs)
		 friend range operator<<(const range &lhs, const size_t &rhs)
		 friend range operator>>(const range &lhs, const size_t &rhs)
		 friend range operator&(const range &lhs, const size_t &rhs)
		 friend range operator|(const range &lhs, const size_t &rhs)
		 friend range operator^(const range &lhs, const size_t &rhs)
		 friend range operator&&(const range &lhs, const size_t &rhs)
		 friend range operator||(const range &lhs, const size_t &rhs)
		 friend range operator<(const range &lhs, const size_t &rhs)
		 friend range operator>(const range &lhs, const size_t &rhs)
		 friend range operator<=(const range &lhs, const size_t &rhs)
		 friend range operator>=(const range &lhs, const size_t &rhs)

   .. function:: friend range operator+(const size_t &lhs, const range &rhs)
		 friend range operator-(const size_t &lhs, const range &rhs)
		 friend range operator*(const size_t &lhs, const range &rhs)
		 friend range operator/(const size_t &lhs, const range &rhs)
		 friend range operator%(const size_t &lhs, const range &rhs)
		 friend range operator<<(const size_t &lhs, const range &rhs)
		 friend range operator>>(const size_t &lhs, const range &rhs)
		 friend range operator&(const size_t &lhs, const range &rhs)
		 friend range operator|(const size_t &lhs, const range &rhs)
		 friend range operator^(const size_t &lhs, const range &rhs)
		 friend range operator&&(const size_t &lhs, const range &rhs)
		 friend range operator||(const size_t &lhs, const range &rhs)
		 friend range operator<(const size_t &lhs, const range &rhs)
		 friend range operator>(const size_t &lhs, const range &rhs)
		 friend range operator<=(const size_t &lhs, const range &rhs)
		 friend range operator>=(const size_t &lhs, const range &rhs)

   .. function:: friend range operator+=(const range &lhs, const range &rhs)
		 friend range operator-=(const range &lhs, const range &rhs)
		 friend range operator*=(const range &lhs, const range &rhs)
		 friend range operator/=(const range &lhs, const range &rhs)
		 friend range operator%=(const range &lhs, const range &rhs)
		 friend range operator<<=(const range &lhs, const range &rhs)
		 friend range operator>>=(const range &lhs, const range &rhs)
		 friend range operator&=(const range &lhs, const range &rhs)
		 friend range operator|=(const range &lhs, const range &rhs)
		 friend range operator^=(const range &lhs, const range &rhs)

   .. function:: friend range operator+=(const range &lhs, const size_t &rhs)
		 friend range operator-=(const range &lhs, const size_t &rhs)
		 friend range operator*=(const range &lhs, const size_t &rhs)
		 friend range operator/=(const range &lhs, const size_t &rhs)
		 friend range operator%=(const range &lhs, const size_t &rhs)
		 friend range operator<<=(const range &lhs, const size_t &rhs)
		 friend range operator>>=(const range &lhs, const size_t &rhs)
		 friend range operator&=(const range &lhs, const size_t &rhs)
		 friend range operator|=(const range &lhs, const size_t &rhs)
		 friend range operator^=(const range &lhs, const size_t &rhs)
