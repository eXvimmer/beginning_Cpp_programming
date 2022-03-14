#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

int main() {
  int num{100};
  int &r_num{num};

  cout << num << '\n';
  cout << r_num << '\n';

  cout << "==================================\n";
  num = 200;
  cout << num << '\n';
  cout << r_num << '\n';

  cout << "==================================\n";
  num = 300;
  cout << num << '\n';
  cout << r_num << '\n';

  cout << "==================================\n";
  vector<string> names{"Mustafa", "Malena", "Maya"};

  for (auto s : names) { // s is a copy
    s = "Someone";
  }

  for (auto s : names) { // no changes
    cout << s << ' ';
  }
  cout << '\n';

  cout << "==================================\n";
  for (auto &r_name : names) {
    r_name = "M...A";
  }

  for (auto const &name : names) {
    cout << name << ' ';
  }
  cout << '\n';

  return 0;
}
