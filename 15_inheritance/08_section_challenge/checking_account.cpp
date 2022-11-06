#include "checking_account.h"
#include <ostream>

CheckingAccount::CheckingAccount(std::string name, double balance)
    : Account{name, balance} {}

bool CheckingAccount::withdraw(double amount) {
  amount += withdrawal_fee;
  return Account::withdraw(amount);
}

std::ostream &operator<<(std::ostream &os, const CheckingAccount &account) {
  os << "Checking account: " << account.name << ", balance: " << account.balance
     << ", with $" << CheckingAccount::withdrawal_fee << " per check fee.\n";
  return os;
}

CheckingAccount &operator+=(CheckingAccount &account, double amount) {
  account.deposit(amount);
  return account;
}

CheckingAccount &operator-=(CheckingAccount &account, double amount) {
  account.withdraw(amount);
  return account;
}
