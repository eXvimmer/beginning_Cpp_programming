#include "account.h"
#include <iostream>

Account::Account() : balance(0.0), name{"Account"} {}

Account::~Account() {}

void Account::deposit(double amount) {
  std::cout << "Deposit $" << amount << " to account." << std::endl;
}

void Account::withdraw(double amount) {
  std::cout << "Withdraw $" << amount << " from account." << std::endl;
}
