#include <cstdlib>
#include <iostream>
#include <string>

class Account {
private:
  std::string name;
  double balance;

public:
  // declared inline
  void set_balance(double amount) { balance = amount; }
  double get_balance() { return balance; }

  // will be defined outside the class declaration
  void set_name(std::string n);
  std::string get_name();
  bool deposit(double amount);
  bool withdraw(double amount);
};

void Account::set_name(std::string n) { name = n; }

std::string Account::get_name() { return name; }

bool Account::deposit(double amount) {
  balance += amount;
  return true;
}

bool Account::withdraw(double amount) {
  if (balance - amount >= 0) {
    balance -= amount;
    return true;
  }
  return false;
}

int main() {
  Account mustafa_account;
  mustafa_account.set_name("Mustafa");
  mustafa_account.set_balance(1000.0);

  if (mustafa_account.deposit(2000.0)) {
    std::cout << "Deposit OK" << '\n';
  } else {
    std::cout << "Deposit Not Allowed" << '\n';
  }

  if (mustafa_account.withdraw(500.0)) {
    std::cout << "Withdrawal OK" << '\n';
  } else {
    std::cout << "Not sufficient founds" << '\n';
  }

  if (mustafa_account.withdraw(4000.0)) {
    std::cout << "Withdrawal OK" << '\n';
  } else {
    std::cout << "Not sufficient founds" << '\n';
  }

  return EXIT_SUCCESS;
}
