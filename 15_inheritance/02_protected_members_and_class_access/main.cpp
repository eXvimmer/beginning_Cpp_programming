#include <cstdlib>
#include <iostream>
class Base {
public:
  int a{0};
  void display() { std::cout << a << ", " << b << ", " << c << std::endl; }

protected:
  int b{0};

private:
  int c{0};
};

class Derived : public Base {
  // NOTE: because access modifier for inheritance is public, then a is public,
  // b is protected and c is not accessible (nothing changes). But if it was
  // protected, then a and b would be protected, and c is still not accessible.
  // In the case of private access modifier a and b would b private and c not
  // accessible.
public:
  void access_base_member() {
    a = 100; // OK
    b = 200; // OK
    /* c = 100; // Error */
    std::cout << a << ", " << b << std::endl;
  }
};

int main() {
  std::cout << "=========Base member access from base object========="
            << std::endl;
  Base base;
  base.a = 100; // OK, public
  /* base.b = 100; // Error, protected */
  /* base.c = 100; // Error, private */

  std::cout << "=========Base member access from derived object========="
            << std::endl;
  Derived derived;
  derived.a = 1000; // OK, public
  /* derived.b = 2000; // Error, protected */
  /* derived.c = 3000; // Error, private */

  return EXIT_SUCCESS;
}
