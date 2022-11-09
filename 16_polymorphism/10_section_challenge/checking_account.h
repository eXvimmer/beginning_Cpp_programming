#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_

#include "account.h"
#include <ostream>
#include <string>

class CheckingAccount : public Account {
public:
  CheckingAccount(std::string name = def_name, double balance = def_balance);
  virtual ~CheckingAccount() = default;
  virtual void print(std::ostream &os) const override;
  virtual bool deposit(double amount) override;
  virtual bool withdraw(double amount) override;
  friend CheckingAccount &operator+=(CheckingAccount &account, double amount);
  friend CheckingAccount &operator-=(CheckingAccount &account, double amount);

private:
  static constexpr const double def_balance{0.0};
  static constexpr const char *def_name{"Unnamed Checking Account"};
  static constexpr const double withdrawal_fee{1.50};
};

#endif
