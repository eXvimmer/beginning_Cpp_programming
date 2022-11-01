#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>

class Player {
public:
  Player(std::string n, int h, int x);
  Player();
  Player(std::string name_val);
  Player(const Player &);
  ~Player();
  void set_name(std::string);
  std::string get_name() const;
  int get_health() const;
  int get_xp() const;
  static int get_players_count(); // NOTE: static methods have only access to
                                  // static properties.

private:
  static int num_players;
  std::string name;
  int health;
  int xp;
};

#endif
