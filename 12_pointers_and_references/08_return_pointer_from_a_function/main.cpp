#include <iostream>

int *createArrayOnHeap(size_t size, int init_value = 0);
void display(const int *const array, size_t size);

int main() {
  int *pArray{nullptr};
  size_t size{};
  int init_value{};

  std::cout << "How many integers would you like to allocate? ";
  std::cin >> size;
  std::cout << "What value would you like them initialized to? ";
  std::cin >> init_value;

  pArray = createArrayOnHeap(size, init_value);
  std::cout << "\n=====================================================\n";
  display(pArray, size);

  // NOTE: Always use a TODO comment when you're using a pointer to heap
  delete[] pArray;

  return 0;
}

int *createArrayOnHeap(size_t size, int init_value) {
  // NOTE: NEVER create an uninitialized pointer.
  int *new_storage{nullptr};
  // WARN: NEVER return a pointer to a local variable; Because after function
  // termination, the stack will be popped out. So you should use the heap, or a
  // pointer that is in a safe scope.
  new_storage = new int[size];
  // NOTE: you should if new failed or not.
  // TODO: new_storage is on the heap, deallocate it after using.

  for (size_t i{0}; i < size; ++i) {
    *(new_storage + i) = init_value;
    /* new_storage[i] = init_value; */
  }

  return new_storage;
}

void display(const int *const array, size_t size) {
  for (size_t i{0}; i < size; ++i) {
    std::cout << array[i] << ' ';
    /* std::cout << *(array + i) << ' '; */
  }
  std::cout << '\n';
}
