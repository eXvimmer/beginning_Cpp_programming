#include "checking_account.h"
#include <ostream>

CheckingAccount::CheckingAccount(std::string name, double balance)
    : Account{name, balance} {}

void CheckingAccount::print(std::ostream &os) const {
  os.precision(2);
  os << std::fixed;
  os << "[CheckingAccount: " << name << ": " << balance << "]\n";
}

bool CheckingAccount::deposit(double amount) {
  return Account::deposit(amount);
}

bool CheckingAccount::withdraw(double amount) {
  amount += withdrawal_fee;
  return Account::withdraw(amount);
}

CheckingAccount &operator+=(CheckingAccount &account, double amount) {
  account.deposit(amount);
  return account;
}

CheckingAccount &operator-=(CheckingAccount &account, double amount) {
  account.withdraw(amount);
  return account;
}
