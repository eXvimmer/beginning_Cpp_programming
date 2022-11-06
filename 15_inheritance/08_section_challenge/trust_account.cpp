#include "trust_account.h"
#include "savings_account.h"

TrustAccount::TrustAccount(std::string name, double balance, double int_rate)
    : SavingsAccount{name, balance, int_rate}, withdrawal_count{0} {}

bool TrustAccount::deposit(double amount) {
  amount += (amount >= bonus_threshold) ? bonus_amount : 0.0;
  return SavingsAccount::deposit(amount);
}

bool TrustAccount::withdraw(double amount) {
  if (withdrawal_count >= max_withdrawal_count ||
      amount > balance * max_withdrawal_percentage) {
    return false;
  }
  ++withdrawal_count;
  return SavingsAccount::withdraw(amount);
}

std::ostream &operator<<(std::ostream &os, const TrustAccount &account) {
  os << "Trust account: " << account.name << ", balance: $" << account.balance
     << ", intereset rate: " << account.int_rate << "%, withdrawals "
     << account.withdrawal_count << std::endl;
  return os;
}

TrustAccount &operator+=(TrustAccount &account, double amount) {
  account.deposit(amount);
  return account;
}

TrustAccount &operator-=(TrustAccount &account, double amount) {
  account.withdraw(amount);
  return account;
}
