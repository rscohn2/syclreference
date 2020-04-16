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

.. namespace-push:: access

.. enum-class:: address_space

   .. enumerator:: global_space
		   local_space
		   constant_space
		   private_space

.. namespace-pop::

.. class:: template <typename ElementType, access::address_space Space> multi_ptr

   .. type:: element_type = ElementType
	     difference_type = std::ptrdiff_t

   .. type:: pointer_t = ElementType*
	     const_pointer_t = const ElementType*
	     reference_t = ElementType&
	     const_reference_t = const ElementType&

	     Implementation defined pointer and reference types that
	     correspond to SYCL/OpenCL interoperability types for
	     OpenCL C functions

   .. member:: static constexpr access::address_space address_space = Space

   .. function:: multi_ptr()
		 multi_ptr(const multi_ptr&)
		 multi_ptr(multi_ptr&&)
		 multi_ptr(pointer_t)
		 multi_ptr(ElementType*)
		 multi_ptr(std::nullptr_t)
                 template <int dimensions, access::mode Mode, access::placeholder isPlaceholder> \
                   multi_ptr(accessor<ElementType, dimensions, Mode, access::target::global_buffer, isPlaceholder>)
                 template <int dimensions, access::mode Mode, access::placeholder isPlaceholder> \
                   multi_ptr(accessor<ElementType, dimensions, Mode, access::target::local, isPlaceholder>)
                 template <int dimensions, access::mode Mode, access::placeholder isPlaceholder> \
                   multi_ptr(accessor<ElementType, dimensions, Mode, access::target::constant_buffer, isPlaceholder>)
		   
   .. function:: ~multi_ptr()

   .. rubric:: Assignment and access operators

   .. function:: multi_ptr &operator=(const multi_ptr&)
		 multi_ptr &operator=(multi_ptr&&)
                 multi_ptr &operator=(pointer_t)
		 multi_ptr &operator=(ElementType*)
		 multi_ptr &operator=(std::nullptr_t)

   .. function:: friend ElementType& operator*(const multi_ptr& mp)

   .. function:: ElementType* operator->() const

   .. function:: pointer_t get() const

                 :returns: underlying OpenCL C pointer
		 
   .. function:: operator ElementType*() const
		 
		 Implicit conversion to the underlying pointer type

   .. function:: operator multi_ptr<void, Space>() const
		 operator multi_ptr<const void, Space>() const
		 operator multi_ptr<const ElementType, Space>() const

		 Implicit conversion to a multi_ptr

   .. function::  void prefetch(size_t numElements) const
		  
   .. rubric:: Arithmetic operators
	       
   .. function:: friend multi_ptr& operator++(multi_ptr& mp)
		 friend multi_ptr operator++(multi_ptr& mp, int)
		 friend multi_ptr& operator--(multi_ptr& mp)
		 friend multi_ptr operator--(multi_ptr& mp, int)
		 friend multi_ptr& operator+=(multi_ptr& lhs, difference_type r)
		 friend multi_ptr& operator-=(multi_ptr& lhs, difference_type r)
		 friend multi_ptr operator+(const multi_ptr& lhs, difference_type r)
		 friend multi_ptr operator-(const multi_ptr& lhs, difference_type r)

   .. rubric:: Relational operators
    
   .. function:: friend bool operator==(const multi_ptr& lhs, const multi_ptr& rhs)
		 friend bool operator!=(const multi_ptr& lhs, const multi_ptr& rhs)
		 friend bool operator<(const multi_ptr& lhs, const multi_ptr& rhs)
		 friend bool operator>(const multi_ptr& lhs, const multi_ptr& rhs)
		 friend bool operator<=(const multi_ptr& lhs, const multi_ptr& rhs)
		 friend bool operator>=(const multi_ptr& lhs, const multi_ptr& rhs)
		 friend bool operator==(const multi_ptr& lhs, std::nullptr_t)
		 friend bool operator!=(const multi_ptr& lhs, std::nullptr_t)
		 friend bool operator<(const multi_ptr& lhs, std::nullptr_t)
		 friend bool operator>(const multi_ptr& lhs, std::nullptr_t)
		 friend bool operator<=(const multi_ptr& lhs, std::nullptr_t)
		 friend bool operator>=(const multi_ptr& lhs, std::nullptr_t)
		 friend bool operator==(std::nullptr_t, const multi_ptr& rhs)
		 friend bool operator!=(std::nullptr_t, const multi_ptr& rhs)
		 friend bool operator<(std::nullptr_t, const multi_ptr& rhs)
		 friend bool operator>(std::nullptr_t, const multi_ptr& rhs)
		 friend bool operator<=(std::nullptr_t, const multi_ptr& rhs)
		 friend bool operator>=(std::nullptr_t, const multi_ptr& rhs)

