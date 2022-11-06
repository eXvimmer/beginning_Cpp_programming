#include "account_util.h"
#include "iostream"

void display(const std::vector<Account> &accounts) {
  std::cout << "====================Accounts====================\n";
  for (const auto &a : accounts) {
    std::cout << a;
  }
}

void display(const std::vector<SavingsAccount> &accounts) {
  std::cout << "=================Savings Accounts=================\n";
  for (const auto &a : accounts) {
    std::cout << a;
  }
}

void deposit(std::vector<Account> &accounts, double amount) {
  std::cout << "==============Depositing to Accounts==============\n";
  for (auto &a : accounts) {
    if (a.deposit(amount)) {
      std::cout << "Deposited " << amount << " to " << a;
    } else {
      std::cout << "Failed deposit of " << amount << " to " << a;
    }
  }
}

void deposit(std::vector<SavingsAccount> &accounts, double amount) {
  std::cout << "==========Depositing to Savings Accounts==========\n";
  for (auto &a : accounts) {
    if (a.deposit(amount)) {
      std::cout << "Deposited " << amount << " to " << a;
    } else {
      std::cout << "Failed deposit of " << amount << " to " << a;
    }
  }
}

void withdraw(std::vector<Account> &accounts, double amount) {
  std::cout << "============Withdrawing from Accounts============\n";
  for (auto &a : accounts) {
    if (a.withdraw(amount)) {
      std::cout << "Withdrew " << amount << " from " << a;
    } else {
      std::cout << "Failed withdrawal of " << amount << " from " << a;
    }
  }
}

void withdraw(std::vector<SavingsAccount> &accounts, double amount) {
  std::cout << "========Withdrawing from Savings Accounts========\n";
  for (auto &a : accounts) {
    if (a.withdraw(amount)) {
      std::cout << "Withdrew " << amount << " from " << a;
    } else {
      std::cout << "Failed withdrawal of " << amount << " from " << a;
    }
  }
}
