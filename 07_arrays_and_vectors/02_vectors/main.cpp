#include <iostream>
#include <vector>

int main() {
  /* std::vector<char> vowels; // empty */
  /* std::vector<char> vowels(5); // 5 initialized to zero */
  std::vector<char> vowels{'a', 'e', 'i', 'o', 'u'};
  std::cout << vowels[0] << '\n';
  std::cout << vowels[4] << '\n';

  /* std::vector<int> test_scores (3); // 3 elements, all initialized to zero */
  /* std::vector<int> test_scores(3, 100); // 3 elements, all initialized to 100
   */
  std::vector<int> test_scores{100, 98, 89};
  std::cout << test_scores[0] << '\n';
  std::cout << test_scores.at(1) << '\n';
  /* std::cout << test_scores.at(4) << '\n'; // error at runtime */
  std::cout << "There are " << test_scores.size()
            << " elements in test_scores\n";
  std::cout << sizeof(test_scores) << '\n'; // 24

  std::cout << "Enter 3 test scores:\n";
  std::cin >> test_scores.at(0);
  std::cin >> test_scores.at(1);
  std::cin >> test_scores.at(2);

  std::cout << test_scores.at(0) << '\n';
  std::cout << test_scores.at(1) << '\n';
  std::cout << test_scores.at(2) << '\n';

  std::cout << "Enter a score to add to the std::vector:\n";
  int score_to_add{0};
  std::cin >> score_to_add;
  test_scores.push_back(score_to_add);
  std::cout << '\n' << test_scores.at(test_scores.size() - 1) << '\n';

  // 2D std::vector
  std::vector<std::vector<int>> table{
      {1, 2, 3, 4}, {6, 7, 8, 9}, {11, 12, 13, 14}, {16, 17, 18, 19}};

  std::cout << table.at(0).at(3) << '\n';

  return 0;
}
