#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <ostream>

class Account {
public:
  friend std::ostream &operator<<(std::ostream &os, const Account &account);
  Account();
  Account(double amount);
  void deposit(double amount);
  void withdraw(double amount);

protected:
  double balance;
};

#endif
