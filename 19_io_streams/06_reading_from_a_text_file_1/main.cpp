#include <fstream>
#include <iostream>

int main() {
  /* std::ifstream in_file{"test.txt", std::ios::binary | std::ios::in}; */
  std::ifstream in_file;
  in_file.open("./test.txt"); // path is relative to the binary executable
  /* if (!in_file.is_open()) */
  if (!in_file) {
    std::cerr << "cannot open the file" << std::endl;
    /* std::exit(1); */
    return 1;
  }
  /* std::cout << "File is ready\n"; */

  /* std::string word; */
  /* in_file >> word; // reads one string (until it reaches space) to line */
  /* std::cout << word; */

  std::string word;
  int num;
  double total;
  // read one string till white-space
  in_file >> word >> num >> total;
  std::cout << word << '\n';
  std::cout << num << '\n';
  std::cout << total << '\n';

  // make sure to close the file
  in_file.close();

  return 0;
}
