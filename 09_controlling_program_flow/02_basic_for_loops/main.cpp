#include <iostream>
#include <vector>

int main() {
  for (int i = 0, j = 5; i < 5; ++i, ++j)
    std::cout << i << " + " << j << " = " << i + j << "\n";

  for (int i = 1; i <= 100; ++i)
    std::cout << i << ((i % 10 == 0) ? "\n" : " ");

  std::vector<int> nums{1, 2, 3, 4, 5};
  for (unsigned i = 0; i < nums.size(); ++i) {
    std::cout << nums.at(i);
  }
  std::cout << std::endl;

  // NOTE: endless loop
  /* for (;;) */
  /*   std::cout << "hi"; */

  return 0;
}
