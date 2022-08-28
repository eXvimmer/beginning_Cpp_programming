#include <iostream>
#include <string>
#include <vector>

int main() {
  int num{13};

  std::cout << "Value of num is " << num << '\n';
  std::cout << "Size of num is " << sizeof num << '\n';
  std::cout << "Address of num is " << &num;

  std::cout
      << "\n===========================================================\n";
  int *pNum; // NOTE: pNum is uninitialized

  std::cout << "Value of pNum is " << pNum << '\n'; // garbage
  std::cout << "Size of pNum is " << sizeof pNum
            << '\n';                           // on my system: 8 bytes
  std::cout << "Address of pNum is " << &pNum; // address of the pointer

  std::cout
      << "\n===========================================================\n";
  pNum = nullptr; // address of 0, pointer points nowhere, best practice
  std::cout << "Value of pNum is " << pNum;

  std::cout
      << "\n===========================================================\n";
  int *pInt{nullptr};
  double *pDouble{nullptr};
  unsigned long long *pUll{nullptr};
  std::vector<std::string> *pVec{nullptr};
  std::string *pStr{nullptr};

  std::cout << "Size of pInt is " << sizeof pInt << '\n';
  std::cout << "Size of pDouble is " << sizeof pDouble << '\n';
  std::cout << "Size of pUll is " << sizeof pUll << '\n';
  /* std::cout << "Size of pVec is " << sizeof pVec << '\n'; */
  /* std::cout << "Size of pStr is " << sizeof pStr << '\n'; */

  std::cout
      << "\n===========================================================\n";
  int score{2022};
  double high_temp{57.8};

  int *pScore{nullptr};

  pScore = &score;

  std::cout << "Value of scores is " << score << '\n';
  std::cout << "Address of score is " << &score << '\n';
  std::cout << "Value of pScore is " << pScore << '\n';

  // pScore = &pDouble; // ERROR: different types

  return 0;
}
