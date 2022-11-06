#include "savings_account.h"

SavingsAccount::SavingsAccount(double balance, double int_rate)
    : Account{balance}, int_rate{int_rate} {}

SavingsAccount::SavingsAccount() : SavingsAccount{0.0, 0.0} {}

void SavingsAccount::deposit(double amount) {
  amount += amount * int_rate / 100;
  Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const SavingsAccount &account) {
  os << "Saving account balance: " << account.balance
     << ", interest rate: " << account.int_rate << std::endl;
  return os;
}
