#include <iostream>
#include <string>

using std::cin;
using std::cout;

int main() {
  char letter_grade{};
  cout << "Enter the letter grade you expect on the exam: ";
  cin >> letter_grade;

  switch (letter_grade) {
  case 'a':
  case 'A':
    cout << "You need a 90 or above; Study hard!\n";
    break;
  case 'b':
  case 'B':
    cout << "You need a 80-89 for B; Go study!\n";
    break;
  case 'c':
  case 'C':
    cout << "You need 70-79 for an average grade\n";
    break;
  case 'd':
  case 'D':
    cout << "You should strive for a better grade. All you need is 60-69\n";
    break;
  case 'f':
  case 'F': {
    char confirm;
    cout << "Are you sure? (y/n): ";
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y')
      cout << "OK, I guess you didn't study\n";
    else if (confirm == 'n' || confirm == 'N')
      cout << "Good; Go study!\n";
    else
      cout << "Illegal choice\n";

    break;
  }
  default:
    cout << "Sorry, not a valid grade\n";
  }

  cout << "\n========================================\n";

  enum Direction { left, right, up, down };

  Direction heading{up};

  switch (heading) {
  case left:
    cout << "Going left\n";
    break;
  case right:
    cout << "Going right\n";
    break;
  case up:
    cout << "Going up\n";
    break;
  case down:
    cout << "Going down\n";
    break;
  default:
    cout << "Never should run.\n";
  }

  return 0;
}
