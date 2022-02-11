#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
  int favorite_number;
  cout << "Enter your favorite number between 1 and 100\n";
  cin >> favorite_number;
  cout << "Amazing " << favorite_number << " is my favorite number too."
       << endl;

  return 0;
}
