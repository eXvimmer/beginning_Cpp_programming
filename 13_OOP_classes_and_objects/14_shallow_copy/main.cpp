#include "Shallow.h"
#include <cstdlib>
#include <iostream>

void display_shallow(Shallow s) { std::cout << s.get_data_value() << '\n'; }

int main() {
  Shallow obj1{100};
  display_shallow(obj1);
  // NOTE: obj1 will be copied to display_shallow and display_shallow will call
  // the destructor after finishing with obj1. But there's another obj1 (the one
  // in the parent (this) scope) that still needs the data attribute; So the
  // address of data attribute will be invalidated after display_shallow
  // function.
  Shallow obj2{obj1};      // obj2 also points to the same invalid data
  obj2.set_data_value(13); // change the data attribute of obj1 and obj1 to 13
  return EXIT_SUCCESS;     // ERROR will happen here
}
