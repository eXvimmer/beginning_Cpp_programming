#include "Mystring.h"
#include <cstdlib>
#include <iostream>

int main() {
  Mystring mustafa{"Mustafa"};
  Mystring malena{"Malena"};
  Mystring maya;

  std::cout << "Enter the third name: ";
  std::cin >> maya;
  std::cout << "The three people are " << mustafa << ", " << malena << " and "
            << maya << std::endl;
  std::cout << "\nEnter three names separated by spaces: ";
  std::cin >> mustafa >> malena >> maya;
  std::cout << "The three people are " << mustafa << ", " << malena << " and "
            << maya << std::endl;

  return EXIT_SUCCESS;
}
