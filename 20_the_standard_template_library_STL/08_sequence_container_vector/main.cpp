#include <algorithm>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>

class Person {
public:
  Person() = default;
  Person(std::string name, int age) : name{name}, age{age} {}
  ~Person() = default;
  // NOTE: when you use STL containers and algorithms, always overload < & ==
  // operators
  bool operator<(const Person &obj) { return this->age < obj.age; }
  bool operator==(const Person &obj) {
    return this->age == obj.age && this->name == obj.name;
  }

private:
  std::string name;
  int age;
  friend std::ostream &operator<<(std::ostream &os, const Person &p);
};

std::ostream &operator<<(std::ostream &os, const Person &p) {
  os << p.name << ":" << p.age;
  return os;
}

template <typename T> void display(const std::vector<T> &vec) {
  std::cout << "[ ";
  for (const auto &elem : vec) {
    std::cout << elem << ' ';
  }
  std::cout << "]\n";
}

void display2(const std::vector<int> &vec) {
  std::cout << "[ ";
  std::for_each(vec.begin(), vec.end(), [](int x) { std::cout << x << ' '; });
  std::cout << "]\n";
}

void test1() {
  std::cout << "======================TEST1=======================\n";
  std::vector<int> vec{1, 2, 3, 4, 5};
  display(vec);
  vec = {2, 4, 5, 6};
  display(vec);

  std::vector<int> vec2(10, 100); // ten 100s
  display(vec2);
}

void test2() {
  std::cout << "======================TEST2=======================\n";
  std::vector<int> vec{1, 2, 3, 4, 5};
  display(vec);
  std::cout << "vec size: " << vec.size() << '\n';
  std::cout << "vec max_size: " << vec.max_size() << '\n';
  std::cout << "vec capacity: " << vec.capacity() << '\n';
  vec.push_back(6);
  display(vec);
  std::cout << "vec size: " << vec.size() << '\n';
  std::cout << "vec max_size: " << vec.max_size() << '\n';
  std::cout << "vec capacity: " << vec.capacity() << '\n';

  vec.shrink_to_fit(); // C++11, very cool
  display(vec);
  std::cout << "vec size: " << vec.size() << '\n';
  std::cout << "vec max_size: " << vec.max_size() << '\n';
  std::cout << "vec capacity: " << vec.capacity() << '\n';

  vec.reserve(100);
  display(vec);
  std::cout << "vec size: " << vec.size() << '\n';
  std::cout << "vec max_size: " << vec.max_size() << '\n';
  std::cout << "vec capacity: " << vec.capacity() << '\n';
}

void test3() {
  std::cout << "======================TEST3=======================\n";
  std::vector<int> vec{1, 2, 3, 4, 5};
  display(vec);
  vec[0] = 100;
  vec.at(1) = 200;
  display(vec);
}

void test4() {
  std::cout << "======================TEST4=======================\n";
  std::vector<Person> people;
  Person p1{"Mustafa", 30};
  display(people);
  people.push_back(p1);
  display(people);
  people.push_back(Person{"Margot", 32});
  display(people);
  people.push_back({"Malena", 26});
  display(people);
  // NOTE: use emplace_back, it's awesome
  people.emplace_back("Emily", 24); // sends arguments to the constructor
  display(people);
}

void test5() {
  std::cout << "======================TEST5=======================\n";
  std::vector<Person> people{{"Mustafa", 30}, {"Malena", 26}, {"Emily", 24}};
  display(people);
  std::cout << "Front: " << people.front() << std::endl;
  std::cout << "Back: " << people.back() << '\n';
  people.pop_back();
  display(people);
}

void test6() {
  std::cout << "======================TEST6=======================\n";
  std::vector<int> vec{1, 2, 3, 4, 5};
  display(vec);
  vec.clear();
  display(vec);
  vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  display(vec);
  vec.erase(vec.begin(), vec.begin() + 2);
  display(vec);
  vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  display(vec);
  auto it = vec.begin();
  while (it != vec.end()) {
    if (*it % 2 == 0) {
      vec.erase(it);
    } else {
      it++;
    }
  }
  display(vec);
}

void test7() {
  std::cout << "======================TEST7=======================\n";
  std::vector<int> vec{1, 2, 3, 4, 5};
  std::vector<int> vec2{10, 20, 30, 40, 50};
  display(vec);
  display(vec2);
  std::cout << std::endl;
  vec2.swap(vec);
  display(vec);
  display(vec2);
}

void test8() {
  std::cout << "======================TEST8=======================\n";
  std::vector<int> vec{1, 21, 3, 40, 12};
  display(vec);
  std::sort(vec.begin(), vec.end());
  display(vec);
}

void test9() {
  std::cout << "======================TEST9=======================\n";
  std::vector<int> vec1{1, 2, 3, 4, 5};
  std::vector<int> vec2{10, 20};
  display(vec1);
  display(vec2);
  std::cout << std::endl;

  std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec2));
  display(vec1);
  display(vec2);
  std::cout << std::endl;

  vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vec2 = {10, 20};
  display(vec1);
  display(vec2);
  std::cout << std::endl;

  // copy_if the element is even
  std::copy_if(vec1.begin(), vec1.end(), std::back_inserter(vec2),
               [](int x) { return x % 2 == 0; });
  display(vec1);
  display(vec2);
  std::cout << std::endl;
}

void test10() {
  std::cout << "======================TEST10=======================\n";
  std::vector<int> vec1{1, 2, 3, 4, 5};
  std::vector<int> vec2{10, 20, 30, 40, 50};
  std::vector<int> vec3;

  std::transform(vec1.begin(), vec1.end(), vec2.begin(),
                 std::back_inserter(vec3), [](int x, int y) { return x * y; });
  display(vec1);
  display(vec2);
  display(vec3);
}

void test11() {
  std::cout << "======================TEST10=======================\n";
  std::vector<int> vec1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> vec2{100, 200, 300, 400};
  display(vec1);
  display(vec2);
  std::cout << std::endl;

  auto it = std::find(vec1.begin(), vec1.end(), 5);
  if (it != vec1.end()) {
    std::cout << "inserting...\n";
    vec1.insert(it, vec2.begin(), vec2.end());
  } else {
    std::cout << "Sorry, 5 not found.\n";
  }
  display(vec1);
  display(vec2);
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
  test11();

  return 0;
}
