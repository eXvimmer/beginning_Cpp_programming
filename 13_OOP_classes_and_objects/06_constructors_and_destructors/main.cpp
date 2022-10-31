#include <cstdlib>
#include <iostream>

class Player {
public:
  Player() { std::cout << "No arg constructor called" << std::endl; }

  Player(std::string name) {
    std::cout << "String arg constructor called" << std::endl;
  }

  Player(std::string n, int health, int xp) {
    std::cout << "Three args constructor called" << std::endl;
  }

  ~Player() { std::cout << "Destructor called for " << name << std::endl; }

  void set_name(std::string name_val) { name = name_val; }

private:
  std::string name;
  int health;
  int xp;
};

int main() {
  {
    Player mustafa;
    mustafa.set_name("Mustafa");
  }

  {
    Player malena;
    malena.set_name("Malena");
    Player hero("Hero");
    hero.set_name("Hero");
    Player villain("Villain", 100, 2);
    villain.set_name("Villain");
    // NOTE: destructors will be called in reverse order: LIFO, because these
    // are on stack: Villain, Hero and then Malena will be destroyed
  }

  Player *enemy{new Player};
  enemy->set_name("The enemy");
  Player *level_boss{new Player("Level Boss", 1000, 3)};
  level_boss->set_name("Level Boss");

  delete enemy; // this will be destroyed first, because this is on the heap
  delete level_boss; // this will be destroyed after enemy

  return EXIT_SUCCESS;
}
