#include <iostream>
#include <string>
#include <vector>

int main() {
  int score{100};
  int *pScore{&score};

  std::cout << *pScore << '\n'; // dereference pScore, the value of score, 100

  *pScore = 200; // dereference the pointer and change the value of score to 200

  std::cout << *pScore << '\n';
  std::cout << score << '\n';

  std::cout << "=================================\n";
  double high_temp{40.7}, low_temp{7.9};
  double *pTemp{&high_temp};

  std::cout << *pTemp << '\n';
  pTemp = &low_temp;
  std::cout << *pTemp << '\n';

  std::cout << "=================================\n";
  std::string name{"Mustafa"};
  std::string *pStr{&name};

  std::cout << *pStr << '\n';
  name = "Malena";
  std::cout << *pStr << '\n';

  std::cout << "=================================\n";
  std::vector<std::string> skills{"programming", "hacking", "procrastinating"};
  std::vector<std::string> *pVec{nullptr};

  pVec = &skills;

  std::cout << "My first skill is " << (*pVec).at(0) << '\n';
  std::cout << "My second skill is " << pVec->at(1) << '\n';

  std::cout << "My skills are:\n";
  for (std::string s : *pVec) {
    std::cout << s << ' ';
  }
  std::cout << std::endl;

  return 0;
}
