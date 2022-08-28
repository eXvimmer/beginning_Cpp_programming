#include <cmath>
#include <cstdlib> // required for rand()
#include <ctime>   // required for time
#include <iostream>

int main() {
  double num{};

  std::cout << "Please enter a number (double): ";
  std::cin >> num;

  std::cout << "The sqrt of " << num << " is: " << std::sqrt(num) << '\n';
  std::cout << "The cubed root of " << num << " is: " << std::cbrt(num) << '\n';

  std::cout << "The sine of " << num << " is: " << std::sin(num) << '\n';
  std::cout << "The cosine of " << num << " is: " << std::cos(num) << '\n';

  std::cout << "The ceil of " << num << " is: " << std::ceil(num) << '\n';
  std::cout << "The floor of " << num << " is: " << std::floor(num) << '\n';
  std::cout << "The round of " << num << " is: " << std::round(num) << '\n';

  double power{};

  std::cout << "\nEnter a power to raise " << num << " to: ";
  std::cin >> power;

  std::cout << num << " raised to the " << power
            << " power is: " << std::pow(num, power) << std::endl;

  std::cout << "\n===================================================\n\n";
  // NOTE: It's better to use random header file if you want to create random
  // numbers

  int random_number{};
  size_t count{10};
  int min{1}, max{6};
  std::cout << "RAND_MAX on my system is: " << RAND_MAX << '\n';

  srand(time(nullptr)); // seed the generator

  std::cout << "\nGenerating " << count << " random numbers.\n";
  for (size_t i{1}; i <= count; ++i) {
    random_number = rand() % max + min; // generate a random number [min, max]
    std::cout << random_number << '\n';
  }

  return 0;
}
