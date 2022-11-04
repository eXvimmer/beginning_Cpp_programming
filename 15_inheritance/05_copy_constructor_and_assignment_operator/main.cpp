#include <cstdlib>
#include <iostream>

class Base {
public:
  Base() : value{0} { std::cout << "Base no-args constructor.\n"; }

  Base(int x) : value{x} { std::cout << "Base overloaded constructor.\n"; }

  Base(const Base &other) : value{other.value} {
    std::cout << "Base copy constructor.\n";
  }

  Base &operator=(const Base &other) {
    std::cout << "Base copy assignment.\n";
    if (this != &other) {
      value = other.value;
    }
    return *this;
  }

  ~Base() { std::cout << "Base destructor.\n"; }

private:
  int value;
};

class Derived : public Base {
public:
  Derived() : Base(), doubled_value(0) {
    std::cout << "Derived no-args constructor.\n";
  }

  Derived(int x) : Base{x}, doubled_value(x * 2) {
    std::cout << "Derived overloaded constructor.\n";
  }

  Derived(const Derived &other)
      : Base{other}, doubled_value{other.doubled_value} {
    std::cout << "Derived copy constructor.\n";
  }

  Derived &operator=(const Derived &rhs) {
    std::cout << "Derived copy assignment.\n";
    if (this == &rhs) {
      return *this;
    }
    Base::operator=(rhs); // NOTE: this is very important
    this->doubled_value = rhs.doubled_value;
    return *this;
  }

  ~Derived() { std::cout << "Derived destructor.\n"; }

private:
  int doubled_value;
};

int main() {
  /* Base b{100}; // overloaded constructor */
  /* Base b1{b};  // copy constructor */
  /* b = b1;      // copy assignment */

  Derived d{1000}; // overloaded constructor
  Derived d1{d};   // copy constructor;
  d = d1;          // copy assignment

  return EXIT_SUCCESS;
}
