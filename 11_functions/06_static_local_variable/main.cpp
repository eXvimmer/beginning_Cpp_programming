#include <iostream>

void static_local_example() {
  static int num{5000}; // NOTE: num is local, but ACTS like a global variable
  std::cout << "Local static num is: " << num
            << " in static_local_example - start\n";
  num += 1000;
  std::cout << "Local static num is: " << num
            << " in static_local_example - end\n";
}

int main() {
  static_local_example();
  static_local_example();
  static_local_example();
}
