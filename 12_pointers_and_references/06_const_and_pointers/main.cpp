#include <iostream>

int main() {
  int high_score{100}, low_score{13};

  const int *pScore{&high_score};
  // NOTE: pScore is a pointer to an integer constant, this means we cannot
  // change the value of the integer that pScore is pointing to.

  // *pScore = 50;     // ERROR:
  pScore = &low_score; // OK

  int *const pScore2{&high_score};
  // NOTE: pScore2 is a constant pointer to an integer. This means we can change
  // the value of the integer the pointer is pointing to, but we cannot change
  // the address that the pointer holds.

  // pScore2 = &low_score; // ERROR:
  *pScore2 = 99; // OK

  const int *const pScore3{&high_score};
  // NOTE: pScore3 is a constant pointer to an integer constant. This means
  // neither the pointer nor the data pointed to by the pointer can be changed.

  return 0;
}
