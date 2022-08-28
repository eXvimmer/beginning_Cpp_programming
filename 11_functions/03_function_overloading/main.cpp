#include <iostream>
#include <string>
#include <vector>

void print(int);
void print(double);
void print(std::string);
void print(std::string, std::string);
void print(std::vector<std::string>);

int main() {
  std::vector<std::string> vec{"Amadeus", "Rubius", "Morbius", "Dovahkiin"};

  print(0);
  print('M');
  print(13.0);
  print(99.0F); // NOTE: float not a double, float is promoted to double
  print("C-style std::string");
  std::string s{"C++ std::string object"};
  print(s);
  print("Mustafa", s);
  print(vec);
  return 0;
}

void print(int num) { std::cout << "Printing int: " << num << '\n'; }
void print(double num) { std::cout << "Printing double: " << num << '\n'; }
void print(std::string s) {
  std::cout << "Printing std::string: " << s << '\n';
}
void print(std::string s1, std::string s2) {
  std::cout << "Printing 2 std::strings: " << s1 << ", " << s2 << '\n';
}
void print(std::vector<std::string> vec) {
  std::cout << "Printing a std::vector of std::strings:\n";
  for (std::string s : vec) {
    std::cout << s << '\n';
  }
}
