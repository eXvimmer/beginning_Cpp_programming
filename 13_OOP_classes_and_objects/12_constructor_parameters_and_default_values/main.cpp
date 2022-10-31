#include "Player.h"
#include <cstdlib>
#include <iostream>

int main() {
  Player mustafa;
  Player malena{"Malena"};
  Player hero{"Hero", 100};
  Player *enemy{new Player("The enemy", 1000, 100)};
  std::cout << enemy->get_name() << " " << hero.get_name() << " "
            << mustafa.get_name() << " " << malena.get_name() << std::endl;
  delete enemy;
  return EXIT_SUCCESS;
}
