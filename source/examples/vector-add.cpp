#include <vector>
#include <CL/sycl.hpp>

#define SIZE 1024

namespace sycl = cl::sycl;

void show_platforms() {
  auto platforms = sycl::platform::get_platforms();

  for (auto &platform : platforms) {
    std::cout << "Platform: "
	      << platform.get_info<sycl::info::platform::name>()
	      << std::endl;

    auto devices = platform.get_devices();
    for (auto &device : devices ) {
      std::cout << "  Device: "
		<< device.get_info<sycl::info::device::name>()
		<< std::endl;
    }
  }
}

void vec_add(int *a, int *b, int *c) {
  sycl::range<1> a_size{SIZE};

  sycl::default_selector device_selector;
  sycl::queue q(device_selector);

  sycl::buffer<int, 1>  a_device(a, a_size);
  sycl::buffer<int, 1>  b_device(b, a_size);
  sycl::buffer<int, 1>  c_device(c, a_size);

  q.submit([&](sycl::handler &cgh) {
      auto c_res = c_device.get_access<sycl::access::mode::write>(cgh);
      auto a_in = a_device.get_access<sycl::access::mode::read>(cgh);
      auto b_in = b_device.get_access<sycl::access::mode::read>(cgh);

      cgh.parallel_for<class ex1>(a_size,[=](sycl::id<1> idx) {
	  c_res[idx] = a_in[idx] + b_in[idx];
	});
    });
}

int main() {
  int a[SIZE], b[SIZE], c[SIZE];

  for (int i = 0; i<SIZE; ++i) {
    a[i] = i;
    b[i] = -i;
    c[i] = i;
  }

  show_platforms();
  vec_add(a, b, c);

  return 0;
}
