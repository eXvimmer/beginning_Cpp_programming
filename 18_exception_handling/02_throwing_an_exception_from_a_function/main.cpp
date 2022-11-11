#include <iostream>

double calculate_mpg(int miles, int gallons) {
  if (gallons == 0) {
    throw 1;
  }
  return static_cast<double>(miles) / gallons;
}

int main() {
  int miles{}, gallons{};
  double miles_per_gallons{};

  std::cout << "Enter the miles: ";
  std::cin >> miles;
  std::cout << "Enter the gallons: ";
  std::cin >> gallons;

  try {
    miles_per_gallons = calculate_mpg(miles, gallons);
    std::cout << "Result: " << miles_per_gallons << '\n';
  } catch (int &ex) {
    std::cerr << "Sorry, you cannot divide by zero.\n";
  }
  std::cout << "Bye.\n";
  return 0;
}
