#include <iostream>

// NOTE: Rules of friendship:
// 1. Friendship must be granted, not taken.
//  * Declared explicitly in the class that is granting the friendship.
//  * Declared in the function prototype with the keyword friend.
// 2. Friendship is not symmetric
//  * Must be explicitly granted.
//    . If A is a friend of B, B is not a friend of A.
// 3. Friendship is not transitive
//  * Must be explicitly granted.
//    . If A is a friend of B & B is a friend of C then A is not a friend of C.
// 4. Friendship is not inherited.

/* class OtherClass { */
/* public: */
/*   void display_player(Player &p) { */
/*     // friend has access to all members */
/*     std::cout << p.name << '\n'; */
/*     std::cout << p.health << '\n'; */
/*     std::cout << p.xp << '\n'; */
/*   } */
/* }; */

// NOTE: this is not the full definition of the Player class, just a summary
class Player {
  friend void display_player(Player &p);
  /* friend void OtherClass::display_player(Player &p); */
  friend class AnotherClass;
  std::string name;
  int health;
  int xp;

public:
  Player(std::string name_val, int health_val, int xp_val)
      : name{name_val}, health{health_val}, xp{xp_val} {}
};

void display_player(Player &p) {
  // NOTE: friend has access to all members
  std::cout << p.name << '\n';
  std::cout << p.health << '\n';
  std::cout << p.xp << '\n';
}
