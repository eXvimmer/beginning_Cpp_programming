#include "account.h"
#include "checking_account.h"
#include "illegal_balance_exception.h"
#include <iostream>
#include <memory>

int main() {
  try {
    std::unique_ptr<Account> my_account{
        std::make_unique<CheckingAccount>("Mustafa", -10.0)};
    std::cout << *my_account << std::endl;
  } catch (const IllegalBalanceException &ex) {
    std::cerr << "couldn't create account; negative balance." << std::endl;
  }
  std::cout << "Program completed successfully.\n";
  return 0;
}
