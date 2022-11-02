#include "Mystring.h"
#include <cstdlib>

int main() {
  /* TODO: run this program through debugger. */
  Mystring a{"Hello"};
  Mystring b;
  a.display();
  b.display();
  b = a; // b.operator=(a);
  a.display();
  b.display();
  b = "This is a test"; // b.operator=("This is a test");
  b.display();

  return EXIT_SUCCESS;
}
