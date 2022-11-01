#include "player.h"

Player::Player(std::string n, int h, int x) : name{n}, health{h}, xp{x} {}

Player::Player() : Player{"None", 0, 0} {}

Player::Player(std::string name_val) : Player{name_val, 0, 0} {}

std::string Player::get_name() const {
  /* xp = 30; // this is ok, if we set xp to be mutable */
  return name;
}

void Player::set_name(std::string n) { name = n; };
