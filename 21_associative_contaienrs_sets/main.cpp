#include <ios>
#include <iostream>
#include <ostream>
#include <set>
#include <string>

class Person {
public:
  Person() : name{"Unknown"}, age{0} {}
  Person(std::string name, int age) : name{name}, age{age} {}
  ~Person() = default;
  bool operator<(const Person &p) const { return this->age < p.age; }
  bool operator==(const Person &p) const {
    return this->age == p.age && this->name == p.name;
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

template <typename T> void display(const std::set<T> &s) {
  std::cout << "[ ";
  for (const auto &el : s) {
    std::cout << el << ' ';
  }
  std::cout << "]\n";
}

void test1() {
  std::cout << "======================TEST1=======================\n";
  std::set<int> s{1, 4, 3, 5, 2};
  // NOTE: set is ordered with no duplicates by default , if you want unordered
  // sets or duplicates, use multiset, unordered_set or unordered_multiset.
  display(s);

  s = {1, 2, 3, 4, 1, 2, 1, 1, 3, 3, 4, 5, 1, 2, 3, 4};
  display(s);

  s.insert(0);
  s.insert(10);
  display(s);

  if (s.count(10)) {
    std::cout << "10 is in the set.\n";
  } else {
    std::cout << "10 is not in the set.\n";
  }

  // NOTE: use set.find method instead of std::find, this one is more efficient.
  auto it = s.find(5);
  if (it != s.end()) {
    std::cout << "Found: " << *it << std::endl;
  }

  s.clear();
  display(s);
}

void test2() {
  std::cout << "======================TEST2=======================\n";
  std::set<Person> people{{"Mustafa", 30}, {"Malena", 26}, {"Emily", 24}};
  // NOTE: will be ordered by age
  display(people);

  people.emplace("Sadie", 22); // build and insert a Person to the set.
  display(people);
  people.emplace("Maya", 24); // NOTE: won't insert, because 24 already exits
  display(people);

  auto it = people.find(Person{"Malena", 26});
  if (it != people.end()) {
    people.erase(it);
  }
  display(people);

  it = people.find({"XXXXX", 22}); // finds Sadie, set uses < to compares values
  if (it != people.end()) {
    people.erase(it);
  }
  display(people);
}

void test3() {
  std::cout << "======================TEST3=======================\n";
  std::set<std::string> s{"A", "B", "C"};
  display(s);

  auto result = s.insert("D");
  display(s);
  std::cout << std::boolalpha;
  std::cout << "First: " << *(result.first) << '\n';
  std::cout << "second (inserted?): " << result.second << '\n';

  result = s.insert("A");
  display(s);
  std::cout << "First: " << *(result.first) << '\n';
  std::cout << "second (inserted?): " << result.second << '\n';
  std::cout << std::noboolalpha;
}

int main() {
  test1();
  test2();
  test3();

  return 0;
}
