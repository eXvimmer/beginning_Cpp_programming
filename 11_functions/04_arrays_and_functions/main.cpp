#include <iostream>

void print_array(const int arr[], size_t size);
// set each array element to value
void set_array(int arr[], size_t size, int val = 0);

int main() {
  int my_scores[]{100, 98, 90, 86, 89};
  print_array(my_scores, 5);

  set_array(my_scores, 5, 13);
  print_array(my_scores, 5);

  set_array(my_scores, 5); // use the default value
  print_array(my_scores, 5);

  return 0;
}

void print_array(const int arr[], size_t size) {
  for (size_t i{0}; i < size; ++i) {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';
}

void set_array(int arr[], size_t size, int val) {
  for (size_t i{0}; i < size; ++i) {
    arr[i] = val;
  }
}
