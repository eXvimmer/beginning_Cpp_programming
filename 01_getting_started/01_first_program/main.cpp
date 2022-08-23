#include <iostream>

int main() {
  int favorite_number{0};
  std::cout << "Enter your favorite number between 1 and 100\n";
  std::cin >> favorite_number;
  std::cout << "Amazing " << favorite_number << " is my favorite number too."
            << std::endl;

  return 0;
}
