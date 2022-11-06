#include <cstdlib>
#include <iostream>

class Base {
public:
  void say_hello() const { std::cout << "Hello, I'm the Base class.\n"; }
};

class Derived : public Base {
public:
  void say_hello() const { std::cout << "Hello, I'm the Derived class.\n"; }
};

void greetings(const Base &obj) {
  std::cout << "Greetings: ";
  obj.say_hello(); // statically bound to Base
}

int main() {
  Base b;
  b.say_hello();

  Derived d;
  d.say_hello();

  greetings(b);
  greetings(d); // the problem, obj is statically bound to Base class.

  Base *p{new Derived()}; // a pointer to Base, so p is statically bound to Base
  p->say_hello();
  delete p;

  return EXIT_SUCCESS;
}
