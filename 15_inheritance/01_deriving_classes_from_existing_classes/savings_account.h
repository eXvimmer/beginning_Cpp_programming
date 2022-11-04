#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_

#include "account.h"

class SavingsAccount : public Account {
public:
  SavingsAccount();
  ~SavingsAccount();
  void deposit(double amount);
  void withdraw(double amount);
  double interest_rate;
};

#endif
