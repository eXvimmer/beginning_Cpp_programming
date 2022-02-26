#include <iomanip>
#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main() {
  int scores[]{1, 2, 3, 4};
  for (int s : scores)
    cout << s << '\n';
  cout << "=================================\n";
  for (auto s : scores)
    cout << s << '\n';
  cout << "=================================\n";

  vector<double> temps{87.9, 77.2, 75.3, 99.2};
  double avg_temp{}, sum_temp{};

  for (double t : temps)
    sum_temp += t;
  if (temps.size() != 0)
    avg_temp = sum_temp / temps.size();

  cout << std::fixed << std::setprecision(1); // NOTE: using io manipulators
  cout << "The average temperature is: " << avg_temp << '\n';
  cout << "=================================\n";

  for (auto v : {1, 2, 3, 4, 5})
    cout << v;
  cout << std::endl;
  cout << "=================================\n";

  /* for (auto c : "This is a test") */
  for (char c : "This is a test") {
    if (c != ' ')
      cout << c;
  }
  cout << std::endl;
  cout << "=================================\n";

  for (auto c : "This is a test")
    cout << (c == ' ' ? '\t' : c);
  cout << std::endl;
  cout << "=================================\n";

  return 0;
}
