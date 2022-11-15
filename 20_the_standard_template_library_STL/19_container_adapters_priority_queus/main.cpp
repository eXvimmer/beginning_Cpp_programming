#include <iostream>
#include <queue>
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

template <typename T> void display(std::priority_queue<T> pq) {
  std::cout << "[ ";
  while (!pq.empty()) {
    std::cout << pq.top() << ' ';
    pq.pop();
  }
  std::cout << "]\n";
}

void test1() {
  std::cout << "======================TEST1=======================\n";
  std::priority_queue<int> pq;

  for (int i : {3, 5, 7, 12, 23, 12, 4, 100, 0, 3, 5, 7}) {
    pq.push(i); // ordered pushing
  }
  display(pq);
  std::cout << "Size: " << pq.size() << '\n'; // 12
  std::cout << "Top: " << pq.top() << '\n';   // 100

  pq.pop(); // now 23 is the top
  display(pq);
}

void test2() {
  std::cout << "======================TEST2=======================\n";
  std::priority_queue<Person> pq;
  pq.push(Person{"Mustafa", 30});
  pq.push(Person{"Malena", 26});
  pq.push(Person{"Emily", 24});
  pq.push(Person{"Sadie", 22});
  pq.push(Person{"Sydney", 24});
  pq.push(Person{"Margot", 32});
  // NOTE: ordered by age; we can change the implementation of operator< to
  // compare names.

  display(pq);
}

int main() {
  test1();
  test2();

  return 0;
}
