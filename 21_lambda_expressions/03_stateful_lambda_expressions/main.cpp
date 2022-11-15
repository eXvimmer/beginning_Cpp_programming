#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int global_x{1000};

class Lambda {
public:
  Lambda(int y) : y{y} {}
  ~Lambda() = default;
  void operator()(int x) const { std::cout << x + y << std::endl; }

private:
  int y;
};

class Person {
public:
  Person() = default;
  Person(std::string name, int age) : name{name}, age{age} {}
  Person(const Person &p) = default;
  ~Person() = default;
  std::string get_name() const { return name; }
  void set_name(std::string name) { this->name = name; }
  int get_age() const { return age; }
  void set_age(int age) { this->age = age; }
  auto change_person1() {
    // NOTE: always use [this] version
    return [this](std::string new_name, int new_age) {
      name = new_name;
      age = new_age;
    };
  }
  auto change_person2() {
    // WARN: deprecated in C++20, you'll probably get a warning
    return [=](std::string new_name, int new_age) {
      name = new_name;
      age = new_age;
    };
  }
  auto change_person3() {
    // NOTE: use [this] version
    return [&](std::string new_name, int new_age) {
      name = new_name;
      age = new_age;
    };
  }

private:
  std::string name;
  int age;
  friend std::ostream &operator<<(std::ostream &os, const Person &p);
};

std::ostream &operator<<(std::ostream &os, const Person &p) {
  os << "[Person: " << p.name << ':' << p.age << ']';
  return os;
}

class People {
public:
  People(int max = 10) : max_people{max} {}
  People(const People &p) = default;
  ~People() = default;
  void add(std::string name, int age) { people.emplace_back(name, age); }
  void set_max_people(int max) { max_people = max; }
  int get_max_people() const { return max_people; }
  std::vector<Person> get_people(int max_age) const {
    std::vector<Person> result;
    int count{0};
    std::copy_if(people.begin(), people.end(), std::back_inserter(result),
                 [this, &count, max_age](const Person &p) {
                   return p.get_age() > max_age && ++count <= max_people;
                 });
    return result;
  }

private:
  std::vector<Person> people;
  int max_people;
};

void test1() {
  std::cout << "======================TEST1=======================\n";
  int local_x{100};
  auto l = [local_x]() {
    /* local_x += 100; // ERROR: non-mutable */
    std::cout << local_x << '\n';
    std::cout << global_x << '\n'; // using normal name lookup rules
  };
  l();
}

void test2() {
  std::cout << "======================TEST2=======================\n";
  int x{100};

  // NOTE: the captured value, x, can only be modified within the lambda, by
  // using the mutable keyword.
  auto l = [x]() mutable {
    x += 100; // changees only within the lambda, like a static variable
    std::cout << x << std::endl;
  };

  l();
  std::cout << x << std::endl; // 100

  l();
  std::cout << x << std::endl; // 100
}

void test3() {
  std::cout << "======================TEST3=======================\n";
  int x{100};

  auto l = [&x]() mutable {
    x += 100;
    std::cout << x << std::endl;
  };

  l();
  std::cout << x << std::endl;
}

void test4() {
  std::cout << "======================TEST4=======================\n";
  // NOTE: z is not captured
  int x{100}, y{200}, z{300};

  // Default capture by value - mutable, only variables used used within lambda
  // body are captured by value.
  auto l = [=]() mutable {
    // NOTE: [=] means capture everything by value
    x += 100;
    y += 100;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
  };

  l();

  std::cout << x << std::endl;
  std::cout << y << std::endl;
  std::cout << z << std::endl; // NOTE: to not get unused variable warning
}

void test5() {
  std::cout << "======================TEST5=======================\n";
  int x{100}, y{200}, z{300};

  auto l = [&]() {
    // NOTE: [&] means capture all by reference
    x += 100;
    y += 100;
    z += 100;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
  };

  l();
  std::cout << x << std::endl;
  std::cout << y << std::endl;
  std::cout << z << std::endl;
}

void test6() {
  std::cout << "======================TEST6=======================\n";
  int x{100}, y{200}, z{300};

  auto l = [=, &y]() mutable {
    // NOTE: [=, &y] means copy everything and get a reference of y
    x += 100;
    y += 100;
    z += 100;

    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
  };

  l();
  std::cout << x << std::endl;
  std::cout << y << std::endl;
  std::cout << z << std::endl;
}

void test7() {
  std::cout << "======================TEST7=======================\n";
  int x{100}, y{200}, z{300};

  // capture everything by reference except x and y
  auto l = [&, x, y]() mutable {
    x += 100;
    y += 100;
    z += 100;
    std::cout << x << '\n';
    std::cout << y << '\n';
    std::cout << z << '\n';
  };

  l();
  std::cout << x << '\n';
  std::cout << y << '\n';
  std::cout << z << '\n';
}

void test8() {
  std::cout << "======================TEST8=======================\n";
  Person person{"Mustafa", 18};
  std::cout << person << std::endl;

  auto change_person1 = person.change_person1();
  change_person1("Malena", 26);
  std::cout << person << std::endl;

  // WARNING: deprecated
  auto change_person2 = person.change_person2();
  change_person2("Margot", 32);
  std::cout << person << std::endl;

  auto change_person3 = person.change_person3();
  change_person3("Emily", 22);
  std::cout << person << std::endl;
}

void test9() {
  std::cout << "======================TEST9=======================\n";
  int y{100};
  Lambda l1(y);
  auto l2 = [y](int x) { std::cout << x + y << std::endl; };

  l1(200);
  l2(200);
}

void test10() {
  std::cout << "======================TEST10=======================\n";
  People friends;
  friends.add("Mustafa", 30);
  friends.add("Malena", 26);
  friends.add("Emily", 24);
  friends.add("Sadie", 22);
  friends.add("Sydney", 25);
  friends.add("Margot", 32);
  friends.add("Brad", 47);

  auto result = friends.get_people(17);
  std::cout << std::endl;
  for (const auto &p : result) {
    std::cout << p << std::endl;
  }

  friends.set_max_people(3);

  result = friends.get_people(17);
  std::cout << std::endl;

  for (const auto &p : result) {
    std::cout << p << std::endl;
  }
  std::cout << std::endl;

  result = friends.get_people(46);
  for (const auto &p : result) {
    std::cout << p << std::endl;
  }
}

int main() {
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
  test8();
  test9();
  test10();

  return 0;
}
