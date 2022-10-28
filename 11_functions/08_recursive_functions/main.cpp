#include <cstdlib>
#include <iostream>

unsigned long long factorial(unsigned long long n) {
  if (n == 0) {
    return 1;
  }
  return n * factorial(n - 1);
}

unsigned long long fibonacci(unsigned long long n) {
  if (n <= 1) {
    return n;
  }
  return fibonacci(n - 2) + fibonacci(n - 1);
}

int main() {
  std::cout << "factorial(8) is: " << factorial(8) << '\n';
  std::cout << "fibonacci(8) is: " << fibonacci(8) << '\n';   // 21
  std::cout << "fibonacci(30) is: " << fibonacci(30) << '\n'; // 832040
  std::cout << "fibonacci(40) is: " << fibonacci(40) << '\n'; // 102334155
  // NOTE: because of the call stack, recursion can be quite resource intensive.
  return EXIT_SUCCESS;
}
