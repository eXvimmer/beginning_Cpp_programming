#include "Account.h"
#include <cstdlib>
#include <iostream>

int main() {
  Account mustafa_account;
  mustafa_account.set_name("Mustafa");
  mustafa_account.set_balance(1000.0);

  if (mustafa_account.deposit(2000.0)) {
    std::cout << "Deposit OK" << '\n';
  } else {
    std::cout << "Deposit Not Allowed" << '\n';
  }

  if (mustafa_account.withdraw(500.0)) {
    std::cout << "Withdrawal OK" << '\n';
  } else {
    std::cout << "Not sufficient founds" << '\n';
  }

  if (mustafa_account.withdraw(4000.0)) {
    std::cout << "Withdrawal OK" << '\n';
  } else {
    std::cout << "Not sufficient founds" << '\n';
  }

  return EXIT_SUCCESS;
}
