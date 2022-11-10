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

void func(std::shared_ptr<Test> p) {
  std::cout << "Use count: " << p.use_count() << '\n';
}

int main() {
  /*
  std::shared_ptr<int> p1{new int{100}};
  std::cout << "Use count: " << p1.use_count() << '\n'; // 1
  std::shared_ptr<int> p2{p1};
  std::cout << "Use count: " << p1.use_count() << '\n'; // 2

  p1.reset(); // p1 is nulled out; decrements the use_count
  std::cout << "Use count: " << p1.use_count() << '\n'; // 0
  std::cout << "Use count: " << p2.use_count() << '\n'; // 1
  */

  /*
  std::shared_ptr<Test> ptr{std::make_shared<Test>(100)}; // new Test{100}
  func(ptr); // ptr copied to func, 2
  std::cout << "Use count: " << ptr.use_count() << '\n'; // 1

  {
    std::shared_ptr<Test> ptr1{ptr};
    std::cout << "Use count: " << ptr.use_count() << '\n'; // 2
    {
      std::shared_ptr<Test> ptr2{ptr};
      std::cout << "Use count: " << ptr.use_count() << '\n'; // 3
      ptr.reset();
    }
    std::cout << "Use count: " << ptr.use_count() << '\n'; // 0
  }
  std::cout << "Use count: " << ptr.use_count() << '\n'; // 0
  */

  std::shared_ptr<Account> acc1{
      std::make_shared<TrustAccount>("Mustafa", 10'000, 4)};
  std::shared_ptr<Account> acc2{
      std::make_shared<CheckingAccount>("Malena", 5'000)};
  std::shared_ptr<Account> acc3{
      std::make_shared<CheckingAccount>("Maya", 4'000)};

  std::vector<std::shared_ptr<Account>> accounts;
  accounts.push_back(acc1); // copied
  accounts.push_back(acc2);
  accounts.push_back(acc3);

  for (const auto &acc : accounts) {
    std::cout << *acc;
    std::cout << "Use count: " << acc.use_count() << '\n'; // 0
  }

  return 0;
}
