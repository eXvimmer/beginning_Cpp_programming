#include <cstdlib>
#include <iostream>

// NOTE: for dynamic polymorphism we must have:
// * inheritance
// * base class pointer or base class reference
// * virtual functions

// NOTE: virtual functions
// * Redefined functions are bound statically.
// * Overridden functions are bound dynamically.
// * Virtual functions are overridden.
// * Allow us to treat all objects generally as objects of the base class.

// NOTE: whenever you have a virtual function you should have a virtual
// destructor.

class Account {
public:
  virtual void withdraw(double amount) {
    std::cout << "In Account::withdraw: " << amount << std::endl;
  }
  // TODO: add a virtual destructor. (see the note above)
};

class SavingsAccount : public Account {
public:
  virtual void withdraw(double amount) {
    std::cout << "In SavingsAccount::withdraw: " << amount << std::endl;
  }
};

class CheckingAccount : public Account {
public:
  virtual void withdraw(double amount) {
    std::cout << "In CheckingAccount::withdraw: " << amount << std::endl;
  }
};

class TrustAccount : public Account {
public:
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
