#include <iomanip>
#include <ios>
#include <iostream>

int main() {
  double num1{123456789.987654321};
  double num2{1234.5678};
  double num3{1234.0};

  // using default settings, with 6 digits of precision
  std::cout << "===================Default=====================\n";
  std::cout << num1 << '\n';
  std::cout << num2 << '\n';
  std::cout << num3 << '\n';

  std::cout
      << "===================2 digits of precision=====================\n";
  std::cout << std::setprecision(2);
  std::cout << num1 << '\n';
  std::cout << num2 << '\n';
  std::cout << num3 << '\n';

  std::cout
      << "===================5 digits of precision=====================\n";
  std::cout << std::setprecision(5);
  std::cout << num1 << '\n';
  std::cout << num2 << '\n';
  std::cout << num3 << '\n';

  std::cout
      << "===================9 digits of precision=====================\n";
  std::cout << std::setprecision(9);
  std::cout << num1 << '\n';
  std::cout << num2 << '\n';
  std::cout << num3 << '\n';

  std::cout << "===================3 digits of precision, "
               "fixed=====================\n";
  std::cout << std::setprecision(3) << std::fixed;
  std::cout << num1 << '\n';
  std::cout << num2 << '\n';
  std::cout << num3 << '\n';

  // NOTE: this is also fixed, because it's set up there
  std::cout << "===================3 digits of precision, "
               "scientific=====================\n";
  std::cout << std::setprecision(3) << std::scientific;
  std::cout << num1 << '\n';
  std::cout << num2 << '\n';
  std::cout << num3 << '\n';

  std::cout << "===================3 digits of precision, "
               "scientific with capital E=====================\n";
  std::cout << std::setprecision(3) << std::scientific << std::uppercase;
  std::cout << num1 << '\n';
  std::cout << num2 << '\n';
  std::cout << num3 << '\n';

  std::cout << "===================3 digits of precision, "
               "fixed with capital E and sign=====================\n";
  std::cout << std::setprecision(3) << std::fixed << std::uppercase
            << std::showpos;
  std::cout << num1 << '\n';
  std::cout << num2 << '\n';
  std::cout << num3 << '\n';

  // back to defaults
  std::cout.unsetf(std::ios::scientific | std::ios::fixed);
  std::cout << std::resetiosflags(std::ios::showpos);

  std::cout << "===================Show trailing zeroes=====================\n";
  std::cout << std::setprecision(10) << std::showpoint;
  std::cout << num1 << '\n';
  std::cout << num2 << '\n';
  std::cout << num3 << '\n';

  std::cout.unsetf(std::ios::scientific | std::ios::fixed);
  std::cout << std::setprecision(6);
  std::cout << std::resetiosflags(std::ios::showpos);
  std::cout << std::resetiosflags(std::ios::showpoint);

  std::cout << "===================Default=====================\n";
  std::cout << num1 << '\n';
  std::cout << num2 << '\n';
  std::cout << num3 << '\n';

  return 0;
}
