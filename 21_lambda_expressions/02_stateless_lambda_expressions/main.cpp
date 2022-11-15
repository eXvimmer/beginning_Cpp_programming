#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

/* void filter_vector(const std::vector<int> &vec, auto predicate); // C++20 */
void filter_vector(const std::vector<int> &vec,
                   std::function<bool(int)> predicate) { // C++14
  std::cout << "[ ";
  for (int i : vec) {
    if (predicate(i)) {
      std::cout << i << ' ';
    }
  }
  std::cout << "]\n";
}

auto make_lambda() {
  return
      []() { std::cout << "This lambda was made by make_lambda function\n"; };
}

class Person {
public:
  Person(std::string name, int age) : name{name}, age{age} {}
  Person(const Person &p) : name{p.name}, age{p.age} {}
  ~Person() = default;
  std::string get_name() const { return name; };
  void set_name(std::string name) { this->name = name; }
  int get_age() const { return age; };
  void set_age(int age) { this->age = age; }

private:
  std::string name;
  int age;
  friend std::ostream &operator<<(std::ostream &os, const Person &p);
};

std::ostream &operator<<(std::ostream &os, const Person &p) {
  os << "[Person: " << p.name << ":" << p.age << "]";
  return os;
}

void test1() {
  std::cout << "======================TEST1=======================\n";
  // NOTE: these lambda expressions are stateless, because [] is empty
  []() { std::cout << "hi\n"; }();
  [](int x) { std::cout << x << '\n'; }(100);
  [](int x, int y) { std::cout << x + y << '\n'; }(100, 200);
}

void test2() {
  std::cout << "======================TEST2=======================\n";

  /* std::function<void()> l1 = []() {...}; */
  auto l1 = []() { std::cout << "hi\n"; };
  l1();

  int num1{100}, num2{100};
  /* std::function<void(int, int)> l2 = [](int x, int y) {...}; */
  auto l2 = [](int x, int y) { std::cout << x + y << '\n'; };
  l2(10, 20);
  l2(num1, num2);

  /* std::function<void(int &, int)> l3 = [](int &x, int y) {...}; */
  auto l3 = [](int &x, int y) {
    std::cout << "x: " << x << ", y: " << y << '\n';
    x = 1000; // will change the value of x
    y = 2000;
  };
  l3(num1, num2);
  std::cout << "num1: " << num1 << ", num2: " << num2 << '\n';
}

void test3() {
  std::cout << "======================TEST3=======================\n";
  Person me{"Mustafa", 30};
  std::cout << me << '\n';

  // NOTE: you need copy constructor for l1
  auto l1 = [](Person p) { std::cout << p << std::endl; };
  l1(me);

  auto l2 = [](const Person &p) { std::cout << p << std::endl; };
  l2(me);

  auto l3 = [](Person &p) {
    p.set_name("Malena");
    p.set_age(26);
    std::cout << p << std::endl;
  };
  l3(me); // not me anymore

  std::cout << me << std::endl;
}

void test4() {
  std::cout << "======================TEST4=======================\n";
  std::vector<int> nums{10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

  filter_vector(nums, [](int x) { return x > 50; });
  filter_vector(nums, [](int x) { return x <= 30; });
  filter_vector(nums, [](int x) { return x >= 30 && x <= 60; });
}

void test5() {
  std::cout << "======================TEST5=======================\n";
  auto l = make_lambda();
  l();
}

void test6() {
  std::cout << "======================TEST6=======================\n";
  // generic lambda expression
  auto l = [](auto x, auto y) {
    std::cout << "x: " << x << ", y: " << y << std::endl;
  };
  l(10, 20);
  l("Mustafa", "Malena");
  l(Person{"Emily", 24}, Person{"Sadie", 22});
}

void test7() {
  std::cout << "======================TEST7=======================\n";
  std::vector<Person> people{{"Mustafa", 30}, {"Sadie", 22}, {"Emily", 24}};
  std::sort(people.begin(), people.end(),
            [](const Person &p1, const Person &p2) {
              return p1.get_name() < p2.get_name();
            });
  std::for_each(people.begin(), people.end(),
                [](const Person &p) { std::cout << p << '\n'; });
  std::cout << std::endl;
  std::sort(people.begin(), people.end(),
            [](const Person &p1, const Person &p2) {
              return p1.get_age() < p2.get_age();
            });
  std::for_each(std::begin(people), std::end(people),
                [](const Person &p) { std::cout << p << '\n'; });
  std::cout << std::endl;
}

int main() {
  /*
   * lambda expression structor
   * [capture list] - (parameters) -> returnType specifiers {body}
   * [] () -> returnType specifiers {}
   * [] (int x) {std::cout << x << '\n';}(100) // immediately invoked
   *
   * function object using STL functional header
   * std::function<void(int)>
   * this means a function that returns void and take an int as parameter
   *
   * function pointer
   * void (*predicate) (int)
   * this means a pointer to a function named predicate that takes an int and
   * returns void
   */

  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();

  return 0;
}
