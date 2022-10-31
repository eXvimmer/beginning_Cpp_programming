#include "Player.h"
#include <iostream>
#include <string>

Player::Player(std::string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val} {}

void Player::talk(std::string text_to_say) {
  std::cout << name << " says \"" << text_to_say << "\"\n";
}

bool Player::is_dead() { return health <= 0; }

std::string Player::get_name() { return name; }
