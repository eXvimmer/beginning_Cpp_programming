#include "savings_account.h"
#include <iostream>

SavingsAccount::SavingsAccount() : interest_rate(4.0) {}

SavingsAccount::~SavingsAccount() {}

void SavingsAccount::deposit(double amount) {
  std::cout << "Deposit $" << amount << " to saving account" << std::endl;
}

void SavingsAccount::withdraw(double amount) {
  std::cout << "Withdraw $" << amount << " from saving account" << std::endl;
}
