#include <iostream>
#include <ostream>

class Account {
  // NOTE: friend functions are not inheritable
  friend std::ostream &operator<<(std::ostream &os, const Account &account);

public:
  virtual void withdraw(double amount) {
    std::cout << "In Account::withdraw: $" << amount << '\n';
  }
  virtual ~Account() {}
};

std::ostream &operator<<(std::ostream &os, const Account &account) {
  os << "Account display";
  return os;
}

class Checking : public Account {
  friend std::ostream &operator<<(std::ostream &os, const Checking &account);

public:
  virtual void withdraw(double amount) override {
    std::cout << "In Checking::withdraw: $" << amount << '\n';
  }
  virtual ~Checking() {}
};

std::ostream &operator<<(std::ostream &os, const Checking &account) {
  os << "Checking display";
  return os;
}

class Savings : public Account {
  friend std::ostream &operator<<(std::ostream &os, const Savings &account);

public:
  virtual void withdraw(double amount) override {
    std::cout << "In Savings::withdraw: $" << amount << '\n';
  }
  virtual ~Savings() {}
};

std::ostream &operator<<(std::ostream &os, const Savings &account) {
  os << "Savings display";
  return os;
}

class Trust : public Account {
  friend std::ostream &operator<<(std::ostream &os, const Trust &account);

public:
  virtual void withdraw(double amount) override {
    std::cout << "In Trust::withdraw: $" << amount << '\n';
  }
  virtual ~Trust() {}
};

std::ostream &operator<<(std::ostream &os, const Trust &account) {
  os << "Trust display";
  return os;
}

int main() {
  /* Account a; */
  /* std::cout << a << std::endl; */

  /* Checking c; */
  /* std::cout << c << std::endl; */

  /* Savings s; */
  /* std::cout << s << std::endl; */

  /* Trust t; */
  /* std::cout << t << std::endl; */

  Account *p1{new Account()};
  std::cout << *p1 << std::endl;

  Account *p2{new Checking()};
  // The problem: because we cannot inherit friend functions
  std::cout << *p2 << std::endl; // this will use the operator<< of Account

  delete p1;
  delete p2;

  return 0;
}
