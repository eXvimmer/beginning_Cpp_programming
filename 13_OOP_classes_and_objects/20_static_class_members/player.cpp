#include "player.h"

int Player::num_players{0};

Player::Player(std::string n, int h, int x) : name{n}, health{h}, xp{x} {
  ++num_players;
}

Player::Player() : Player{"None", 0, 0} {}

Player::Player(std::string name_val) : Player{name_val, 0, 0} {}

Player::Player(const Player &source)
    : Player{source.name, source.health, source.xp} {}

// No move constructor

Player::~Player() { --num_players; }

void Player::set_name(std::string n) { name = n; };

std::string Player::get_name() const { return name; }
int Player::get_health() const { return health; }
int Player::get_xp() const { return xp; }
int Player::get_players_count() { return num_players; }
