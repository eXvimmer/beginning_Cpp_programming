#include <cctype>
#include <cstring>
#include <iostream>

using std::cin;
using std::cout;

int main() {
  // C style string variables
  char something[20];
  cout << something; // Will display GARBAGE or nothing!

  char first_name[20]{};
  char last_name[20]{};
  char full_name[50]{};

  cout << "\nPlease enter your first name: ";
  cin >> first_name;

  cout << "Please enter your last name: ";
  cin >> last_name;

  cout << "\nHello " << first_name << ". Your name has " << strlen(first_name)
       << " characters\nand your last name, " << last_name << ", has "
       << strlen(last_name) << " characters.\n";

  strcpy(full_name, first_name); // copy first_name to full_name
  strcat(full_name, " ");        // concatenate a space to full_name
  strcat(full_name, last_name);
  cout << "Your full name is " << full_name << ".\n";

  /* char temp[50]{}; */
  /* cout << "Etner your full name: "; */
  /* cin >> temp; */
  /* cout << "temp is " << temp << '\n'; */

  /* char temp[50]{}; */
  /* cout << "Etner your full name: "; */
  /* cin.getline(temp, 50); // this doesn't work in my system */
  /* cout << "temp is " << temp << '\n'; */

  char temp[50]{};
  strcpy(temp, full_name);

  if (strcmp(temp, full_name) == 0)
    cout << temp << " and " << full_name << " are the same.\n";
  else
    cout << temp << " and " << full_name << " are different.\n";

  cout << "Result of comparing " << temp << " and " << full_name << ": "
       << strcmp(temp, full_name) << std::endl;

  for (size_t i{0}; i < strlen(full_name); ++i) {
    if (std::isalpha(full_name[i]))
      full_name[i] = toupper(full_name[i]);
  }

  if (strcmp(temp, full_name) == 0)
    cout << temp << " and " << full_name << " are the same.\n";
  else
    cout << temp << " and " << full_name << " are different.\n";

  cout << "Result of comparing " << temp << " and " << full_name << ": "
       << strcmp(temp, full_name) << std::endl;

  return 0;
}
