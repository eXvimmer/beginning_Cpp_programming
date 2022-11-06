#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_

#include "account.h"
#include <ostream>
#include <string>

class SavingsAccount : public Account {
public:
  SavingsAccount(std::string name = def_name, double balance = def_balance,
                 double int_rate = def_int_rate);
  bool deposit(double amount);
  // inherits Account::withdraw methods
  friend std::ostream &operator<<(std::ostream &os,
                                  const SavingsAccount &account);

protected:
  double int_rate;

private:
  static constexpr const char *def_name{"Unnamed Savings Account"};
  static constexpr double def_balance{0.0};
  static constexpr double def_int_rate{0.0};
};

#endif
