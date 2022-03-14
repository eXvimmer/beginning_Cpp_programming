#include <iostream>

using std::cin;
using std::cout;

int *createArray(size_t size, int init_value = 0);
void display(const int *const array, size_t size);

int main() {
  int *pArray{nullptr};
  size_t size{};
  int init_value{};

  cout << "How many integers would you like to allocate? ";
  cin >> size;
  cout << "What value would you like them initialized to? ";
  cin >> init_value;

  pArray = createArray(size, init_value);
  cout << "\n=====================================================\n";
  display(pArray, size);

  // NOTE: Always use a TODO comment when you're using a pointer to heap
  delete[] pArray;

  return 0;
}

int *createArray(size_t size, int init_value) {
  int *new_storage{nullptr};
  new_storage = new int[size];
  // WARNING: new_storage is on the heap, deallocate after using it

  for (size_t i{0}; i < size; ++i) {
    *(new_storage + i) = init_value;
    /* new_storage[i] = init_value; */
  }

  return new_storage;
}

void display(const int *const array, size_t size) {
  for (size_t i{0}; i < size; ++i) {
    cout << array[i] << ' ';
  }
  cout << '\n';
}
