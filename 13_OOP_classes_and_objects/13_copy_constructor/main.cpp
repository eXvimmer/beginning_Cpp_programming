#include "Player.h"
#include <cstdlib>
#include <iostream>

void display_player(Player p) {
  std::cout << "Name  : " << p.get_name() << '\n';
  std::cout << "Health: " << p.get_health() << '\n';
  std::cout << "XP    : " << p.get_xp() << '\n';
}

int main() {
  Player enemy;
  display_player(enemy);

  Player mustafa{"Mustafa"};
  Player malena{"Malena", 100};
  Player *maya{new Player("Maya", 1000, 100)};
  delete maya;

  return EXIT_SUCCESS;
}
