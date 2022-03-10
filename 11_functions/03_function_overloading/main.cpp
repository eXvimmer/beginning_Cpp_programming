#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

void print(int);
void print(double);
void print(string);
void print(string, string);
void print(vector<string>);

int main() {
  vector<string> vec{"Amadeus", "Rubius", "Morbius", "Dovahkiin"};

  print(0);
  print('M');
  print(13.0);
  print(99.0F); // NOTE: float not a double, float is promoted to double
  print("C-style string");
  string s{"C++ string object"};
  print(s);
  print("Mustafa", s);
  print(vec);
  return 0;
}

void print(int num) { cout << "Printing int: " << num << '\n'; }
void print(double num) { cout << "Printing double: " << num << '\n'; }
void print(string s) { cout << "Printing string: " << s << '\n'; }
void print(string s1, string s2) {
  cout << "Printing 2 strings: " << s1 << ", " << s2 << '\n';
}
void print(vector<string> vec) {
  cout << "Printing a vector of strings:\n";
  for (string s : vec) {
    cout << s << '\n';
  }
}
