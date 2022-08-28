#include <algorithm>
#include <iostream>
#include <vector>

void showOptions();
void printNums(const std::vector<int> *nums);
void addANumber(int num, std::vector<int> *nums);
bool contains(const std::vector<int> *vec, const int &elem);
void calcMean(const std::vector<int> &vec);
void findSmallest(const std::vector<int> &vec);
void findLargest(const std::vector<int> &vec);

int main() {
  char choice{};
  std::vector<int> nums{};

  showOptions();
  std::cin >> choice;

  while (choice != 'Q' && choice != 'q') {
    if (choice == 'P' || choice == 'p') {
      printNums(&nums);
    } else if (choice == 'A' || choice == 'a') {
      int num{};
      std::cout << "Enter an integer to add to the list: ";
      std::cin >> num;
      addANumber(num, &nums);
    } else if (choice == 'M' || choice == 'm') {
      calcMean(nums);
    } else if (choice == 'S' || choice == 's') {
      findSmallest(nums);
    } else if (choice == 'L' || choice == 'l') {
      findLargest(nums);
    } else {
      std::cout << "Unknown selection, please try again.\n";
    }

    showOptions();
    std::cin >> choice;
  }

  std::cout << "GoodBye...\n";

  return 0;
}

void showOptions() {
  std::cout << "\n";
  std::cout << "P - Print numbers\n";
  std::cout << "A - Add a number\n";
  std::cout << "M - Display mean of numbers\n";
  std::cout << "S - Display the smallest number\n";
  std::cout << "L - Display the largest number\n";
  std::cout << "Q - Quit\n";

  std::cout << "Enter your choice: ";
}

void printNums(const std::vector<int> *pNums) {
  if (pNums->empty()) {
    std::cout << "[]\n";
    return;
  } else {
    std::cout << "[ ";
    for (int el : *pNums) {
      std::cout << el << " ";
    }
    std::cout << "]\n";
  }
}

void addANumber(int num, std::vector<int> *nums) {
  if (contains(nums, num)) {
    std::cout << num << " is already in the list.\n";
  } else {
    nums->push_back(num);
    std::cout << num << " added\n";
  }
}

bool contains(const std::vector<int> *vec, const int &elem) {
  if (vec->empty()) {
    return false;
  }

  bool result = false;

  if (find(vec->begin(), vec->end(), elem) != vec->end())
    result = true;

  return result;
}

void calcMean(const std::vector<int> &vec) {
  if (vec.empty()) {
    std::cout << "The list is empty.\n";
    std::cout << "0\n";
    return;
  }

  int sum{0};

  for (int el : vec) {
    sum += el;
  }

  std::cout << "The mean is " << sum / vec.size() << '\n';
}

void findSmallest(const std::vector<int> &vec) {
  if (vec.empty()) {
    std::cout << "The list is empty.\n";
    return;
  }

  int smallest = vec.at(0);
  for (int el : vec) {
    if (el < smallest)
      smallest = el;
  }

  std::cout << "The smallest numer is " << smallest << '\n';
}

void findLargest(const std::vector<int> &vec) {
  if (vec.empty()) {
    std::cout << "The list is empty.\n";
    return;
  }

  int largest = vec.at(0);
  for (int el : vec) {
    if (el > largest)
      largest = el;
  }

  std::cout << "The largest numer is " << largest << '\n';
}
