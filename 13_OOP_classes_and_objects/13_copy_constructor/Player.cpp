#include "Player.h"
#include <iostream>

// constructor
Player::Player(std::string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val} {}

// copy constructor
Player::Player(const Player &source)
    /* : name{source.name}, health{source.health}, xp{source.xp}  */
    : Player{source.name, source.health, source.xp} {
  std::cout << "calling copy constructor for " << source.name << std::endl;
}

// destructor
Player::~Player() {
  std::cout << "Destructor called for " << name << std::endl;
}

void Player::talk(std::string text_to_say) {
  std::cout << name << " says \"" << text_to_say << "\"\n";
}

bool Player::is_dead() { return health <= 0; }

std::string Player::get_name() { return name; }

int Player::get_health() { return health; }

int Player::get_xp() { return xp; }
