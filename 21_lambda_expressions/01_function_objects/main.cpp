#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct SquareFunctor {
  void operator()(int x) { std::cout << x * x << '\n'; }
};

template <typename T> struct Displayer {
  void operator()(const T &data) { std::cout << data << ' '; }
};

class Multiplier {
public:
  Multiplier() : num{0} {}
  Multiplier(int num) : num{num} {}
  ~Multiplier() = default;
  int operator()(int x) const { return x * num; }

private:
  int num;
};

void test1() {
  std::cout << "======================TEST1=======================\n";
  SquareFunctor square;
  square(4); // calls square.operator(4)

  Displayer<int> di;
  Displayer<std::string> ds;
  di(100); // calls di.operator(100);
  ds("Thieves");
  std::cout << std::endl;
}

void test2() {
  std::cout << "======================TEST2=======================\n";
  SquareFunctor square;
  Displayer<int> di;
  Displayer<std::string> ds;
  std::vector<int> vi{1, 2, 3, 4, 5};
  std::vector<std::string> vs{"Mustafa", "Malena", "Emily"};
  std::for_each(vi.begin(), vi.end(), square);
  std::cout << std::endl;
  std::for_each(vi.begin(), vi.end(), Displayer<int>());
  std::cout << std::endl;
  std::for_each(vi.begin(), vi.end(), di);
  std::cout << std::endl;
  std::for_each(vs.begin(), vs.end(), Displayer<std::string>());
  std::cout << std::endl;
  std::for_each(vs.begin(), vs.end(), ds);
  std::cout << std::endl;
}

void test3() {
  std::cout << "======================TEST3=======================\n";
  std::vector<int> vi{1, 2, 3, 4, 5};
  std::vector<std::string> vs{"Mustafa", "Malena", "Emily"};
  std::for_each(vi.begin(), vi.end(), [](int x) { std::cout << x * x << ' '; });
  std::cout << std::endl;
  std::for_each(vi.begin(), vi.end(),
                [](int x) { std::cout << x * 10 << ' '; });
  std::cout << std::endl;
  std::for_each(vi.begin(), vi.end(), [](int x) { std::cout << x << ' '; });
  std::cout << std::endl;
  std::for_each(vs.begin(), vs.end(),
                [](std::string s) { std::cout << s << ' '; });
  std::cout << std::endl;
}

void test4() {
  std::cout << "======================TEST4=======================\n";
  Multiplier mult(100);
  std::vector<int> vi{1, 2, 3, 4, 5};
  std::transform(vi.begin(), vi.end(), vi.begin(), mult);
  std::for_each(vi.begin(), vi.end(), [](int i) { std::cout << i << ' '; });
  std::cout << std::endl;

  vi = {1, 2, 3, 4, 5};
  std::transform(vi.begin(), vi.end(), vi.begin(),
                 [](int i) { return i * 100; });
  std::cout << std::endl;
  std::for_each(vi.begin(), vi.end(), [](int i) { std::cout << i << ' '; });
  std::cout << std::endl;
}

int main() {
  test1();
  test2();
  test3();
  test4();

  return 0;
}
