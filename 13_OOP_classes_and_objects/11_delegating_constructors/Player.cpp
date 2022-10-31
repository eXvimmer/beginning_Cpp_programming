#include "Player.h"
#include <iostream>
#include <string>

// construction initializtion list
Player::Player(std::string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val} {
  std::cout << "Three args constructor\n";
}

// constructor delegation
Player::Player() : Player{"None", 0, 0} {
  std::cout << "No args constructor\n";
}

Player::Player(std::string name_val) : Player{name_val, 0, 0} {
  std::cout << "One arg constructor\n";
}

void Player::talk(std::string text_to_say) {
  std::cout << name << " says \"" << text_to_say << "\"\n";
}

bool Player::is_dead() { return health <= 0; }

std::string Player::get_name() { return name; }
