#include <ios>
#include <iostream>
#include <string>

int main() {
  int scores[]{100, 95, 90, 85, -1};
  int *pScores{scores};

  while (*pScores != -1) {
    std::cout << *pScores << '\n';
    pScores++; // increment by the size of int (in this case) => next address
  }

  std::cout << "\n--------------------------\n";
  pScores = scores; // first element
  // same
  while (*pScores != -1)
    std::cout << *pScores++
              << '\n'; // same precedence for * and ++ so rtl associativity

  std::cout << "\n--------------------------\n";
  std::string s1{"Mustafa"};
  std::string s2{"Mustafa"};
  std::string s3{"Malena"};

  std::string *pStr1{&s1};
  std::string *pStr2{&s2};
  std::string *pStr3{&s1};

  std::cout << std::boolalpha;

  // addresses
  std::cout << pStr1 << " == " << pStr2 << ": " << (pStr1 == pStr2)
            << '\n'; // false
  std::cout << pStr1 << " == " << pStr3 << ": " << (pStr1 == pStr3)
            << '\n'; // true

  // values
  std::cout << *pStr1 << " == " << *pStr2 << ": " << (*pStr1 == *pStr2)
            << '\n'; // true
  std::cout << *pStr1 << " == " << *pStr3 << ": " << (*pStr1 == *pStr3)
            << '\n'; // true

  pStr3 = &s3; // points to Malena
  std::cout << *pStr1 << " == " << *pStr3 << ": " << (*pStr1 == *pStr3)
            << '\n'; // false

  std::cout << "\n--------------------------\n";
  char name[]{"Mustafa"};
  char *pChar1{nullptr};
  char *pChar2{nullptr};

  pChar1 = &name[0]; // &'M'
  pChar2 = &name[3]; // &'t';

  std::cout << "In the std::string " << name << ", " << *pChar2 << " is "
            << (pChar2 - pChar1) << " characters away from " << *pChar1 << '\n';

  return 0;
}
