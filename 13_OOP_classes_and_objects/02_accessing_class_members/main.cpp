#include <cstdlib>
#include <iostream>
#include <string>

class Player {
public:
  std::string name;
  int health;
  int xp;

  void talk(std::string text_to_say) {
    std::cout << name << " says " << text_to_say << std::endl;
  };
  bool is_dead() { return health <= 0; };
};

class Account {
public:
  std::string name;
  double balance;

  // NOTE: dummy implementations
  bool withdraw(double amount) {
    balance -= amount;
    return true;
  };

  bool deposite(double amount) {
    balance += amount;
    return true;
  };
};

int main() {
  // TODO: use debugger to walk through this code.
  Player mustafa;
  mustafa.name = "Mustafa";
  mustafa.health = 100;
  mustafa.xp = 13;
  mustafa.talk("Sup?");

  Player *enemy{new Player};
  (*enemy).name = "The enemy";
  enemy->health = 70;
  enemy->xp = 20;
  (*enemy).talk("How you doing?");
  enemy->talk("Howdy");
  delete enemy;

  Account maya_account;
  maya_account.name = "Maya's account";
  maya_account.balance = 5000.0;
  maya_account.deposite(1000.0);

  return EXIT_SUCCESS;
}
