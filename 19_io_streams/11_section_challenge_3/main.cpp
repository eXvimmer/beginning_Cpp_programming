#include <fstream>
#include <iostream>
#include <string>

bool find_substring(const std::string &word_to_find,
                    const std::string &target) {
  auto found = target.find(word_to_find);
  return !(found == std::string::npos);
}

int main() {
  std::ifstream in_file;
  in_file.open("./romeoandjuliet.txt");
  if (!in_file) {
    std::cerr << "failed to open the file" << std::endl;
    return 1;
  }
  std::string target_word, current_word;
  int words_count{0};
  int occurence{0};
  std::cout << "Enter the word that you want to find: ";
  std::cin >> target_word;
  while (in_file >> current_word) {
    ++words_count;
    if (find_substring(target_word, current_word)) {
      ++occurence;
    }
  }
  in_file.close();
  std::cout << "Searched " << words_count << " words\n";
  std::cout << "Found " << occurence << " occurence of the word '"
            << target_word << "'\n";
  return 0;
}
