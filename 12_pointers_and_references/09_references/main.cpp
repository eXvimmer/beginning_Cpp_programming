#include <iostream>
#include <string>
#include <vector>

int main() {
  int num{100};
  int &r_num{num};

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

  for (auto s : names) { // s is a copy
    s = "Someone";
  }

  for (auto s : names) { // no changes
    std::cout << s << ' ';
  }
  std::cout << '\n';

  std::cout << "==================================\n";
  for (auto &r_name : names) {
    r_name = "M...A";
  }

  for (auto const &name : names) {
    std::cout << name << ' ';
  }
  std::cout << '\n';

  return 0;
}
