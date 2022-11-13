#include <iostream>
#include <list>
#include <map>
#include <vector>

// display any vector of integers using range-based for loop
void display(const std::vector<int> &vec) {
  std::cout << "[ ";
  for (const auto &i : vec) {
    std::cout << i << ' ';
  }
  std::cout << ']' << std::endl;

  /*
  auto it = vec.begin();
  while (it != vec.end()) {
    std::cout << *it;
    if (it == vec.end() - 1) {
      std::cout << ']';
      // ++it;
      break;
    } else {
      std::cout << ' ';
      ++it;
    }
  }
  */
}

void test1() {
  std::cout << "======================TEST1=======================\n";
  std::vector<int> nums{1, 2, 3, 4, 5};
  /* std::vector<int>::iterator it; */
  // NOTE: iterators are objects that use pointer notation by design
  auto it = nums.begin();
  std::cout << *it << '\n'; // 1

  it++;
  std::cout << *it << '\n'; // 2

  it += 2;
  std::cout << *it << '\n'; // 4

  it -= 2;
  std::cout << *it << '\n'; // 2

  it = nums.end() - 1;
  std::cout << *it << '\n'; // 5
}

void test2() {
  std::cout << "======================TEST2=======================\n";
  std::vector<int> nums{1, 2, 3, 4, 5};
  std::vector<int>::iterator it = nums.begin();
  while (it != nums.end()) {
    std::cout << *it << std::endl;
    ++it;
  }

  it = nums.begin();
  while (it != nums.end()) {
    *it = 0;
    ++it;
  }
  display(nums);
}

void test3() {
  std::cout << "======================TEST3=======================\n";
  std::vector<int> nums{1, 2, 3, 4, 5};
  // NOTE: you cannot change the value of what a constant iterator is pointing
  // to
  std::vector<int>::const_iterator it = nums.begin();
  /* auto it = nums.cbegin(); */
  while (it != nums.end()) {
    std::cout << *it << std::endl;
    ++it;
  }

  /*
  it = nums.begin();
  while (it != nums.end()) {
    *it = 0; // ERROR: readonly
    ++it;
  }
  */
  display(nums);
}

void test4() {
  std::cout << "======================TEST4=======================\n";
  std::vector<int> nums{1, 2, 3, 4, 5};
  /* std::vector<int>::reverse_iterator it = nums.rbegin(); */
  auto it = nums.rbegin(); // starts at 5
  while (it != nums.rend()) {
    std::cout << *it << std::endl;
    ++it; // NOTE: we increment
  }

  std::list<std::string> names{"Mustafa", "Malena", "Emily"};
  auto it1 = names.crbegin(); // constant reverse iterator
  std::cout << *it1 << '\n';  // Emily
  it1++;
  std::cout << *it1 << '\n'; // Malena

  std::map<std::string, std::string> favorits{{"Mustafa", "C++"},
                                              {"Barbara", "Architecture"},
                                              {"Emily", "Python"},
                                              {"Malena", "Art"}};
  auto it2 = favorits.begin();
  while (it2 != favorits.end()) {
    std::cout << it2->first << ": " << it2->second << '\n';
    ++it2;
  }
}

void test5() {
  std::cout << "======================TEST5=======================\n";
  // iterate over a subset of a container
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto start = vec.begin() + 2; // 3
  auto finish = vec.end() - 3;  // 8
  while (start != finish) {
    std::cout << *start << std::endl;
    ++start;
  }
}

int main() {
  test1();
  test2();
  test3();
  test4();
  test5();

  return 0;
}
