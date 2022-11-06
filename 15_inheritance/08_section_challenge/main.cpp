#include "account.h"
#include "account_util.h"
#include "checking_account.h"
#include "savings_account.h"
#include "trust_account.h"
#include <cstdlib>
#include <iostream>

int main() {
  std::cout.precision(2);
  std::cout << std::fixed;

  // Accounts
  std::vector<Account> accounts;
  accounts.push_back(Account{});
  accounts.push_back(Account{"Larry"});
  accounts.push_back(Account{"Moe", 2000});
  accounts.push_back(Account{"Curly", 5000});

  display(accounts);
  deposit(accounts, 1000);
  withdraw(accounts, 2000);

  // Savings
  std::vector<SavingsAccount> sav_accounts;
  sav_accounts.push_back(SavingsAccount{});
  sav_accounts.push_back(SavingsAccount{"Superman"});
  sav_accounts.push_back(SavingsAccount{"Batman", 2000});
  sav_accounts.push_back(SavingsAccount{"Wonderwoman", 5000, 5.0});

  display(sav_accounts);
  deposit(sav_accounts, 1000);
  withdraw(sav_accounts, 2000);

  // Checking
  std::vector<CheckingAccount> check_accounts;
  check_accounts.push_back(CheckingAccount{});
  check_accounts.push_back(CheckingAccount{"Kirk"});
  check_accounts.push_back(CheckingAccount{"Spock", 2000});
  check_accounts.push_back(CheckingAccount{"Bones", 5000});

  display(check_accounts);
  deposit(check_accounts, 1000);
  withdraw(check_accounts, 2000);

  // Trust
  std::vector<TrustAccount> trust_accounts;
  trust_accounts.push_back(TrustAccount{});
  trust_accounts.push_back(TrustAccount{"Athos", 10000, 5.0});
  trust_accounts.push_back(TrustAccount{"Porthos", 20000, 4.0});
  trust_accounts.push_back(TrustAccount{"Aramis", 30000});

  display(trust_accounts);
  deposit(trust_accounts, 1000);
  withdraw(trust_accounts, 3000);

  // Withdraw 5 times from each trust account
  // All withdrawals should fail if there are too many withdrawals or if the
  // withdrawl is > 20% of the balance
  for (int i{1}; i <= 5; i++) {
    withdraw(trust_accounts, 1000);
  }

  return EXIT_SUCCESS;
}
