#include <cstdlib>
#include <iostream>
#include <string>

class Player {
public:
  // overwriting the default constructor
  Player() {
    name = "None";
    health = 100;
    xp = 3;
  }

  Player(std::string name_val, int health_val, int xp_val) {
    name = name_val;
    health = health_val;
    xp = xp_val;
  }
  // NOTE: the default constructor won't be defined anymore.

  void set_name(std::string new_name) { name = new_name; }

  std::string get_name() { return name; };

private:
  std::string name;
  int health;
  int xp;
};

int main() {
  Player mustafa{"Mustafa", 100, 13};
  std::cout << mustafa.get_name() << std::endl;
  Player malena;
  malena.set_name("Malena");
  std::cout << malena.get_name() << std::endl;

  Player *enemy{new Player("The enemy", 1000, 100)};
  // TODO: use valgrind to find memory leaks
  delete enemy;

  return EXIT_SUCCESS;
}
