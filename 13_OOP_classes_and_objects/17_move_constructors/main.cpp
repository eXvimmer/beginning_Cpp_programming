#include "Move.h"
#include <cstdlib>
#include <vector>

int main() {
  std::vector<Move> vec;
  vec.push_back(Move{1});
  // NOTE: Move{1} is a r-value; if there's a move constructor it'll use that,
  // otherwise it'll use the copy constructor.
  vec.push_back(Move{2});
  vec.push_back(Move{3});
  vec.push_back(Move{4});
  vec.push_back(Move{5});
  vec.push_back(Move{6});
  vec.push_back(Move{7});
  vec.push_back(Move{8});
  return EXIT_SUCCESS;
}
