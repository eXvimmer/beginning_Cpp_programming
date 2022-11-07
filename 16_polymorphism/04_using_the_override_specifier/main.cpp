
#include <cstdlib>
#include <iostream>

// NOTE: We cab override base class virtual functions. The function signature
// and the return type must be exactly the same. If they are different, we have
// redefinition not overriding. Redefinition is statically bound. Overriding is
// dynamically bound. C++11 provides an override specifier to have the compiler
// ensure overriding.

class Base {
public:
  virtual ~Base(){};
  virtual void say_hello() const {
    std::cout << "Hello, I'm a Base class object.\n";
  }
};

class Derived : public Base {
public:
  virtual ~Derived(){};
  /* virtual void say_hello() { */
  /*   std::cout << "Hello, I'm a Derived class object.\n"; */
  /* } */
  // NOTE: We forgot const, so this will be redefined (statically bind). To fix
  // this, put the override keyword after any method that you want to override.
  // This way, if you have a mistake, it will give an error.
  virtual void say_hello() const override {
    std::cout << "Hello, I'm a Derived class object.\n";
  }
};

int main() {
  Base *p1{new Base()};
  p1->say_hello();

  Derived *p2{new Derived()};
  p2->say_hello();

  Base *p3{new Derived()};
  p3->say_hello();

  delete p1;
  delete p2;
  delete p3;
  return EXIT_SUCCESS;
}
