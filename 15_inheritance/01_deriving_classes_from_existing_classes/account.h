#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <string>

class Account {
public:
  Account();
  ~Account();
  void deposit(double amount);
  void withdraw(double amount);
  double balance;
  std::string name;
};

#endif // _ACCOUNT_H_
