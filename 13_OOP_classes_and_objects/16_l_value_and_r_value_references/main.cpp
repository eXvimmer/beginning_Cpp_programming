#include <cstdlib>
#include <iostream>

// NOTE: we donte a reference to a l-value with & and a reference to r-value
// with &&

void func_with_l_value(int &num);  // num is a reference to a l-value int
void func_with_r_value(int &&num); // num is a reference to a r-value int
// overloading
void func(int &num);  // l-value reference
void func(int &&num); // r-value reference

int main() {
  int x{13};            // x is a l-value: it has a name and is addressable
  func_with_l_value(x); // OK

  /* func_with_l_value(200); // ERROR 200 is a r-value */
  /* func_with_r_value(x);   // ERROR */

  func_with_r_value(200); // OK

  func(x);   // OK
  func(200); // OK

  return EXIT_SUCCESS;
}

void func_with_l_value(int &num) {
  std::cout << "l-value reference: " << num << '\n';
}

void func_with_r_value(int &&num) {
  std::cout << "r-value reference: " << num << '\n';
}

void func(int &num) {
  std::cout << "overloaded l-value reference: " << num << '\n';
}

void func(int &&num) {
  std::cout << "overloaded r-value reference: " << num << '\n';
}
