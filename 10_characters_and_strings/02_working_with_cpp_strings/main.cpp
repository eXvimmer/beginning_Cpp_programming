#include <iomanip>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::getline;
using std::string;

int main() {
  // NOTE: these are all objects
  string s0;
  string s1{"Apple"};
  string s2{"Banana"};
  string s3{"Kiwi"};
  string s4{"apple"};
  string s5{s1};       // copy of s1: Apple
  string s6{s1, 0, 3}; // App
  string s7(10, 'X');  // XXXXXXXXXX, NOTE: watch parenthesis

  cout << s0 << '\n'; // no garbage, empty
  cout << s0.length() << '\n';

  cout << "Initialization examples\n----------------------------------\n";
  cout << "s0 is initialized to " << s0 << '\n';
  cout << "s1 is initialized to " << s1 << '\n';
  cout << "s2 is initialized to " << s2 << '\n';
  cout << "s3 is initialized to " << s3 << '\n';
  cout << "s4 is initialized to " << s4 << '\n';
  cout << "s5 is initialized to " << s5 << '\n';
  cout << "s6 is initialized to " << s6 << '\n';
  cout << "s7 is initialized to " << s7 << '\n';

  cout << "\nComparison examples\n----------------------------------\n";
  cout << std::boolalpha;
  cout << s1 << " == " << s5 << " : " << (s1 == s5) << "\n";
  cout << s1 << " == " << s2 << " : " << (s1 == s2) << "\n";
  cout << s1 << " != " << s2 << " : " << (s1 != s2) << "\n";
  cout << s1 << " < " << s2 << " : " << (s1 < s2) << "\n";
  cout << s1 << " > " << s2 << " : " << (s1 > s2) << "\n";
  cout << s2 << " > " << s1 << " : " << (s2 > s1) << "\n";
  cout << s4 << " < " << s5 << " : " << (s4 < s5) << "\n";
  cout << s1 << " == "
       << "Apple"
       << " : " << (s1 == "Apple") << "\n";

  cout << "\nAssignment examples\n----------------------------------\n";
  s1 = "Watermelon";
  cout << "s1 is now: " << s1 << "\n";
  s2 = s1;
  cout << "s2 is now: " << s2 << "\n";

  s3 = "Mustafa";
  s3[1] = 'o'; // Mostafa
  cout << "Change second letter of s3 to o: " << s3 << '\n';
  s3[1] = '0'; // Mostafa
  cout << "Change second letter of s3 to 0: " << s3 << '\n';

  cout << "\nConcatenation examples\n----------------------------------\n";
  s3 = "Watermelon";
  s3 = s5 + " and " + s2 + " juice"; // ERROR: Apple and Watermelon juice;
  cout << s3 << '\n';
  /*  NOTE:
   * s3 = object + C-style string + object + C-style string So this is fine
   */

  // s3 = "nice" + " and " + s5 + " juice"; // Compiler error
  /*  NOTE:
   * Error because, C-style string + C-style string doesn't support +
   * operator. In objects operators are overloaded
   */

  cout << "\nLooping examples\n----------------------------------\n";
  for (size_t i{0}; i < s1.length(); ++i)
    cout << s1.at(i); // or s1[i]
  cout << '\n';

  for (char c : s1)
    cout << c;
  cout << '\n';

  cout << "\nSubstring examples\n----------------------------------\n";
  s1 = "This is a test";
  cout << s1.substr(0, 4) << '\n';  // This
  cout << s1.substr(5, 2) << '\n';  // is
  cout << s1.substr(10, 4) << '\n'; // test

  cout << "\nErasing examples\n----------------------------------\n";
  s1 = "This is a test";
  s1.erase(0, 5);
  cout << "s1 is now: " << s1 << '\n';

  cout << "\ngetline examples\n----------------------------------\n";
  string full_name{};
  cout << "Enter your full name: ";
  getline(cin, full_name);
  cout << "Your full name is " << full_name << ".\n";

  cout << "\nfind examples\n----------------------------------\n";
  s1 = "doom elden ring max payne elder scrolls skyrim witcher";
  cout << "Enter the word to find: ";
  string word{};
  cin >> word;

  size_t position = s1.find(word);
  if (position != string::npos)
    cout << "Found " << word << " at position " << position << ".\n";
  else
    cout << "Sorry, " << word << " not found.\n";

  return 0;
}
