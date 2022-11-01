#include <string>

class Player {
public:
  Player(std::string n, int h, int x);
  Player();
  Player(std::string name_val);
  void set_name(std::string);
  // by using const we guarantee that the method won't change the object, unless
  // we set an attribute as mutable
  std::string get_name() const;

private:
  std::string name;
  int health;
  /* mutable int xp; */
  int xp;
};
