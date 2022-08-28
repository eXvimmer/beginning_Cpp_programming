#include <iomanip>
#include <iostream>
#include <vector>

int main() {
  int scores[]{1, 2, 3, 4};
  for (int s : scores)
    std::cout << s << '\n';
  std::cout << "=================================\n";
  for (auto s : scores)
    std::cout << s << '\n';
  std::cout << "=================================\n";

  std::vector<double> temps{87.9, 77.2, 75.3, 99.2};
  double avg_temp{}, sum_temp{};

  for (double t : temps)
    sum_temp += t;
  if (temps.size() != 0)
    avg_temp = sum_temp / temps.size();

  std::cout << std::fixed
            << std::setprecision(1); // NOTE: using io manipulators
  std::cout << "The average temperature is: " << avg_temp << '\n';
  std::cout << "=================================\n";

  for (auto v : {1, 2, 3, 4, 5})
    std::cout << v;
  std::cout << std::endl;
  std::cout << "=================================\n";

  /* for (auto c : "This is a test") */
  for (char c : "This is a test") {
    if (c != ' ')
      std::cout << c;
  }
  std::cout << std::endl;
  std::cout << "=================================\n";

  for (auto c : "This is a test")
    std::cout << (c == ' ' ? '\t' : c);
  std::cout << std::endl;
  std::cout << "=================================\n";

  return 0;
}
