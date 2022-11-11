#include "savings_account.h"

SavingsAccount::SavingsAccount(std::string name, double balance,
                               double int_rate)
    : Account{name, balance}, int_rate{int_rate} {}

void SavingsAccount::print(std::ostream &os) const {
  os.precision(2);
  os << std::fixed;
  os << "[SavingsAccount: " << name << ": " << balance << ", " << int_rate
     << "]\n";
}

bool SavingsAccount::deposit(double amount) {
  amount += amount * int_rate / 100;
  return Account::deposit(amount);
}

bool SavingsAccount::withdraw(double amount) {
  return Account::withdraw(amount);
}

SavingsAccount &operator+=(SavingsAccount &account, double amount) {
  account.deposit(amount);
  return account;
}

SavingsAccount &operator-=(SavingsAccount &account, double amount) {
  account.withdraw(amount);
  return account;
}
