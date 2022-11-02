#include "Mystring.h"
#include <cstdlib>

int main() {
  /* TODO: run this program through debugger. */
  Mystring a{"Hello"};  // overloaded constructor
  a = Mystring{"Hola"}; // overloaded constructor, then move assignment
  a = "Bonjour";        // overloaded constructor, then move assignment

  return EXIT_SUCCESS;
}
