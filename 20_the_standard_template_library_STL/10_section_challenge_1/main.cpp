#include <algorithm>
#include <cctype>
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

bool is_palindrome(const std::string &s) {
  if (s.length() <= 1)
    return true;
  std::deque<char> cleaned, reversed;
  std::copy_if(s.begin(), s.end(), std::back_inserter(cleaned),
               [](char c) { return std::isalpha(c); });
  std::transform(cleaned.begin(), cleaned.end(), cleaned.begin(),
                 [](char c) { return std::tolower(c); });
  std::copy(cleaned.begin(), cleaned.end(), std::front_inserter(reversed));
  /* return std::equal(cleaned.begin(), cleaned.end(), reversed.begin()); */
  return cleaned == reversed;
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
