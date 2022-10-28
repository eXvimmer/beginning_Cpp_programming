#include <cstdlib>
#include <iostream>

inline int add_number(int a, int b) { return a + b; } // definition
// NOTE: we "suggest" to the compiler to compile this function 'inline'
// * avoid function call overhead
// * generate inline assembly code
// * faster
// * could cause code bloat
// if you inline a function many times, then you're duplicating function code in
// many places and it could lead to larger binaries.

int main() {
  int result{0};
  result = add_number(4, 9); // call
  std::cout << result << std::endl;
  return EXIT_SUCCESS;
}
