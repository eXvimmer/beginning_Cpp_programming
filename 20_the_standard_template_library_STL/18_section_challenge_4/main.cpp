#include <cctype>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <string>

bool is_palindrome(const std::string &s) {
  if (s.length() <= 1)
    return true;
  std::queue<char> straight;
  std::stack<char> reversed;
  for (const char &c : s) {
    if (std::isalpha(c)) {
      auto l = std::tolower(c);
      straight.push(l);
      reversed.push(l);
    }
  }
  char c1, c2;
  while (!reversed.empty()) {
    c1 = straight.front();
    c2 = reversed.top();
    if (c1 != c2) {
      return false;
    }
    straight.pop();
    reversed.pop();
  }
  return true;
}

int main() {
  std::vector<std::string> test_strings{
      "a",
      "aa",
      "aba",
      "abba",
      "abbcbba",
      "ab",
      "abc",
      "radar",
      "bob",
      "ana",
      "avid diva",
      "Amore, Roma",
      "A Toyota's a toyota",
      "A Santa at NASA",
      "C++",
      "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!",
      "This is a palindrome",
      "palindrome"};

  std::cout << std::boolalpha;
  std::cout << std::setw(8) << std::left << "Result"
            << "String" << std::endl;
  for (const auto &s : test_strings) {
    std::cout << std::setw(8) << std::left << is_palindrome(s) << s
              << std::endl;
  }
  std::cout << std::endl;
  return 0;
}
