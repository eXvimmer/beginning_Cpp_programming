#include <iomanip>
#include <iostream>
#include <string>

int main() {
  // NOTE: these are all objects
  std::string s0;
  std::string s1{"Apple"};
  std::string s2{"Banana"};
  std::string s3{"Kiwi"};
  std::string s4{"apple"};
  std::string s5{s1};       // copy of s1: Apple
  std::string s6{s1, 0, 3}; // App
  std::string s7(10, 'X');  // XXXXXXXXXX, NOTE: watch parenthesis

  std::cout << s0 << '\n'; // no garbage, empty
  std::cout << s0.length() << '\n';

  std::cout << "Initialization examples\n----------------------------------\n";
  std::cout << "s0 is initialized to " << s0 << '\n';
  std::cout << "s1 is initialized to " << s1 << '\n';
  std::cout << "s2 is initialized to " << s2 << '\n';
  std::cout << "s3 is initialized to " << s3 << '\n';
  std::cout << "s4 is initialized to " << s4 << '\n';
  std::cout << "s5 is initialized to " << s5 << '\n';
  std::cout << "s6 is initialized to " << s6 << '\n';
  std::cout << "s7 is initialized to " << s7 << '\n';

  std::cout << "\nComparison examples\n----------------------------------\n";
  std::cout << std::boolalpha;
  std::cout << s1 << " == " << s5 << " : " << (s1 == s5) << "\n";
  std::cout << s1 << " == " << s2 << " : " << (s1 == s2) << "\n";
  std::cout << s1 << " != " << s2 << " : " << (s1 != s2) << "\n";
  std::cout << s1 << " < " << s2 << " : " << (s1 < s2) << "\n";
  std::cout << s1 << " > " << s2 << " : " << (s1 > s2) << "\n";
  std::cout << s2 << " > " << s1 << " : " << (s2 > s1) << "\n";
  std::cout << s4 << " < " << s5 << " : " << (s4 < s5) << "\n";
  std::cout << s1 << " == "
            << "Apple"
            << " : " << (s1 == "Apple") << "\n";

  std::cout << "\nAssignment examples\n----------------------------------\n";
  s1 = "Watermelon";
  std::cout << "s1 is now: " << s1 << "\n";
  s2 = s1;
  std::cout << "s2 is now: " << s2 << "\n";

  s3 = "Mustafa";
  s3[1] = 'o'; // Mostafa
  std::cout << "Change second letter of s3 to o: " << s3 << '\n';
  s3[1] = '0'; // Mostafa
  std::cout << "Change second letter of s3 to 0: " << s3 << '\n';

  std::cout << "\nConcatenation examples\n----------------------------------\n";
  s3 = "Watermelon";
  s3 = s5 + " and " + s2 + " juice"; // ERROR: Apple and Watermelon juice;
  std::cout << s3 << '\n';
  /*  NOTE:
   * s3 = object + C-style string + object + C-style string So this is fine
   */

  // s3 = "nice" + " and " + s5 + " juice"; // Compiler error
  /*  NOTE:
   * Error because, C-style string + C-style string doesn't support +
   * operator. In objects operators are overloaded
   */

  std::cout << "\nLooping examples\n----------------------------------\n";
  for (size_t i{0}; i < s1.length(); ++i)
    std::cout << s1.at(i); // or s1[i]
  std::cout << '\n';

  for (char c : s1)
    std::cout << c;
  std::cout << '\n';

  std::cout << "\nSubstring examples\n----------------------------------\n";
  s1 = "This is a test";
  std::cout << s1.substr(0, 4) << '\n';  // This
  std::cout << s1.substr(5, 2) << '\n';  // is
  std::cout << s1.substr(10, 4) << '\n'; // test

  std::cout << "\nErasing examples\n----------------------------------\n";
  s1 = "This is a test";
  s1.erase(0, 5);
  std::cout << "s1 is now: " << s1 << '\n';

  std::cout << "\ngetline examples\n----------------------------------\n";
  std::string full_name{};
  std::cout << "Enter your full name: ";
  std::getline(std::cin, full_name);
  std::cout << "Your full name is " << full_name << ".\n";

  std::cout << "\nfind examples\n----------------------------------\n";
  s1 = "doom elden ring max payne elder scrolls skyrim witcher";
  std::cout << "Enter the word to find: ";
  std::string word{};
  std::cin >> word;

  size_t position = s1.find(word);
  if (position != std::string::npos)
    std::cout << "Found " << word << " at position " << position << ".\n";
  else
    std::cout << "Sorry, " << word << " not found.\n";

  return 0;
}
