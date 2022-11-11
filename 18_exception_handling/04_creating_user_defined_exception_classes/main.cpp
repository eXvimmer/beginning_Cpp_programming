#include <iostream>

class DevideByZeroException {};
class NegativeValueException {};
// NOTE: we could make these classes as complicated as we need

double calculate_mpg(int miles, int gallons) {
  if (gallons == 0) {
    throw DevideByZeroException();
    // NOTE: throw by value and catch by reference or const reference
  } else if (miles < 0 || gallons < 0) {
    throw NegativeValueException();
  }
  return static_cast<double>(miles) / gallons;
}

int main() {
  int miles{}, gallons{};
  double miles_per_gallons{};

  std::cout << "Enter the miles driven: ";
  std::cin >> miles;
  std::cout << "Enter the gallons used: ";
  std::cin >> gallons;

  try {
    miles_per_gallons = calculate_mpg(miles, gallons);
    std::cout << "Result: " << miles_per_gallons << '\n';
  } catch (/* const */ DevideByZeroException &ex) {
    std::cerr << "cannot divide by zero" << std::endl;
  } catch (const NegativeValueException &ex) {
    std::cerr << "miles and gallons cannot be negative" << std::endl;
  } catch (...) {
    std::cerr << "something went wrong" << std::endl;
  }
  std::cout << "Bye\n";
  return 0;
}
