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

.. enum-class:: stream_manipulator

   .. enumerator:: flush
		   dec
		   hex
		   oct
		   noshowbase
		   showbase
		   noshowpos
		   showpos
		   endl
		   fixed
		   scientific
		   hexfloat
		   defaultfloat

.. var:: const stream_manipulator flush = stream_manipulator::flush

.. var:: const stream_manipulator dec = stream_manipulator::dec

.. var:: const stream_manipulator hex = stream_manipulator::hex

.. var:: const stream_manipulator oct = stream_manipulator::oct

.. var:: const stream_manipulator noshowbase = stream_manipulator::noshowbase

.. var:: const stream_manipulator showbase = stream_manipulator::showbase

.. var:: const stream_manipulator noshowpos = stream_manipulator::noshowpos

.. var:: const stream_manipulator showpos = stream_manipulator::showpos

.. var:: const stream_manipulator endl = stream_manipulator::endl

.. var:: const stream_manipulator fixed = stream_manipulator::fixed

.. var:: const stream_manipulator scientific = stream_manipulator::scientific

.. var:: const stream_manipulator hexfloat = stream_manipulator::hexfloat

.. var:: const stream_manipulator defaultfloat = stream_manipulator::defaultfloat

.. function:: __precision_manipulator__ setprecision(int precision)

.. function:: __width_manipulator__ setw(int width)

.. class:: stream

   .. function:: stream(size_t totalBufferSize, size_t workItemBufferSize, handler& cgh)

   .. function:: size_t get_size() const

   .. function:: size_t get_work_item_buffer_size() const

   .. function:: size_t get_max_statement_size() const
		 
		 :func:`get_max_statement_size()` has the same
                 functionality as :func:`get_work_item_buffer_size()`,
                 and is provided for backward compatibility.
                 get_max_statement_size() is a deprecated query.

.. class template <typename T> const stream& operator<<(const stream& os, const T &rhs)
