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
  using Base::Base; // inheriting the Base constructor

public:
  // NOTE: constructors and destructors, overloaded assignment operators and
  // friend functions are not inherited
  Derived() : doubled_value{0} { std::cout << "Derived no-args constructor\n"; }
  // NOTE: you can comment out this ⬇ overloaded constructor and use "using
  // Base::Base" at the top of the class to use the parent constructor.
  Derived(int x) : doubled_value{x * 2} {
    std::cout << "Derived overloaded constructor\n";
  }
  ~Derived() { std::cout << "Derived destructor\n"; }

private:
  int doubled_value;
};

int main() {
  /* Base b; */
  /* Base B{100}; */
  /* Derived d; */
  Derived d{1000};
  return EXIT_SUCCESS;
}
