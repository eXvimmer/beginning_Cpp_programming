#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <vector>

template <typename T> void display(const std::deque<T> &d) {
  std::cout << "[ ";
  for (const auto &elem : d) {
    std::cout << elem << ' ';
  }
  std::cout << "]\n";
}

void test1() {
  std::cout << "======================TEST1=======================\n";
  std::deque<int> d{1, 2, 3, 4, 5};
  display(d);

  d = {2, 4, 5, 6};
  display(d);

  std::deque<int> d1(10, 100); // ten 100s
  display(d1);

  // WARN: deque are like doubled ended queues; you just want to work with front
  // and back, don't insert in the middle ;)
  d1[1] = 200;
  d1.at(2) = 300;
  display(d1);
}

void test2() {
  std::cout << "======================TEST2=======================\n";
  std::deque<int> d{0, 0, 0};
  display(d);
  d.push_back(10);
  d.push_back(20);
  display(d);

  d.push_front(100);
  d.push_front(200);
  display(d);

  std::cout << "Front: " << d.front() << '\n';
  std::cout << "Back: " << d.back() << '\n';
  std::cout << "Size: " << d.size() << '\n';

  d.pop_back();
  d.pop_front();
  display(d);
}

void test3() {
  std::cout << "======================TEST3=======================\n";
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::deque<int> d;

  for (const auto &elem : vec) {
    if (elem % 2 == 0) {
      d.push_back(elem);
    } else {
      d.push_front(elem);
    }
  }
  display(d);
}

void test4() {
  std::cout << "======================TEST4=======================\n";
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::deque<int> d;

  for (const auto &elem : vec) {
    d.push_front(elem);
  }
  display(d);

  d.clear();

  for (const auto &elem : vec) {
    d.push_back(elem);
  }
  display(d);
}

void test5() {
  std::cout << "======================TEST5=======================\n";
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::deque<int> d;
  display(d);

  std::copy(vec.begin(), vec.end(), std::front_inserter(d));
  display(d);

  d.clear();

  std::copy(vec.begin(), vec.end(), std::back_inserter(d));
  display(d);
}

int main() {
  test1();
  test2();
  test3();
  test4();
  test5();

  return 0;
}
