#include "account.h"
#include "savings_account.h"
#include <cstdlib>
#include <iostream>

int main() {
  std::cout << "====================Account====================\n";
  Account acc{};
  acc.deposit(2000);
  acc.withdraw(500);
  Account *p_acc{nullptr};
  p_acc = new Account();
  p_acc->deposit(1000);
  p_acc->withdraw(500);
  delete p_acc;
  std::cout << "====================Savings Account====================\n";
  SavingsAccount sav_acc{};
  sav_acc.deposit(2000);
  sav_acc.withdraw(500);
  SavingsAccount *p_sav_acc{nullptr};
  p_sav_acc = new SavingsAccount();
  p_sav_acc->deposit(1000);
  p_sav_acc->withdraw(500);
  delete p_sav_acc;

  return EXIT_SUCCESS;
}
