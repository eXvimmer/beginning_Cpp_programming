#include "player.h"
#include <cstdlib>
#include <iostream>

void display_player_name(const Player &p) {
  std::cout << p.get_name() << std::endl;
}

int main() {
  const Player villain{"Villain", 1000, 100};
  Player hero{"Hero"};
  display_player_name(villain);
  display_player_name(hero);

  return EXIT_SUCCESS;
}
