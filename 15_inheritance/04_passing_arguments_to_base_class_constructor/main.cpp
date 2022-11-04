#include <cstdlib>
#include <iostream>
class Base {
public:
  Base() : value{0} { std::cout << "Base no-args constructor\n"; }
  Base(int x) : value{x} { std::cout << "Base overloaded constructor\n"; }
  ~Base() { std::cout << "Base destructor\n"; }

private:
  int value;
};

class Derived : public Base {
  using Base::Base;

public:
  // having explicit control over how constructors are called
  Derived() : Base{}, doubled_value{0} {
    std::cout << "Derived no-args constructor\n";
  }
  Derived(int x) : Base{x}, doubled_value{x * 2} {
    std::cout << "Derived overloaded constructor\n";
  }
  ~Derived() { std::cout << "Derived destructor\n"; }

private:
  int doubled_value;
};

int main() {
  /* Derived d; */
  Derived d{1000};
  return EXIT_SUCCESS;
}
