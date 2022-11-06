#include "account.h"
#include "account_util.h"
#include "savings_account.h"
#include <cstdlib>
#include <iostream>
#include <vector>

int main() {
  std::cout.precision(2);
  std::cout << std::fixed;

  std::vector<Account> accounts;
  accounts.push_back(Account());
  accounts.push_back(Account{"Mustafa", 2000.0});
  accounts.push_back(Account{"Malena", 5000.0});
  display(accounts);
  deposit(accounts, 1000);
  withdraw(accounts, 5000);

  std::vector<SavingsAccount> savings_accounts;
  savings_accounts.push_back(SavingsAccount{});
  savings_accounts.push_back(SavingsAccount("Maya"));
  savings_accounts.push_back(SavingsAccount{"Barbara", 2000});
  savings_accounts.push_back(SavingsAccount{"Sydney", 5000, 5.0});
  display(savings_accounts);
  deposit(savings_accounts, 1000);
  withdraw(savings_accounts, 2000);

  return EXIT_SUCCESS;
}
