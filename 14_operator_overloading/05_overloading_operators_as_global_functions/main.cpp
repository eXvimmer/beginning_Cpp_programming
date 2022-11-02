#include "Mystring.h"
#include <cstdlib>
#include <ios>
#include <iostream>

int main() {
  /* TODO: run this program through debugger. */
  Mystring mustafa{"Mustafa"};
  mustafa.display();
  mustafa = -mustafa; // make it lowercase
  mustafa.display();
  std::cout << std::boolalpha;
  Mystring malena{"Malena"};
  Mystring maya{mustafa}; // does {} calls the copy assignment like = does?
  std::cout << (mustafa == malena) << std::endl;
  std::cout << (mustafa == maya) << std::endl;
  Mystring team{mustafa + malena};
  team.display();
  Mystring others{maya + " " + "Maya"};
  others.display();
  Mystring another{"Mustafa " + malena + " Maya"};
  another.display();

  return EXIT_SUCCESS;
}
