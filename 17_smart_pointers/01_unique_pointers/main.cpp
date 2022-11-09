#include "account.h"
#include "checking_account.h"
#include "savings_account.h"
#include "trust_account.h"
#include <iostream>
#include <memory>
#include <vector>

class Test {
public:
  Test() : data{0} { std::cout << "Test constructor (" << data << ")\n"; }
  Test(int data) : data{data} {
    std::cout << "Test constructor (" << data << ")\n";
  }
  ~Test() { std::cout << "Test destructor (" << data << ")\n"; }
  int get_data() const { return data; }

private:
  int data;
};

int main() {
  // NOTE: unique_ptr<T>
  // * points to an object of type T on the heap
  // * it's unique - there can only be one unique_ptr<T> pointing to the object
  // on the heap
  // * owns what it points to
  // * cannot be assigned or copied
  // * can be moved
  // * when the pointer is destroyed, what it points to is automatically
  // destroyed

  /* Test t1{1000}; */

  /* Test *t2{new Test(2000)}; // raw pointer */
  /* delete t2; */

  // using a unique_ptr
  std::unique_ptr<Test> t3{new Test{3000}};
  // NOTE: no need to delete manually

  std::unique_ptr<Test> t4{std::make_unique<Test>(4000)};

  auto t5 = std::make_unique<Test>(5000);

  std::unique_ptr<Test> t6;
  // unique pointers cannot be assigned or copied
  /* t6 = t5; // ERROR */

  t6 = std::move(t5); // unique_ptr can be moved, now ownership belongs to t6
  // NOTE: now t6 owns Test(5000) and t5 will be a nullptr

  // NOTE: smart pointers can be easily checked with if statements
  if (!t5) {
    std::cout << "t5 is nullptr\n";
  }

  /* std::unique_ptr<Account> a1{ */
  /*     std::make_unique<CheckingAccount>("Mustafa", 5000)}; */
  // NOTE: using auto with make_unique is better, I think
  auto a1 = std::make_unique<CheckingAccount>("Mustafa", 5000);
  std::cout << *a1;
  a1->deposit(5000);
  std::cout << *a1;

  std::vector<std::unique_ptr<Account>> accounts;
  /* accounts.push_back(a1); // ERROR cannot copy or assign */
  accounts.push_back(std::make_unique<CheckingAccount>("Malena", 10'000));
  accounts.push_back(std::move(a1)); // OK, we can move ownership
  accounts.push_back(std::make_unique<SavingsAccount>("Maya", 4'500));
  accounts.push_back(std::make_unique<TrustAccount>("Emily", 80'000));

  // ERROR because we're copying unique_ptrs
  /* for (auto acc : accounts) { */
  /*   std::cout << *acc << std::endl; */
  /* } */

  // OK we can reference them
  for (const auto &acc : accounts) {
    std::cout << *acc;
  }
  return 0;
}
