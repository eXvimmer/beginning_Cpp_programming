#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

void ruler() {
  std::cout << "\n12345678901234567890123456789012345678901234567890\n";
}

void header(const char *message, int width = 50) {
  std::cout << '\n'
            << std::setw(width) << std::left << std::setfill('=') << message
            << std::endl;
}

int main() {
  int num1{1234};
  double num2{1234.5678};
  std::string hello{"Hello"};

  header("Default");
  ruler();
  std::cout << num1 << num2 << hello << std::endl;

  header("One per line");
  ruler();
  std::cout << num1 << '\n';
  std::cout << num2 << '\n';
  std::cout << hello << '\n';

  // NOTE: right justified by default
  header("width 10 for num1");
  ruler();
  std::cout << std::setw(10) << num1 << num2 << hello << std::endl;

  header("width 10 for num1 and num2");
  ruler();
  std::cout << std::setw(10) << num1 << std::setw(10) << num2 << hello
            << std::endl;

  header("width 10 for num1 and num2 and hello");
  ruler();
  std::cout << std::setw(10) << num1 << std::setw(10) << num2 << std::setw(10)
            << hello << std::endl;

  header("width 10 for all and left justified");
  ruler();
  std::cout << std::setw(10) << std::left << num1 << std::setw(10) << std::left
            << num2 << std::setw(10) << std::left << hello << std::endl;

  header("fill with dash");
  ruler();
  std::cout << std::setfill('-');
  std::cout << std::setw(10) << std::left << num1 << std::setw(10) << std::left
            << num2 << std::setw(10) << std::left << hello << std::endl;

  header("fill with different characters");
  ruler();
  std::cout << std::setw(10) << std::left << std::setfill('*') << num1
            << std::setw(10) << std::left << std::setfill('#') << num2
            << std::setw(10) << std::left << std::setfill('-') << hello
            << std::endl;
  return 0;
}
