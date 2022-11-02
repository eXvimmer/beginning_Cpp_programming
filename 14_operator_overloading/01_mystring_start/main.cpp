#include "Mystring.h"
#include <cstdlib>

int main() {
  Mystring empty;              // no-args constructor
  Mystring mustafa{"Mustafa"}; // overloaded constructor
  Mystring malena{mustafa};    // copy constructor

  empty.display();
  mustafa.display();
  malena.display();

  return EXIT_SUCCESS;
}
