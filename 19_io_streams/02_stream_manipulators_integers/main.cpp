#include <iomanip>
#include <ios>
#include <iostream>

int main() {
  int num{255};
  std::cout << "====================================================\n";
  std::cout << std::dec << num << '\n'; // 255, std::dec is default
  std::cout << std::oct << num << '\n'; // 377
  std::cout << std::hex << num << '\n'; // ff

  // show base
  std::cout << "====================================================\n";
  std::cout << std::showbase;
  std::cout << std::dec << num << '\n'; // 255
  std::cout << std::oct << num << '\n'; // 0377
  std::cout << std::hex << num << '\n'; // 0xff
  std::cout << std::noshowbase;

  // make it uppercase
  std::cout << "====================================================\n";
  std::cout << std::showbase << std::uppercase;
  std::cout << std::dec << num << '\n'; // 255
  std::cout << std::oct << num << '\n'; // 0377
  std::cout << std::hex << num << '\n'; // 0XFF
  std::cout << std::noshowbase << std::nouppercase;

  // show sign
  std::cout << "====================================================\n";
  std::cout << std::showbase << std::uppercase << std::showpos;
  std::cout << std::dec << num << '\n'; // +255
  std::cout << std::oct << num << '\n'; // 0377
  std::cout << std::hex << num << '\n'; // 0XFF
  std::cout << std::noshowbase << std::nouppercase << std::noshowpos;

  std::cout << "====================================================\n";
  // using the setf methods and format flags
  /* std::cout.setf(std::ios::basefield); // back to decimal */
  std::cout.setf(std::ios::showbase);
  std::cout.setf(std::ios::uppercase);
  std::cout.setf(std::ios::showpos);

  std::cout << std::dec << num << '\n'; // +255
  std::cout << std::oct << num << '\n'; // 0377
  std::cout << std::hex << num << '\n'; // 0XFF

  std::cout << std::resetiosflags(std::ios::showbase);
  std::cout << std::resetiosflags(std::ios::uppercase);
  std::cout << std::resetiosflags(std::ios::showpos);

  std::cout << "====================================================\n";
  std::cout << std::dec << num << '\n'; // 255
  std::cout << std::oct << num << '\n'; // 377
  std::cout << std::hex << num << '\n'; // ff
  return 0;
}
