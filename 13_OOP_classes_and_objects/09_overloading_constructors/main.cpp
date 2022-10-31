#include "Player.h"
#include <cstdlib>
#include <iostream>

int main() {
  Player mustafa("Mustafa", 0, 13);
  std::cout << mustafa.get_name() << " is " << (mustafa.is_dead() ? "not " : "")
            << "alive\n";
  mustafa.talk("Sup?");

  Player hero{"Hero"};
  Player villain{"Villain"};
  Player *enemy{new Player("The enemy", 1000, 100)};
  std::cout << enemy->get_name() << " " << hero.get_name() << " "
            << villain.get_name() << std::endl;
  delete enemy;
  return EXIT_SUCCESS;
}
