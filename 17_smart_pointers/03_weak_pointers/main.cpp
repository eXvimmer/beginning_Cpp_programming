#include <iostream>
#include <memory>

class B; // forward declaration

class A {
public:
  A() : b_ptr{nullptr} { std::cout << "A constructor\n"; }
  ~A() { std::cout << "A destructor\n"; }
  void set_B(std::shared_ptr<B> &b) { b_ptr = b; }

private:
  std::shared_ptr<B> b_ptr;
};

class B {
public:
  B() : a_ptr{} { std::cout << "B constructor\n"; }
  ~B() { std::cout << "B destructor\n"; }
  void set_A(std::shared_ptr<A> &a) { a_ptr = a; }

private:
  /* std::shared_ptr<A> a_ptr; */
  // NOTE: a circular reference to A, make one of them a weak_ptr or you'll have
  // a memory leak; because use_count will remain 1 and the objects on stack
  // will be destroyed and heap will remain untouched
  std::weak_ptr<A> a_ptr; // now we'll have no memory leak
};

int main() {
  std::shared_ptr<A> a{std::make_shared<A>()};
  std::shared_ptr<B> b{std::make_shared<B>()};
  a->set_B(b);
  b->set_A(a);

  return 0;
}
