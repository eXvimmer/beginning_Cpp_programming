#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include "iprintable.h"
#include <ostream>
#include <string>

class Account : public IPrintable {
public:
  Account(std::string name = def_name, double balance = def_balance);
  virtual ~Account() = default;
  virtual void print(std::ostream &os) const override;
  virtual bool deposit(double amount) = 0;
  virtual bool withdraw(double amount) = 0;
  friend Account &operator+=(Account &account, double amount);
  friend Account &operator-=(Account &account, double amount);

  // NOTE: if you define a method in an abstract class, you have to define it in
  // other derived classes as well. For example if we declare get_balance in
  // accoutn and not define it in derived classes, then those classes will be
  // abstract classes as well.
  /* virtual double get_balance() const = 0; */

protected:
  std::string name;
  double balance;

private:
  static constexpr const char *def_name{"Unnamed Account"};
  static constexpr double def_balance{0.0};
};

#endif
