#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>

void display(std::array<int, 5> &arr) {
  std::cout << "[ ";
  for (const int &el : arr) {
    std::cout << el << ' ';
  }
  std::cout << ']' << std::endl;
}

void test1() {
  std::cout << "======================TEST1=======================\n";
  std::array<int, 5> arr1{1, 2, 3, 4, 5}; //  double {{}} if C++11
  std::array<int, 5> arr2;                // will contain garbage
  display(arr1);
  display(arr2);

  arr2 = {10, 20, 30, 40, 50};
  display(arr1);
  display(arr2);

  std::cout << "Size of arr1 is " << arr1.size() << std::endl;
  std::cout << "Size of arr2 is " << arr2.size() << std::endl;

  arr1[0] = 1000;    // doesn't do bounds checking
  arr1.at(1) = 2000; // does bound checking
  display(arr1);

  std::cout << "Front of arr2: " << arr2.front() << std::endl;
  std::cout << "Back of arr2: " << arr2.back() << std::endl;
}

void test2() {
  std::cout << "======================TEST2=======================\n";
  std::array<int, 5> arr1{1, 2, 3, 4, 5};
  std::array<int, 5> arr2{10, 20, 30, 40, 50};
  display(arr1);
  display(arr2);
  arr1.fill(0);
  display(arr1);
  display(arr2);
  arr1.swap(arr2);
  display(arr1);
  display(arr2);
}

void test3() {
  std::cout << "======================TEST3=======================\n";
  std::array<int, 5> arr1{1, 2, 3, 4, 5};
  int *ptr{arr1.data()}; // data() returns the raw pointer to the raw array
  std::cout << ptr << std::endl;
  *ptr = 10'000;
  display(arr1);
}

void test4() {
  std::cout << "======================TEST4=======================\n";
  std::array<int, 5> arr1{2, 1, 5, 3, 4};
  display(arr1);
  std::sort(arr1.begin(), arr1.end());
  display(arr1);
}

void test5() {
  std::cout << "======================TEST5=======================\n";
  std::array<int, 5> arr{2, 1, 5, 3, 4};
  std::array<int, 5>::iterator min_num{
      std::min_element(arr.begin(), arr.end())};
  auto max_num = std::max_element(arr.begin(), arr.end());
  std::cout << "min value: " << *min_num << " and max value: " << *max_num
            << '\n';
}

void test6() {
  std::cout << "======================TEST6=======================\n";
  std::array<int, 5> arr{2, 1, 3, 3, 5};
  auto adjacent = std::adjacent_find(arr.begin(), arr.end());
  if (adjacent != arr.end()) {
    std::cout << "adjacent element found with value: " << *adjacent << '\n';
  } else {
    std::cout << "No adjacent element found.\n";
  }
}

void test7() {
  std::cout << "======================TEST7=======================\n";
  std::array<int, 5> arr{1, 2, 3, 4, 5};
  // TODO: you should #include <numeric>
  int sum{std::accumulate(arr.begin(), arr.end(), 0)};
  std::cout << "Sum of elements in arr is: " << sum << '\n';
}

void test8() {
  std::cout << "======================TEST8=======================\n";
  std::array<int, 10> arr{1, 2, 3, 1, 2, 3, 3, 3, 3, 3};
  auto count = std::count(arr.begin(), arr.end(), 3);
  std::cout << "found " << count << " occurence of 3\n";
}

void test9() {
  std::cout << "======================TEST9=======================\n";
  std::array<int, 10> arr{1, 2, 3, 50, 60, 70, 80, 200, 300, 400};
  auto count = std::count_if(arr.begin(), arr.end(),
                             [](int x) { return x > 10 && x < 200; });
  std::cout << "found " << count << " number between 10 and 200";
}
int main() {
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
  test8();
  test9();

  return 0;
}
