#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <ostream>
#include <string>

class Account {
public:
  Account(std::string name = def_name, double balance = def_balance);
  bool deposit(double amount);
  bool withdraw(double amount);
  double get_balance() const;
  friend std::ostream &operator<<(std::ostream &os, const Account &account);
  friend Account &operator+=(Account &account, double amount);
  friend Account &operator-=(Account &account, double amount);

protected:
  std::string name;
  double balance;

private:
  static constexpr const char *def_name{"Unnamed Account"};
  static constexpr double def_balance{0.0};
};

#endif
