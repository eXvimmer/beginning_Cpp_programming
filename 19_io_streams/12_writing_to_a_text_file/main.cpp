#include <fstream>
#include <iostream>
#include <string>

int main() {
  // std::ofstream out_file{"./my_file.txt"};
  // std::ofstream out_file{"./my_file.txt", std::ios::out};
  // std::ofstream out_file{"./my_file.txt", std::ios::trunc};
  // std::ofstream out_file{"./my_file.txt", std::ios::app};
  // std::ofstream out_file{"./my_file.txt", std::ios::ate};
  std::ofstream out_file{"./output.txt", std::ios::app};
  if (!out_file) {
    std::cerr << "cannot create the file" << std::endl;
    return 1;
  }
  std::string line{};
  std::cout << "Enter something to write to the text file: ";
  std::getline(std::cin, line);
  out_file << line << std::endl;
  out_file.close(); // NOTE: you sould always close the file
  return 0;
}
