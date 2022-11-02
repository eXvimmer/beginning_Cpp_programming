#include "Mystring.h"
#include <cstdlib>
#include <ios>
#include <iostream>

int main() {
  /* TODO: run this program through debugger. */
  std::cout << std::boolalpha << std::endl;
  Mystring mustafa{"Mustafa"};
  Mystring malena{"Malena"};
  Mystring maya{malena};
  mustafa.display();
  malena.display();
  std::cout << (mustafa == malena) << std::endl;
  std::cout << (malena == maya) << std::endl;
  maya.display();
  Mystring melina = -mustafa; // this operator is ambiguous
  melina.display();
  Mystring team{mustafa + "Miranda"};
  team.display();
  /* Mystring stooges {  "Larry" + malena }; // NOT OK, Error */
  Mystring others{maya + " " + "Maya"};
  others.display();

  return EXIT_SUCCESS;
}
