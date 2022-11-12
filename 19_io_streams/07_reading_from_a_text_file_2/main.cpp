#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

int main() {
  /* std::ifstream in_file{"test.txt", std::ios::binary}; */
  std::ifstream in_file;
  in_file.open("./test.txt"); // path is relative to the binary executable
  if (!in_file) {
    std::cerr << "cannot open the file" << std::endl;
    return 1;
  }

  std::string line;
  int num;
  double total;

  /* while (!in_file.eof()) { */
  /*   in_file >> line >> num >> total; */

  /*   std::cout << std::setw(10) << std::left << line << std::setw(10) << num
   */
  /*             << std::setw(10) << total << std::endl; */
  /* } */

  while (in_file >> line >> num >> total) {
    std::cout << std::setw(10) << std::left << line << std::setw(10) << num
              << std::setw(10) << total << std::endl;
  }

  // make sure to close the file
  in_file.close();

  return 0;
}
