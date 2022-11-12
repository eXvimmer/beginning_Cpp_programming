#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

int main() {
  std::ifstream in_file{"./romeoandjuliet.txt"};
  if (!in_file) {
    std::cerr << "failed to open the input file" << std::endl;
    return 1;
  }

  std::ofstream out_file{"output.txt"};
  if (!out_file) {
    std::cerr << "failed to open the output file";
    return 1;
  }

  std::string line;
  unsigned int line_number{1};
  while (std::getline(in_file, line)) {
    out_file << std::setw(7) << std::left << line_number++ << " " << line
             << std::endl;
  }

  std::cout << "File copied\n";
  in_file.close();
  out_file.close();

  return 0;
}
