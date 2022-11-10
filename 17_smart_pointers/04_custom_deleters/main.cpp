#include <iostream>
#include <memory>

class Test {
public:
  Test() : data{0} { std::cout << "Test constructor: " << data << "\n"; }
  Test(int data) : data{data} {
    std::cout << "Test constructor: " << data << "\n";
  }
  ~Test() { std::cout << "Test destructor: " << data << "\n"; }
  int get_data() const { return data; }

private:
  int data;
};

void custom_deleter(Test *ptr) {
  std::cout << "Using custom pointer deleter.\n";
  delete ptr;
}

int main() {
  {
    // using a function
    std::shared_ptr<Test> ptr1{new Test(100), custom_deleter};
    // NOTE: you cannot use make_shared or make_unique functions
  }
  std::cout << "=====================================================\n";
  {
    // using a lambda expression
    std::shared_ptr<Test> ptr2(new Test(200), [](Test *ptr) {
      std::cout << "Using custom lambda pointer deleter\n";
      delete ptr;
    });
  }
  return 0;
}
