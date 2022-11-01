#include "Deep.h"
#include <cstdlib>
#include <iostream>

void display_deep(Deep d) { std::cout << d.get_data_value() << '\n'; }

int main() {
  Deep obj1{100};
  display_deep(obj1); // Deep copy, so this is safe
  Deep obj2{obj1};    // Deep copy
  // NOTE: this is safe, because obj1 and obj2 will have distince data
  // attributes
  obj2.set_data_value(13);

  return EXIT_SUCCESS;
}
