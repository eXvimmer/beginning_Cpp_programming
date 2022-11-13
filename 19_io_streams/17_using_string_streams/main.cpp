#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

int main() {
  int num{};
  double total{};
  std::string name{};
  std::string info{"Mustafa 100 1234.5"};
  std::istringstream iss{info};
  iss >> name >> num >> total;
  std::cout << std::setw(10) << std::left << name << std::setw(5) << num
            << std::setw(10) << total << std::endl;

  std::cout << "\n========================================================\n";
  std::ostringstream oss{};
  oss << std::setw(10) << std::left << name << std::setw(5) << num
      << std::setw(10) << total << std::endl;
  std::cout << oss.str() << std::endl;

  std::cout << "\n====================Data validation====================\n";
  int value{};
  std::string entry{};
  bool done{false};

  do {
    std::cout << "Please enter an integer: ";
    std::cin >> entry;
    std::istringstream validator{entry};
    if (validator >> value) {
      done = true;
    } else {
      std::cout << "Sorry! That's not an integer.\n";
    }
    // discard the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  } while (!done);
  std::cout << "You entered the integer: " << value << std::endl;

  return 0;
}
