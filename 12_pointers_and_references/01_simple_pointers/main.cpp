#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

int main() {
  int num{13};

  cout << "Value of num is " << num << '\n';
  cout << "Size of num is " << sizeof num << '\n';
  cout << "Address of num is " << &num;

  cout << "\n===========================================================\n";
  int *pNum; // NOTE: pNum is uninitialized

  cout << "Value of pNum is " << pNum << '\n';       // garbage
  cout << "Size of pNum is " << sizeof pNum << '\n'; // on my system: 8 bytes
  cout << "Address of pNum is " << &pNum;            // address of the pointer

  cout << "\n===========================================================\n";
  pNum = nullptr; // address of 0, pointer points nowhere, best practice
  cout << "Value of pNum is " << pNum;

  cout << "\n===========================================================\n";
  int *pInt{nullptr};
  double *pDouble{nullptr};
  unsigned long long *pUll{nullptr};
  vector<string> *pVec{nullptr};
  string *pStr{nullptr};

  cout << "Size of pInt is " << sizeof pInt << '\n';
  cout << "Size of pDouble is " << sizeof pDouble << '\n';
  cout << "Size of pUll is " << sizeof pUll << '\n';
  /* cout << "Size of pVec is " << sizeof pVec << '\n'; */
  /* cout << "Size of pStr is " << sizeof pStr << '\n'; */

  cout << "\n===========================================================\n";
  int score{2022};
  double high_temp{57.8};

  int *pScore{nullptr};

  pScore = &score;

  cout << "Value of scores is " << score << '\n';
  cout << "Address of score is " << &score << '\n';
  cout << "Value of pScore is " << pScore << '\n';

  // pScore = &pDouble; // ERROR: different types

  return 0;
}
