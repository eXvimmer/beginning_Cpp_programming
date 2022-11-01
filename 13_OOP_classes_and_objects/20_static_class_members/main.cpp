#include "player.h"
#include <cstdlib>
#include <iostream>

void display_active_players() {
  auto count{Player::get_players_count()};
  std::cout << count << " active player" << (count == 1 ? "\n" : "s\n");
}

int main() {
  display_active_players();
  Player mustafa{"Msutafa"};
  display_active_players();
  Player malena{"Malena"};
  display_active_players();

  {
    Player maya{"Maya"};
    display_active_players();
    // destructor for the player will be called here
  }
  display_active_players();

  Player *enemy{new Player("The enemy", 1000, 100)};
  display_active_players();
  delete enemy;
  display_active_players();

  return EXIT_SUCCESS;
}
