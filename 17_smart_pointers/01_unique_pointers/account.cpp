#include "account.h"

Account::Account(std::string name, double balance)
    : name{name}, balance{balance} {}

void Account::print(std::ostream &os) const {
  os.precision(2);
  os << std::fixed;
  os << "[Account: " << name << ": " << balance << "]\n";
}

bool Account::deposit(double amount) {
  if (amount > 0) {
    balance += amount;
    return true;
  }
  return false;
}

bool Account::withdraw(double amount) {
  if (balance - amount >= 0) {
    balance -= amount;
    return true;
  }
  return false;
}

/* double Account::get_balance() const { return balance; } */

Account &operator+=(Account &account, double amount) {
  account.deposit(amount);
  return account;
}

Account &operator-=(Account &account, double amount) {
  account.withdraw(amount);
  return account;
}
