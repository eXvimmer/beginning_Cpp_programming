#include <cmath>
#include <cstdlib> // required for rand()
#include <ctime>   // required for time
#include <iostream>

using std::cin;
using std::cout;

int main() {
  double num{};

  cout << "Please enter a number (double): ";
  cin >> num;

  cout << "The sqrt of " << num << " is: " << std::sqrt(num) << '\n';
  cout << "The cubed root of " << num << " is: " << std::cbrt(num) << '\n';

  cout << "The sine of " << num << " is: " << std::sin(num) << '\n';
  cout << "The cosine of " << num << " is: " << std::cos(num) << '\n';

  cout << "The ceil of " << num << " is: " << std::ceil(num) << '\n';
  cout << "The floor of " << num << " is: " << std::floor(num) << '\n';
  cout << "The round of " << num << " is: " << std::round(num) << '\n';

  double power{};

  cout << "\nEnter a power to raise " << num << " to: ";
  cin >> power;

  cout << num << " raised to the " << power
       << " power is: " << std::pow(num, power) << std::endl;

  cout << "\n===================================================\n\n";
  // NOTE: It's better to use random header file if you want to create random
  // numbers

  int random_number{};
  size_t count{10};
  int min{1}, max{6};
  cout << "RAND_MAX on my system is: " << RAND_MAX << '\n';

  srand(time(nullptr)); // seed the generator

  cout << "\nGenerating " << count << " random numbers.\n";
  for (size_t i{1}; i <= count; ++i) {
    random_number = rand() % max + min; // generate a random number [min, max]
    cout << random_number << '\n';
  }

  return 0;
}
