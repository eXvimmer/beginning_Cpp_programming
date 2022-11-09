#include <iostream>

// an abstract class as interface
class IPrintable {
  friend std::ostream &operator<<(std::ostream &os, const IPrintable &obj);

public:                                           // must be public
  virtual void print(std::ostream &os) const = 0; // pure virtual function.
  virtual ~IPrintable() {}
};

std::ostream &operator<<(std::ostream &os, const IPrintable &obj) {
  obj.print(os);
  return os;
}

class Account : public IPrintable {

public:
  virtual void print(std::ostream &os) const override {
    os << "Account display\n";
  }
  virtual void withdraw(double amount) {
    std::cout << "In Account::withdraw: $" << amount << '\n';
  }
  virtual ~Account() {}
};

class Checking : public Account {
public:
  virtual void print(std::ostream &os) const override {
    os << "Checking display\n";
  }
  virtual void withdraw(double amount) override {
    std::cout << "In Checking::withdraw: $" << amount << '\n';
  }
  virtual ~Checking() {}
};

class Savings : public Account {
public:
  virtual void print(std::ostream &os) const override {
    os << "Savings display\n";
  }
  virtual void withdraw(double amount) override {
    std::cout << "In Savings::withdraw: $" << amount << '\n';
  }
  virtual ~Savings() {}
};

class Trust : public Account {
public:
  virtual void print(std::ostream &os) const override {
    os << "Trust display\n";
  }
  virtual void withdraw(double amount) override {
    std::cout << "In Trust::withdraw: $" << amount << '\n';
  }
  virtual ~Trust() {}
};

class Dog : public IPrintable {
public:
  virtual void print(std::ostream &os) const override { os << "Woof woof\n"; }
  virtual ~Dog() {}
};

void print(const IPrintable &obj) { std::cout << obj << std::endl; }

int main() {
  Account *p1{new Account()};
  print(*p1);

  Account *p2{new Checking()};
  print(*p2);

  Dog *dog{new Dog()};
  print(*dog);

  delete p1;
  delete p2;
  delete dog;

  return 0;
}
