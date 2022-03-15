#include <iostream>

using std::cout;

void print(const int *const pArr, int size);
int *applyAll(const int *const pArr1, int size1, const int *const pArr2,
              int size2);

int main() {
  const size_t array1_size{5};
  const size_t array2_size{3};
  int array1[]{1, 2, 3, 4, 5};
  int array2[]{10, 20, 30};

  cout << "array1: ";
  print(array1, 5);

  cout << "array2: ";
  print(array2, 3);

  int *results1 = applyAll(array1, 5, array2, 3);
  constexpr size_t results_size{array1_size * array2_size};

  /* NOTE:
   * The keyword constexpr was introduced in C++11 and improved in C++14. It
   * means constant expression. Like const, it can be applied to variables: A
   * compiler error is raised when any code attempts to modify the value.
   * Unlike const, constexpr can also be applied to functions and class
   * constructors. constexpr indicates that the value, or return value, is
   * constant and, where possible, is computed at compile time. A constexpr
   * integral value can be used wherever a const integer is required, such as
   * in template arguments and array declarations. And when a value is computed
   * at compile time instead of run time, it helps your program run faster and
   * use less memory. To limit the complexity of compile-time constant
   * computations, and their potential impacts on compilation time, the C++14
   * standard requires the types in constant expressions to be literal types.
   */

  cout << "results1: ";
  print(results1, results_size);

  delete[] results1;

  int *results2 = applyAll(array2, 3, array1, 5);

  cout << "results2: ";
  print(results2, results_size);

  delete[] results2;

  return 0;
}

void print(const int *const pArr, int size) {
  cout << "[ ";
  for (int i{0}; i < size; ++i) {
    cout << pArr[i] << ' ';
  }
  cout << "]\n";
}

int *applyAll(const int *const pArr1, int size1, const int *const pArr2,
              int size2) {
  int *new_arr{nullptr};

  new_arr = new int[size1 * size2];

  int position{0};
  for (int i{0}; i < size2; ++i) {
    for (int j{0}; j < size1; ++j) {
      new_arr[position] = pArr1[j] * pArr2[i];
      position++;
    }
  }

  return new_arr;
}
