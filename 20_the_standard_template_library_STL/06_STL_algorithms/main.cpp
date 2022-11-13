#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>

// NOTE: Whenever you use STL or algorithms, your custom types need a way to
// be comparable. So it's better to overload operators like < and ==

// An object represeting a Person
class Person {
public:
  Person() = default;
  Person(std::string name, int age) : name{name}, age{age} {}
  bool operator<(const Person &obj) const { return this->age < obj.age; }
  bool operator==(const Person &obj) const {
    return this->age == obj.age && this->name == obj.name;
  }

private:
  std::string name;
  int age;
};

void find_number() {
  std::cout << "======================TEST1=======================\n";
  std::vector<int> nums{1, 2, 3, 4, 5};
  /* auto loc = std::find(nums.begin(), nums.end(), 1); */
  auto loc = std::find(std::begin(nums), std::end(nums), 1);
  /* if (loc != nums.end()) { */
  if (loc != std::end(nums)) {
    std::cout << "Found the number: " << *loc << std::endl;
  } else {
    std::cout << "Couldn't find the number.\n";
  }
}

void find_Player() {
  std::cout << "======================TEST2=======================\n";
  std::list<Person> players{{"Mustafa", 30}, {"Malena", 26}, {"Emily", 24}};
  // NOTE: you need to overload the operator==, for this to work

  // auto loc =
  //  std::find(std::begin(players), std::end(players), Person{"Malena", 26});
  auto loc = std::find(players.begin(), players.end(), Person{"Malena", 26});
  if (loc != std::end(players)) {
    std::cout << "Found the player" << std::endl;
  } else {
    std::cout << "Couldn't find the player.\n";
  }
}

void count_numbers() {
  std::cout << "======================TEST3=======================\n";
  std::vector<int> nums{1, 2, 3, 1, 4, 5, 1};
  auto num = std::count(nums.begin(), nums.end(), 1);
  std::cout << num << " occurences found" << std::endl;
}

void count_if_test() {
  std::cout << "======================TEST4=======================\n";
  // count only if the element is even
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 88, 100}; // 6 even numbers
  auto num =
      std::count_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });
  std::cout << num << " even numbers found\n";
  num = std::count_if(vec.begin(), vec.end(), [](int x) { return x % 2 != 0; });
  std::cout << num << " odd numbers found\n";
}

void count_if_greater_than_5() {
  std::cout << "======================TEST5=======================\n";
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 88, 100}; // 6 numbers > 5
  auto num = std::count_if(vec.begin(), vec.end(), [](int x) { return x > 5; });
  std::cout << num << " numbers are greater than 5\n";
}

void replace_test() {
  std::cout << "======================TEST6=======================\n";
  std::vector<int> vec{1, 2, 3, 4, 5, 1, 2, 1};

  std::cout << "[ ";
  for (const auto &i : vec) {
    std::cout << i << ' ';
  }
  std::cout << ']' << std::endl;

  std::replace(vec.begin(), vec.end(), 1, 88);

  std::cout << "[ ";
  for (const auto &i : vec) {
    std::cout << i << ' ';
  }
  std::cout << ']' << std::endl;
}

void all_of_test() {
  std::cout << "======================TEST7=======================\n";
  std::vector<int> vec{1, 2, 3, 4, 13, 14, 18, 19};

  if (std::all_of(vec.begin(), vec.end(), [](int x) { return x > 10; })) {
    std::cout << "All elements are greater than 10\n";
  } else {
    std::cout << "Not all elements are greater than 10\n";
  }

  if (std::all_of(vec.begin(), vec.end(), [](int x) { return x < 20; })) {
    std::cout << "All elements are less than 20\n";
  } else {
    std::cout << "Not all elements are less than 20\n";
  }
}

void any_of_test() {
  std::cout << "======================TEST8=======================\n";
  std::vector<int> vec{1, 2, 3, 4, 13, 14, 18, 19};

  if (std::any_of(vec.begin(), vec.end(), [](int x) { return x > 10; })) {
    std::cout << "Some elements are greater than 10\n";
  } else {
    std::cout << "None of elements are greater than 10\n";
  }

  if (std::all_of(vec.begin(), vec.end(), [](int x) { return x < 20; })) {
    std::cout << "Some of elements are less than 20\n";
  } else {
    std::cout << "None of elements are less than 20\n";
  }
}

void string_transform_test() {
  std::cout << "======================TEST9=======================\n";
  std::string str1{"This is a test"};
  std::cout << "Before transform: " << str1 << std::endl;
  std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
  // NOTE: ::toupper means toupper in 'global scope';
  std::cout << "After transform: " << str1 << std::endl;
}

int main() {
  find_number();
  find_Player();
  count_numbers();
  count_if_test();
  count_if_greater_than_5();
  replace_test();
  all_of_test();
  any_of_test();
  string_transform_test();

  return 0;
}
