#include <cstdlib>
#include <iostream>
#include <string>

struct Person {
  std::string name; // public by default
  std::string get_name() { return name; };
};
// NOTE: use structs for simple objects with public access. Don't declare
// methods in structs. If you want methods, getters and setters or private
// properties then use classes.

int main() {
  Person p;
  p.name = "Mustafa";
  std::cout << p.get_name() << std::endl;
  return EXIT_SUCCESS;
}
