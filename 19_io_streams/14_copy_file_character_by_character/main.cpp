#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::ifstream in_file;
  in_file.open("./poem.txt");
  if (!in_file) {
    std::cerr << "failed to open the input file" << std::endl;
    return 1;
  }

  std::ofstream out_file;
  out_file.open("./poem_out.txt");
  if (!out_file) {
    std::cerr << "failed to open the output file" << std::endl;
    return 1;
  }

  char c;
  while (in_file.get(c)) {
    out_file.put(c);
  }
  std::cout << "File copied.\n";

  in_file.close();
  out_file.close();
  return 0;
}
