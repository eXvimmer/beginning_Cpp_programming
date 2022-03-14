#include <ios>
#include <iostream>
#include <string>

using std::cout;
using std::string;

int main() {
  int scores[]{100, 95, 90, 85, -1};
  int *pScores{scores};

  while (*pScores != -1) {
    cout << *pScores << '\n';
    pScores++; // increment by the size of int (in this case) => next address
  }

  cout << "\n--------------------------\n";
  pScores = scores; // first element
  // same
  while (*pScores != -1)
    cout << *pScores++
         << '\n'; // same precedence for * and ++ so rtl associativity

  cout << "\n--------------------------\n";
  string s1{"Mustafa"};
  string s2{"Mustafa"};
  string s3{"Malena"};

  string *pStr1{&s1};
  string *pStr2{&s2};
  string *pStr3{&s1};

  cout << std::boolalpha;

  // addresses
  cout << pStr1 << " == " << pStr2 << ": " << (pStr1 == pStr2) << '\n'; // false
  cout << pStr1 << " == " << pStr3 << ": " << (pStr1 == pStr3) << '\n'; // true

  // values
  cout << *pStr1 << " == " << *pStr2 << ": " << (*pStr1 == *pStr2)
       << '\n'; // true
  cout << *pStr1 << " == " << *pStr3 << ": " << (*pStr1 == *pStr3)
       << '\n'; // true

  pStr3 = &s3; // points to Malena
  cout << *pStr1 << " == " << *pStr3 << ": " << (*pStr1 == *pStr3)
       << '\n'; // false

  cout << "\n--------------------------\n";
  char name[]{"Mustafa"};
  char *pChar1{nullptr};
  char *pChar2{nullptr};

  pChar1 = &name[0]; // &'M'
  pChar2 = &name[3]; // &'t';

  cout << "In the string " << name << ", " << *pChar2 << " is "
       << (pChar2 - pChar1) << " characters away from " << *pChar1 << '\n';

  return 0;
}
