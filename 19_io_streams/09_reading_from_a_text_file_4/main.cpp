#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

int main() {
  std::ifstream in_file;
  in_file.open("./poem.txt");
  if (!in_file) {
    std::cerr << "cannot open the file" << std::endl;
    return 1;
  }

  char c;
  while (in_file.get(c)) {
    std::cout << c;
  }

  // make sure to close the file
  in_file.close();

  return 0;
}
