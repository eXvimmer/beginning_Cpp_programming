#include <iostream>

using std::cout;

void print_array(const int arr[], size_t size);
// set each array element to value
void set_array(int arr[], size_t size, int val);

int main() {
  int my_scores[]{100, 98, 90, 86, 89};

  print_array(my_scores, 5);
  set_array(my_scores, 5, 0);
  print_array(my_scores, 5);

  return 0;
}

void print_array(const int arr[], size_t size) {
  for (size_t i{0}; i < size; ++i)
    cout << arr[i] << ' ';

  cout << '\n';
}

void set_array(int arr[], size_t size, int val) {
  for (size_t i = 0; i < size; ++i)
    arr[i] = val;
}