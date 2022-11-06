#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_

#include "savings_account.h"
#include <ostream>
#include <string>

class TrustAccount : public SavingsAccount {
public:
  TrustAccount(std::string name = def_name, double balance = def_balance,
               double int_rate = def_int_rate);
  bool deposit(double amount);
  bool withdraw(double amount);
  friend std::ostream &operator<<(std::ostream &os,
                                  const TrustAccount &account);
  friend TrustAccount &operator+=(TrustAccount &account, double amount);
  friend TrustAccount &operator-=(TrustAccount &account, double amount);

protected:
  short withdrawal_count;

private:
  static constexpr double def_balance{0.0};
  static constexpr double def_int_rate{0.0};
  static constexpr const double bonus_amount{50.0};
  static constexpr const double bonus_threshold{5000.0};
  static constexpr const double max_withdrawal_percentage{0.2}; // 20%
  static constexpr const short max_withdrawal_count{3};
  static constexpr const char *def_name{"Unnamed Trust Account"};
};

#endif
