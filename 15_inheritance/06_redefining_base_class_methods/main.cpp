#include "account.h"
#include "savings_account.h"
#include <cstdlib>
#include <iostream>

int main() {
  std::cout << "====================Account====================\n";
  Account account;
  account.deposit(1000);
  account.withdraw(500);
  std::cout << account;
  std::cout << "=================Saving Account=================\n";
  SavingsAccount savings_account{1000, 5.0};
  savings_account.deposit(1000);
  savings_account.withdraw(2000);
  std::cout << savings_account;
  return EXIT_SUCCESS;
}
