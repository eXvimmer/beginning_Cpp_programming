#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>

class Player {
public:
  Player();
  Player(std::string name_val);
  Player(std::string name_val, int health_val, int xp_val);

  void talk(std::string text_to_say);
  bool is_dead();
  std::string get_name();

private:
  std::string name{};
  int health{};
  int xp{};
};
#endif
