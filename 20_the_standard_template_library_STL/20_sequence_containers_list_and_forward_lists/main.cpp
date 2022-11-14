#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <string>

class Person {
public:
  Person() : name{"Unknown"}, age{0} {}
  Person(std::string name, int age) : name{name}, age{age} {}
  ~Person() = default;
  bool operator==(const Person &p) const {
    return this->name == p.name && this->age == p.age;
  }
  bool operator<(const Person &p) const { return this->age < p.age; }

private:
  std::string name;
  int age;
  friend std::ostream &operator<<(std::ostream &os, const Person &p);
};

std::ostream &operator<<(std::ostream &os, const Person &p) {
  os << p.name << ":" << p.age;
  return os;
}

template <typename T> void display(const std::list<T> &t) {
  std::cout << "[ ";
  for (const auto &el : t) {
    std::cout << el << ' ';
  }
  std::cout << "]\n";
}

void test1() {
  std::cout << "======================TEST1=======================\n";
  std::list<int> l1{1, 2, 3, 4, 5};
  display(l1);

  std::list<std::string> l2;
  l2.push_back("Mustafa");
  l2.push_back("Emily");
  l2.push_back("Malena");
  display(l2);

  std::list<int> l3;
  l3 = {1, 2, 3, 4, 5, 6};
  display(l3);

  std::list<int> l4(10, 100); // ten 100s
  display(l4);
}

void test2() {
  std::cout << "======================TEST2=======================\n";
  std::list<int> l1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  display(l1);
  std::cout << "Size: " << l1.size() << '\n';
  std::cout << "Front: " << l1.front() << '\n';
  std::cout << "Back: " << l1.back() << '\n';
  l1.clear();
  display(l1);
  std::cout << "Size: " << l1.size() << '\n';
}

void test3() {
  std::cout << "======================TEST3=======================\n";
  std::list<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  display(l);
  l.resize(5);
  display(l);
  l.resize(10);
  display(l);

  std::list<Person> people;
  people.resize(5); // use the Person default constructor
  display(people);
}

void test4() {
  std::cout << "======================TEST4=======================\n";
  std::list<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  display(l);
  auto it = std::find(l.begin(), l.end(), 5);
  if (it != l.end()) {
    l.insert(it, 888);
  }
  display(l);

  std::list<int> l2{1'000, 2'000, 3'000};
  l.insert(it, l2.begin(), l2.end());
  display(l);

  std::advance(it, -4); // cannot it -= 4
  std::cout << *it << std::endl;

  l.erase(it); // removes the 888 - iterator becomes invalid
  display(l);
}

void test5() {
  std::cout << "======================TEST5=======================\n";
  std::list<Person> people{{"Mustafa", 30}, {"Malena", 26}, {"Emily", 24}};
  display(people);
  std::string name;
  int age;
  std::cout << "Please enter the name of the next person: ";
  std::getline(std::cin, name);
  std::cout << "Please enter their age: ";
  std::cin >> age;
  people.emplace_back(name, age);
  display(people);

  // insert Sadie before Malena
  auto it = std::find(people.begin(), people.end(), Person{"Malena", 26});
  if (it != people.end()) {
    people.emplace(it, "Sadie", 22);
  }
  display(people);
}

void test6() {
  std::cout << "======================TEST6=======================\n";
  std::list<Person> people{{"Mustafa", 30}, {"Malena", 26}, {"Emily", 24}};
  display(people);
  people.sort(); // in this case, it sorts from younger to older Person
  display(people);
}

int main() {
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();

  return 0;
}
