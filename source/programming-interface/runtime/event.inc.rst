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

.. class:: event

   .. rubric:: Constructors
	       
   .. function:: event()
		 event(cl_event clEvent, const context& syclContext)

		 :args clEvent:
		 :args syclContext:

   .. function:: cl_event get()

		 :returns:

   .. function:: bool is_host() const

		 :returns:

   .. function:: vector_class<event> get_wait_list()

		 :returns:

   .. function:: void wait()

   .. function:: static void wait(const vector_class<event> &eventList)
		 void wait_and_throw()
		 static void wait_and_throw(const vector_class<event> &eventList)
		 
		 :args eventList:

   .. function:: template <info::event param> \
		   typename info::param_traits<info::event, param>::return_type get_info() const

		 :tparam param:
		 :returns:

   .. function:: template <info::event_profiling param> \
		   typename info::param_traits<info::event_profiling, param>::return_type get_profiling_info() const

		 :tparam param:
		 :returns:

.. namespace-push:: info

.. enum-class:: event

   .. enumerator:: command_execution_status
		   reference_count

.. enum-class:: event_command_status

   .. enumerator:: submitted
		   running
		   complete

.. enum-class:: event_profiling

   .. enumerator:: command_submit
		   command_start
		   command_end

.. namespace-pop::
