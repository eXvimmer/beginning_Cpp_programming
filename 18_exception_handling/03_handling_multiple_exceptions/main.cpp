#include <iostream>
#include <string>

double calculate_mpg(int miles, int gallons) {
  if (gallons == 0) {
    throw 1;
  } else if (miles < 0 || gallons < 0) {
    throw std::string{"negative value error"};
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
    /* throw "Unknow"; // trigger catch all handler */
    miles_per_gallons = calculate_mpg(miles, gallons);
    std::cout << "Result: " << miles_per_gallons << '\n';
  } catch (int &ex) {
    std::cerr << "Sorry, you cannot divide by zero.\n";
  } catch (std::string &ex) {
    std::cerr << ex << std::endl;
  } catch (...) { // catch all handler
    std::cerr << "unknown exception." << std::endl;
  }
  std::cout << "Bye.\n";
  return 0;
}
