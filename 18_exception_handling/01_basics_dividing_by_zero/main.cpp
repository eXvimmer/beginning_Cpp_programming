#include <iostream>

int main() {
  // NOTE: exception  handling should be used only in synchronous code.
  int miles{}, gallons{};
  double miles_per_gallon{};

  std::cout << "Enter the miles driven: ";
  std::cin >> miles;
  std::cout << "Enter the gallons used: ";
  std::cin >> gallons;

  try {
    if (gallons == 0) {
      throw 1; // NOTE: it's better to throw objects
    }
    miles_per_gallon = static_cast<double>(miles) / gallons;
    std::cout << "Result: " << miles_per_gallon << std::endl;
  } catch (int &ex) {
    std::cerr << "Sorry cannot divide by zero." << std::endl;
  }
  std::cout << "Bye" << std::endl;
  return 0;
}
