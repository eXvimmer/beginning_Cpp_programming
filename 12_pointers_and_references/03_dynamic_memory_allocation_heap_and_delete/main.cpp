#include <iostream>

using std::cin;
using std::cout;

int main() {
  int *pInt{nullptr};
  pInt = new int; // allocate memory from heap, kinda like malloc
  cout << pInt << '\n';

  /* NOTE:
   * pInt holds the address of newly created integer, if we lose it,then we'll
   * have memory leak. e.g. if we do:  pInt = nullptr; then we have a memory
   * leak and we cannot deallocate the pInt.
   */

  delete pInt; // free allocated storage

  size_t size{0};
  double *pDouble{nullptr};

  cout << "How many temps do you want to insert? ";
  cin >> size;

  pDouble = new double[size];
  // allocate n (size) temperature (doubles) in memory and store the address of
  // the first element in pDouble.
  cout << pDouble << '\n';
  delete[] pDouble; // NOTE: you should insert [] in this case

  return 0;
}
