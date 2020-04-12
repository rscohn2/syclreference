//==----------- stl.hpp - basic STL implementation -------------------------==//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#pragma once

// 4.5 C++ Standard library classes required for the interface

#include <CL/sycl/detail/defines.hpp>

#include <exception>
#include <functional>
#include <memory>
#include <mutex>
#include <string>
#include <vector>

__SYCL_INLINE_NAMESPACE(cl) {
namespace sycl {

 template < class T, class Alloc = std::allocator<T> >

 /// STL vector
 using vector_class = std::vector<T, Alloc>;

 /// STL string
 using string_class = std::string;

 /// STL function
 template <class Sig>
 using function_class = std::function<Sig>;

 /// STL mutex
 using mutex_class = std::mutex;

 /// STL unique_ptr
 template <class T, class Deleter = std::default_delete<T>>
 using unique_ptr_class = std::unique_ptr<T, Deleter>;

 /// STL shared_ptr
 template <class T>
 using shared_ptr_class = std::shared_ptr<T>;

 /// STL weak_ptr
 template <class T>
 using weak_ptr_class = std::weak_ptr<T>;

 /// STL hash
 template <class T>
 using hash_class = std::hash<T>;

 /// STL exception_ptr
 using exception_ptr_class = std::exception_ptr;

 template <typename T, typename... ArgsT>
 unique_ptr_class<T> make_unique_ptr(ArgsT &&... Args) {
   return unique_ptr_class<T>(new T(std::forward<ArgsT>(Args)...));
 }
} // sycl
} // cl

