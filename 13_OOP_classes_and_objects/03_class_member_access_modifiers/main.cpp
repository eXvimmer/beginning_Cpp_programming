#include <cstdlib>
#include <iostream>
#include <string>

class Player {
private: // private is default
  std::string name{"Player"};
  int health;
  int xp;

public:
  void talk(std::string text_to_say) {
    std::cout << name << " says " << text_to_say << std::endl;
  };
  bool is_dead();
};

int main() {
  Player mustafa;
  /* mustafa.name = "Mustafa"; // ERROR */
  /* std::cout << mustfa.health << std::endl; // ERROR */
  mustafa.talk("Sup?");
  return EXIT_SUCCESS;
}
