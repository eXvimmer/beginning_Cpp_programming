#include <iostream>

// WARN: Don't use macros, use templates instead.

// NOTE: wrap each argument of the macro with parenthesis.

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) ((a > b) ? a : b)
#define SQAURE(a) ((a) * (a))

int main() {
  std::cout << MIN(2, 3) << std::endl;
  std::cout << MIN('A', 'B') << std::endl;
  std::cout << MIN(12.5, 9.2) << std::endl;
  std::cout << MIN(5 + 2 * 2, 7 + 40) << std::endl;
  std::cout << MAX(10, 20) << std::endl;

  std::cout << SQAURE(5) << std::endl;
  std::cout << 100 / SQAURE(5) << std::endl;

  return 0;
}
