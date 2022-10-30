#include <iostream>
#include <string>
#include <vector>

int main() {
  int num{100};
  int &r_num{num};
  // NOTE: References can't be null. So if you have a null value, use a pointer.

  std::cout << num << '\n';
  std::cout << r_num << '\n';

  std::cout << "==================================\n";
  num = 200;
  std::cout << num << '\n';
  std::cout << r_num << '\n';

  std::cout << "==================================\n";
  num = 300;
  std::cout << num << '\n';
  std::cout << r_num << '\n';

  std::cout << "==================================\n";
  std::vector<std::string> names{"Mustafa", "Malena", "Maya"};

  for (auto s : names) { // NOTE: s is a copy
    s = "Someone";
  }

  for (auto s : names) { // no changes
    std::cout << s << ' ';
  }
  std::cout << '\n';
  // NOTE: it's better to use [constant] references with these kinds of loops to
  // avoid having unnecessary copies.

  std::cout << "==================================\n";
  for (std::string &name : names) {
    name = "M...A";
  }

  for (auto const &name : names) {
    std::cout << name << ' ';
  }
  std::cout << '\n';

  return 0;
}
