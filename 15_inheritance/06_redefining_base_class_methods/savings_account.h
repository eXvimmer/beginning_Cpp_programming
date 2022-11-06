#ifndef _SAVING_ACCOUNT_H
#define _SAVING_ACCOUNT_H

#include "account.h"
#include <ostream>

class SavingsAccount : public Account {
public:
  friend std::ostream &operator<<(std::ostream &, const SavingsAccount &);
  SavingsAccount();
  SavingsAccount(double balance, double int_rate);
  void deposit(double amount);
  // withdraw is inherited
protected:
  double int_rate;
};

#endif
