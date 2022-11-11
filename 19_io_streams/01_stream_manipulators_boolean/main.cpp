#include <iomanip>
#include <ios>
#include <iostream>

int main() {
  std::cout << "noboolalpha - default (10 == 10): " << (10 == 10) << '\n'; // 1
  std::cout << "noboolalpha - default (10 == 20): " << (10 == 20) << '\n'; // 0

  // using a manipulator
  std::cout << std::boolalpha; // switch to true/false
  std::cout << "boolalpha (10 == 10): " << (10 == 10) << '\n'; // true
  std::cout << "boolalpha (10 == 20): " << (10 == 20) << '\n'; // false

  // still set to true/false
  std::cout << "boolalpha (10 == 10): " << (10 == 10) << '\n'; // true
  std::cout << "boolalpha (10 == 20): " << (10 == 20) << '\n'; // false

  std::cout << std::noboolalpha;
  std::cout << "noboolalpha - default (10 == 10): " << (10 == 10) << '\n'; // 1
  std::cout << "noboolalpha - default (10 == 20): " << (10 == 20) << '\n'; // 0

  // using setf method
  std::cout.setf(std::ios::boolalpha);
  std::cout << "boolalpha (10 == 10): " << (10 == 10) << '\n'; // true
  std::cout << "boolalpha (10 == 20): " << (10 == 20) << '\n'; // false

  std::cout << std::resetiosflags(std::ios::boolalpha);      // needs iomanip
  std::cout << "Default (10 == 10): " << (10 == 10) << '\n'; // 1
  std::cout << "Default (10 == 20): " << (10 == 20) << '\n'; // 0
  return 0;
}
