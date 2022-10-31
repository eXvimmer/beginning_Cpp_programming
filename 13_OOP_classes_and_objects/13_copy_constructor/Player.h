#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>

class Player {
public:
  Player(std::string name_val = "None", int health_val = 0, int xp_val = 0);
  Player(const Player &); // copy constructor
  ~Player();

  int get_health();
  std::string get_name();
  int get_xp();
  bool is_dead();
  void talk(std::string text_to_say);

private:
  std::string name;
  int health;
  int xp;
};
#endif
