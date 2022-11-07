#include <cstdlib>
#include <iostream>

class Account {
public:
  virtual ~Account() { std::cout << "Account destructor" << std::endl; };
  virtual void withdraw(double amount) {
    std::cout << "In Account::withdraw: " << amount << std::endl;
  }
};

class SavingsAccount : public Account {
public:
  virtual ~SavingsAccount() {
    std::cout << "SavingsAccount destructor" << std::endl;
  };
  virtual void withdraw(double amount) {
    std::cout << "In SavingsAccount::withdraw: " << amount << std::endl;
  }
};

class CheckingAccount : public Account {
public:
  virtual ~CheckingAccount() {
    std::cout << "CheckingAccount destructor" << std::endl;
  };
  virtual void withdraw(double amount) {
    std::cout << "In CheckingAccount::withdraw: " << amount << std::endl;
  }
};

class TrustAccount : public Account {
public:
  virtual ~TrustAccount() {
    std::cout << "TrurstAccount destructor" << std::endl;
  };
  virtual void withdraw(double amount) {
    std::cout << "In TrustAccount::withdraw: " << amount << std::endl;
  }
};

int main() {
  std::cout << "====================Pointers====================\n";
  Account *p1{new Account()};
  Account *p2{new SavingsAccount()};
  Account *p3{new CheckingAccount()};
  Account *p4{new TrustAccount()};

  p1->withdraw(1000);
  p2->withdraw(1000);
  p3->withdraw(1000);
  p4->withdraw(1000);

  std::cout << "================Clean Up Pointers================\n";
  delete p1;
  delete p2;
  delete p3;
  delete p4;

  return EXIT_SUCCESS;
}
