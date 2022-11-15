#include <iostream>
#include <queue>

template <typename T> void display(std::queue<T> q) {
  std::cout << "[ ";
  while (!q.empty()) {
    std::cout << q.front() << ' ';
    q.pop();
  }
  std::cout << "]\n";
}

int main() {
  std::queue<int> q; // the underlying container is a deque
  for (int i : {1, 2, 3, 4, 5}) {
    q.push(i);
  }
  display(q);

  std::cout << "Front: " << q.front() << '\n';
  std::cout << "back: " << q.back() << '\n';

  q.push(100);
  display(q);

  q.pop();
  q.pop();
  display(q);

  while (!q.empty()) {
    q.pop();
  }
  display(q);

  std::cout << "Size: " << q.size() << '\n';

  q.push(10);
  q.push(100);
  q.push(1000);
  display(q);

  std::cout << "Front: " << q.front() << '\n';
  std::cout << "back: " << q.back() << '\n';

  q.front() = 5;
  q.back() = 5000;
  display(q);

  std::cout << "Front: " << q.front() << '\n';
  std::cout << "back: " << q.back() << '\n';

  return 0;
}
