#include "account_util.h"
#include "checking_account.h"
#include "iostream"
#include "trust_account.h"

void display(const std::vector<Account *> &accounts) {
  for (const auto a : accounts) {
    std::cout << *a;
  }
}

void deposit(std::vector<Account *> &accounts, double amount) {
  for (auto a : accounts) {
    if (a->deposit(amount)) {
      std::cout << "Deposited " << amount << " to " << *a;
    } else {
      std::cout << "Failed deposit of " << amount << " to " << *a;
    }
  }
}

void withdraw(std::vector<Account *> &accounts, double amount) {
  for (auto a : accounts) {
    if (a->withdraw(amount)) {
      std::cout << "Withdrew " << amount << " from " << *a;
    } else {
      std::cout << "Failed withdrawal of " << amount << " from " << *a;
    }
  }
}
