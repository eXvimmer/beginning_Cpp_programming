#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

class Player {
  // atributes
  // NOTE: since C++11 you can initialize attributes
  std::string name{"Player"};
  int health{100};
  int xp{0};

  // methods
  void talk(std::string text_to_say);
  bool is_dead();
};

class Account {
  std::string name{"Account"};
  double balance{0.0};

  bool deposite(double);
  bool withdraw(double);
};

int main() {
  // TODO: run this program in debugger and step through it.
  Player lilith;
  Player lucifer;
  Player players[]{lucifer, lilith};
  std::vector<Player> players_vec{lilith};
  players_vec.push_back(lucifer);
  Player *enemy{nullptr};
  enemy = new Player; // NOTE: new means that this object will be on the heap
  delete enemy;

  Account maya;
  return EXIT_SUCCESS;
}
