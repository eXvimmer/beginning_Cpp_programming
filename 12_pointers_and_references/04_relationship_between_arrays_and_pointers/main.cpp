#include <iostream>

int main() {
  int scores[]{100, 99, 98};

  // NOTE: scores (an array) holds the address of the first element

  std::cout << scores << '\n';  // address of first element
  std::cout << *scores << '\n'; // we can dereference arrays, it's the address
                                // of first element
  int *pScores{scores};

  /* NOTE:
   * we cannot put an & before scores, because scores (an array) is already the
   * address of the first element.
   */

  std::cout << pScores << '\n';
  std::cout << *pScores << '\n';

  /* NOTE:
   * |  subscript notation     |  offset notation
   * -----------------------------------------------------
   * |  array_name[index]      |  *(array_name + index)
   * -----------------------------------------------------
   * |  pointer_name[index]    |  *(pointer_name + index)
   */

  std::cout << "\nArray subscription notation ==============================\n";
  std::cout << scores[0] << '\n';
  std::cout << scores[1] << '\n';
  std::cout << scores[2] << '\n';

  // NOTE: we can almost use array names and pointers interchangably.

  // NOTE: C++ doesn't have true arrays and arrays are just the address of
  // first element in the chunk of memory

  std::cout
      << "\nPointer subscription notation ==============================\n";
  std::cout << pScores[0] << '\n';
  std::cout << pScores[1] << '\n';
  std::cout << pScores[2] << '\n';

  // NOTE: we are not adding 1 to the pointer value, we're adding the size of 1
  // integer to the pointer value. The pointer doesn't hold integers, it holds
  // address of integers (in this case).

  std::cout << "\nPointer offset notation ==============================\n";
  std::cout << *pScores << '\n';       // value of the first element
  std::cout << *(pScores + 1) << '\n'; // value of the second element
  std::cout << *(pScores + 2) << '\n'; // value of the third element

  std::cout << "\nArray offset notation ==============================\n";
  std::cout << *scores << '\n';       // value of the first element
  std::cout << *(scores + 1) << '\n'; // value of the second element
  std::cout << *(scores + 2) << '\n'; // value of the third element

  std::cout << "\nPointer addresses ==============================\n";
  std::cout << pScores << '\n';       // address of the first element
  std::cout << (pScores + 1) << '\n'; // address of the second element
  std::cout << (pScores + 2) << '\n'; // address of the third element

  return 0;
}
