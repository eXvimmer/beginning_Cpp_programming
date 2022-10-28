#include <iostream>
#include <string>
#include <vector>

void print(int);
void print(double);
void print(std::string);
void print(std::string, std::string);
void print(std::vector<std::string>);

int main() {
  std::vector<std::string> vec{"Amadeus", "Maximus", "Rubius", "Morbius",
                               "Dovahkiin"};

  print(0);
  print('M'); // characters are always promoted to int => 77
  print(13.0);
  print(99.0F);            // float not a double, float is promoted to double
  print("C-style string"); // C-style string is converted to a C++ string
  std::string s{"C++ string object"};
  print(s);
  print("Mustafa", s); // C-style and C++ string
  print(vec);
  return 0;
}

void print(int num) { std::cout << "Printing int: " << num << '\n'; }

void print(double num) { std::cout << "Printing double: " << num << '\n'; }

void print(std::string s) { std::cout << "Printing string: " << s << '\n'; }

void print(std::string s1, std::string s2) {
  std::cout << "Printing 2 strings: " << s1 << ", " << s2 << '\n';
}

void print(std::vector<std::string> vec) {
  std::cout << "Printing a vector of strings:\n";
  /* for (auto s : vec) { */
  for (std::string s : vec) {
    std::cout << s << '\n';
  }
}
