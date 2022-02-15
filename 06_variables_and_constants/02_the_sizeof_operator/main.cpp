#include <climits>
#include <iostream>

using std::cout;

int main() {
  cout << "sizeof information\n";
  cout << "=======================================\n";
  cout << "char: " << sizeof(char) << " bytes.\n";
  cout << "int: " << sizeof(int) << " bytes.\n";
  cout << "unsigned int: " << sizeof(unsigned int) << " bytes.\n";
  cout << "short: " << sizeof(short) << " bytes.\n";
  cout << "long: " << sizeof(long) << " bytes.\n";
  cout << "long long: " << sizeof(long long) << " bytes.\n";
  cout << "=======================================\n";
  cout << "float: " << sizeof(float) << " bytes.\n";
  cout << "double: " << sizeof(double) << " bytes.\n";
  cout << "long double: " << sizeof(long double) << " bytes.\n";
  cout << "=======================================\n";
  cout << "Minimum values:\n";
  cout << "char: " << CHAR_MIN << "\n";
  cout << "int: " << INT_MIN << "\n";
  cout << "short: " << SHRT_MIN << "\n";
  cout << "long: " << LONG_MIN << "\n";
  cout << "long long: " << LLONG_MIN << "\n";
  cout << "=======================================\n";
  cout << "Maximum values:\n";
  cout << "char: " << CHAR_MAX << "\n";
  cout << "int: " << INT_MAX << "\n";
  cout << "short: " << SHRT_MAX << "\n";
  cout << "long: " << LONG_MAX << "\n";
  cout << "long long: " << LLONG_MAX << "\n";
  cout << "=======================================\n";
  cout << "sizeof using variable names:\n";
  int age{29};
  cout << "age is " << sizeof(age) << " bytes.\n";
  // or
  cout << "age is " << sizeof age << " bytes.\n";

  double wage{99.99};
  cout << "wage is " << sizeof(wage) << " bytes.\n";
  // or
  cout << "wage is " << sizeof wage << " bytes.\n";
  return 0;
}
