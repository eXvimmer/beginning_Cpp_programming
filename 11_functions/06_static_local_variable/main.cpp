#include <iostream>

using std::cout;

void static_local_example() {
  static int num{5000}; // NOTE: num is local, but ACTS like a global variable
  cout << "Local static num is: " << num
       << " in static_local_example - start\n";
  num += 1000;
  cout << "Local static num is: " << num << " in static_local_example - end\n";
}

int main() {
  static_local_example();
  static_local_example();
  static_local_example();
}
