#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>

class Player {
public:
  Player(std::string name_val = "None", int health_val = 0, int xp_val = 0);

  void talk(std::string text_to_say);
  bool is_dead();
  std::string get_name();

private:
  std::string name;
  int health;
  int xp;
};
#endif
