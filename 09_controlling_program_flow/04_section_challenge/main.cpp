#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

void showOptions();
void printNums(const vector<int> *nums);
void addANumber(int num, vector<int> *nums);
bool contains(const vector<int> *vec, const int &elem);
void calcMean(const vector<int> &vec);
void findSmallest(const vector<int> &vec);
void findLargest(const vector<int> &vec);

int main() {
  char choice{};
  vector<int> nums{};

  showOptions();
  cin >> choice;

  while (choice != 'Q' && choice != 'q') {
    if (choice == 'P' || choice == 'p') {
      printNums(&nums);
    } else if (choice == 'A' || choice == 'a') {
      int num{};
      cout << "Enter an integer to add to the list: ";
      cin >> num;
      addANumber(num, &nums);
    } else if (choice == 'M' || choice == 'm') {
      calcMean(nums);
    } else if (choice == 'S' || choice == 's') {
      findSmallest(nums);
    } else if (choice == 'L' || choice == 'l') {
      findLargest(nums);
    } else {
      cout << "Unknown selection, please try again.\n";
    }

    showOptions();
    cin >> choice;
  }

  cout << "GoodBye...\n";

  return 0;
}

void showOptions() {
  cout << "\n";
  cout << "P - Print numbers\n";
  cout << "A - Add a number\n";
  cout << "M - Display mean of numbers\n";
  cout << "S - Display the smallest number\n";
  cout << "L - Display the largest number\n";
  cout << "Q - Quit\n";

  cout << "Enter your choice: ";
}

void printNums(const vector<int> *pNums) {
  if (pNums->empty()) {
    cout << "[]\n";
    return;
  } else {
    cout << "[ ";
    for (int el : *pNums) {
      cout << el << " ";
    }
    cout << "]\n";
  }
}

void addANumber(int num, vector<int> *nums) {
  if (contains(nums, num)) {
    cout << num << " is already in the list.\n";
  } else {
    nums->push_back(num);
    cout << num << " added\n";
  }
}

bool contains(const vector<int> *vec, const int &elem) {
  if (vec->empty()) {
    return false;
  }

  bool result = false;

  if (find(vec->begin(), vec->end(), elem) != vec->end())
    result = true;

  return result;
}

void calcMean(const vector<int> &vec) {
  if (vec.empty()) {
    cout << "The list is empty.\n";
    cout << "0\n";
    return;
  }

  int sum{0};

  for (int el : vec) {
    sum += el;
  }

  cout << "The mean is " << sum / vec.size() << '\n';
}

void findSmallest(const vector<int> &vec) {
  if (vec.empty()) {
    cout << "The list is empty.\n";
    return;
  }

  int smallest = vec.at(0);
  for (int el : vec) {
    if (el < smallest)
      smallest = el;
  }

  cout << "The smallest numer is " << smallest << '\n';
}

void findLargest(const vector<int> &vec) {
  if (vec.empty()) {
    cout << "The list is empty.\n";
    return;
  }

  int largest = vec.at(0);
  for (int el : vec) {
    if (el > largest)
      largest = el;
  }

  cout << "The largest numer is " << largest << '\n';
}
