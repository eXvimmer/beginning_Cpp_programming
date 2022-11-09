class MyFinalClass final {};

/* class D : public MyFinalClass {}; // ERROR */

class A {
public:
  virtual void do_something();
};

class B {
public:
  virtual void do_something() final;
};

class C : public B {
public:
  /* virtual void do_something() final; // ERROR */
};

int main() { return 0; }
