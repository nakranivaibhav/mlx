#include "/Users/vaibhavnakrani/mlx/mlx/backend/common/arange.h"
#include <iostream>

int main() {
  // Create an array of size 10 and dtype float32
  mlx::core::array a(10, mlx::core::float32);

  // Call the arange function with start = 0.0, step = 0.5
  mlx::core::arange({}, a, 0.0, 0.5);

  // Print the array contents
  std::cout << "a = " << a << "\n";

  // Check if the array contains the expected values
  bool passed = true;
  for (int i = 0; i < 10; ++i) {
    if (a.data<float>()[i] != i * 0.5) {
      passed = false;
      break;
    }
  }

  // Print the test result
  if (passed) {
    std::cout << "Test passed!\n";
  } else {
    std::cout << "Test failed!\n";
  }

  return 0;
}
