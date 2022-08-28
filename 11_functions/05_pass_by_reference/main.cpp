#include <iostream>
#include <string>
#include <vector>

void changeTheReference(int &rNum);
void changeTheReference(std::string &rStr);
void changeTheReference(std::vector<std::string> &rVec);
void printVector(const std::vector<std::string> &rVec);

int main() {
  int num{10}, another_num{20};

  std::cout << "num before calling changeTheReference: " << num << '\n';

  changeTheReference(num);

  std::cout << "num after calling changeTheReference: " << num << '\n';

  std::cout << "another_num before calling changeTheReference: " << another_num
            << '\n';

  changeTheReference(another_num);

  std::cout << "another_num after calling changeTheReference: " << another_num
            << '\n';

  std::cout << "\n=======================================================\n";

  std::string name{"Mustafa"};

  std::cout << "name before calling changeTheReference: " << name << '\n';

  changeTheReference(name);

  std::cout << "name after calling changeTheReference: " << name << '\n';

  std::cout << "=======================================================\n";

  std::vector<std::string> foods{"Pizza", "Cheese", "Wine"};

  std::cout << "foods before calling changeTheReference:\n";
  printVector(foods);

  changeTheReference(foods);

  std::cout << "foods after calling changeTheReference:\n";
  printVector(foods);

  return 0;
}

void changeTheReference(int &rNum) { rNum = 13; }
void changeTheReference(std::string &rStr) { rStr = "Changed"; }
void changeTheReference(std::vector<std::string> &rVec) { rVec.clear(); }

void printVector(const std::vector<std::string> &rVec) {
  if (rVec.size() == 0) {
    std::cout << "[]\n";
    return;
  }

  for (std::string s : rVec) {
    std::cout << s << '\n';
  }
}
