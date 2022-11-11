#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_

#include "account.h"
#include <ostream>
#include <string>

class SavingsAccount : public Account {
public:
  SavingsAccount(std::string name = def_name, double balance = def_balance,
                 double int_rate = def_int_rate);
  virtual ~SavingsAccount() = default;
  virtual void print(std::ostream &os) const override;
  virtual bool deposit(double amount) override;
  virtual bool withdraw(double amount) override;
  friend SavingsAccount &operator+=(SavingsAccount &account, double amount);
  friend SavingsAccount &operator-=(SavingsAccount &account, double amount);

protected:
  double int_rate;

private:
  static constexpr const char *def_name{"Unnamed Savings Account"};
  static constexpr double def_balance{0.0};
  static constexpr double def_int_rate{0.0};
};

#endif // _SAVINGS_ACCOUNT_H_
