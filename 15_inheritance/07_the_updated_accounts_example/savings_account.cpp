#include "savings_account.h"

SavingsAccount::SavingsAccount(std::string name, double balance,
                               double int_rate)
    : Account{name, balance}, int_rate{int_rate} {}

bool SavingsAccount::deposit(double amount) {
  amount += amount * int_rate / 100;
  return Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const SavingsAccount &account) {
  os << "Saving account: " << account.name << ", balance: " << account.balance
     << ", intereset rate: " << account.int_rate << "%\n";
  return os;
}
