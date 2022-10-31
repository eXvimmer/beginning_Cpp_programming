#include "Player.h"
#include <cstdlib>
#include <iostream>

int main() {
  Player unknown;
  Player hero{"Hero"};
  Player villain{"Villain"};
  Player *enemy{new Player("The enemy", 1000, 100)};
  std::cout << enemy->get_name() << " " << hero.get_name() << " "
            << villain.get_name() << " " << unknown.get_name() <<  std::endl;
  delete enemy;
  return EXIT_SUCCESS;
}
