#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

void changeTheReference(int &rNum);
void changeTheReference(string &rStr);
void changeTheReference(vector<string> &rVec);
void printVector(const vector<string> &rVec);

int main() {
  int num{10}, another_num{20};

  cout << "num before calling changeTheReference: " << num << '\n';

  changeTheReference(num);

  cout << "num after calling changeTheReference: " << num << '\n';

  cout << "another_num before calling changeTheReference: " << another_num
       << '\n';

  changeTheReference(another_num);

  cout << "another_num after calling changeTheReference: " << another_num
       << '\n';

  cout << "\n=======================================================\n";

  string name{"Mustafa"};

  cout << "name before calling changeTheReference: " << name << '\n';

  changeTheReference(name);

  cout << "name after calling changeTheReference: " << name << '\n';

  cout << "=======================================================\n";

  vector<string> foods{"Pizza", "Cheese", "Wine"};

  cout << "foods before calling changeTheReference:\n";
  printVector(foods);

  changeTheReference(foods);

  cout << "foods after calling changeTheReference:\n";
  printVector(foods);

  return 0;
}

void changeTheReference(int &rNum) { rNum = 13; }
void changeTheReference(string &rStr) { rStr = "Changed"; }
void changeTheReference(vector<string> &rVec) { rVec.clear(); }

void printVector(const vector<string> &rVec) {
  if (rVec.size() == 0) {
    cout << "[]\n";
    return;
  }

  for (string s : rVec) {
    cout << s << '\n';
  }
}
