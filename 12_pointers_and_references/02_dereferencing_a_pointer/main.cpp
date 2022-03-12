#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

int main() {
  int score{100};
  int *pScore{&score};

  cout << *pScore << '\n'; // dereference pScore, the value of score, 100

  *pScore = 200; // dereference the pointer and change the value of score to 200

  cout << *pScore << '\n';
  cout << score << '\n';

  cout << "=================================\n";
  double high_temp{40.7}, low_temp{7.9};
  double *pTemp{&high_temp};

  cout << *pTemp << '\n';
  pTemp = &low_temp;
  cout << *pTemp << '\n';

  cout << "=================================\n";
  string name{"Mustafa"};
  string *pStr{&name};

  cout << *pStr << '\n';
  name = "Malena";
  cout << *pStr << '\n';

  cout << "=================================\n";
  vector<string> skills{"programming", "hacking", "procrastinating"};
  vector<string> *pVec{nullptr};

  pVec = &skills;

  cout << "My first skill is " << (*pVec).at(0) << '\n';
  cout << "My second skill is " << pVec->at(1) << '\n';

  cout << "My skills are:\n";
  for (string s : *pVec) {
    cout << s << ' ';
  }
  cout << std::endl;

  return 0;
}
