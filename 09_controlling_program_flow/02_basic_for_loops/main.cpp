#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main() {
  for (int i = 0, j = 5; i < 5; ++i, ++j)
    cout << i << " + " << j << " = " << i + j << "\n";

  for (int i = 1; i <= 100; ++i)
    cout << i << ((i % 10 == 0) ? "\n" : " ");

  vector<int> nums{1, 2, 3, 4, 5};
  for (unsigned i = 0; i < nums.size(); ++i) {
    cout << nums.at(i);
  }
  cout << std::endl;

  // NOTE: endless loop
  /* for (;;) */
  /*   cout << "hi"; */

  return 0;
}
