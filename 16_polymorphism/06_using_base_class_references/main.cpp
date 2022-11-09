#include <iostream>

class Account {
public:
  virtual ~Account(){};
  virtual void withdraw(double amount) {
    std::cout << "Withdraw $" << amount << " from Account\n";
  }
};

class Trust : public Account {
public:
  virtual ~Trust(){};
  virtual void withdraw(double amount) override {
    std::cout << "Withdraw $" << amount << " from Trust Account\n";
  }
};

class Checking : public Account {
public:
  virtual ~Checking(){};
  virtual void withdraw(double amount) override {
    std::cout << "Withdraw $" << amount << " from Checking Account\n";
  }
};

class Savings : public Account {
public:
  virtual ~Savings(){};
  virtual void withdraw(double amount) override {
    std::cout << "Withdraw $" << amount << " from Savings Account\n";
  }
};

void do_withdraw(Account &account, double amount) { account.withdraw(amount); }

int main() {
  Account a;
  Account &ref{a};
  ref.withdraw(1000); // Account::withdraw

  Trust t;
  Account &ref1{t};
  ref1.withdraw(1000); // Trust::withdraw

  Account a1;
  Savings a2;
  Checking a3;
  Trust a4;

  do_withdraw(a1, 2000); // Account::withdraw
  do_withdraw(a2, 2000); // Savings::withdraw
  do_withdraw(a3, 2000); // Checking::withdraw
  do_withdraw(a4, 2000); // Trust::withdraw

  return 0;
}
