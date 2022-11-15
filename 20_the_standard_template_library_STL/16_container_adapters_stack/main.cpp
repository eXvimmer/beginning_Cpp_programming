#include <deque>
#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <vector>

template <typename T> void display(std::stack<T> s) {
  // NOTE: s is copied
  std::cout << "[ ";
  while (!s.empty()) {
    std::cout << s.top() << ' ';
    s.pop();
  }
  std::cout << "]\n";
}

// NOTE: we cannot use iterators with stacks

int main() {
  std::stack<int> s; // the default underlying container is a deque
  std::stack<int, std::vector<int>> sv; // change the underlying container
  std::stack<int, std::list<int>> sl;
  std::stack<int, std::deque<int>> sd; // same as default

  for (int i : {1, 2, 3, 4, 5}) {
    s.push(i);
  }
  display(s);

  s.push(1000);
  display(s);

  s.pop();
  s.pop();
  display(s);

  while (!s.empty()) {
    s.pop();
  }
  display(s);

  std::cout << "Size: " << s.size() << '\n';

  s.push(13);
  display(s);

  s.top() = 100;
  display(s);

  return 0;
}
