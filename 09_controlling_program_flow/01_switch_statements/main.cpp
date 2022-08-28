#include <iostream>
#include <string>

int main() {
  char letter_grade{};
  std::cout << "Enter the letter grade you expect on the exam: ";
  std::cin >> letter_grade;

  switch (letter_grade) {
  case 'a':
  case 'A':
    std::cout << "You need a 90 or above; Study hard!\n";
    break;
  case 'b':
  case 'B':
    std::cout << "You need a 80-89 for B; Go study!\n";
    break;
  case 'c':
  case 'C':
    std::cout << "You need 70-79 for an average grade\n";
    break;
  case 'd':
  case 'D':
    std::cout
        << "You should strive for a better grade. All you need is 60-69\n";
    break;
  case 'f':
  case 'F': {
    char confirm;
    std::cout << "Are you sure? (y/n): ";
    std::cin >> confirm;

    if (confirm == 'y' || confirm == 'Y')
      std::cout << "OK, I guess you didn't study\n";
    else if (confirm == 'n' || confirm == 'N')
      std::cout << "Good; Go study!\n";
    else
      std::cout << "Illegal choice\n";

    break;
  }
  default:
    std::cout << "Sorry, not a valid grade\n";
  }

  std::cout << "\n========================================\n";

  enum Direction { left, right, up, down };

  Direction heading{up};

  switch (heading) {
  case left:
    std::cout << "Going left\n";
    break;
  case right:
    std::cout << "Going right\n";
    break;
  case up:
    std::cout << "Going up\n";
    break;
  case down:
    std::cout << "Going down\n";
    break;
  default:
    std::cout << "Never should run.\n";
  }

  return 0;
}
