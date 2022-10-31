#include <cstdlib>
#include <iostream>
#include <string>

class Player {
public:
  // NOTE: C++ creates a defautl constructor if none is defined
  void set_name(std::string new_name) { name = new_name; }

  std::string get_name() { return name; };

private:
  std::string name;
  int health;
  int xp;
};

int main() {
  Player mustafa; // the default constructor, created by C++, will be called
  mustafa.set_name("Mustafa");
  std::cout << mustafa.get_name() << std::endl;

  return EXIT_SUCCESS;
}
