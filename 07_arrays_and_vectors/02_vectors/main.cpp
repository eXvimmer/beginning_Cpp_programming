#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int main() {
  /* vector<char> vowels; // empty */
  /* vector<char> vowels(5); // 5 initialized to zero */
  vector<char> vowels{'a', 'e', 'i', 'o', 'u'};
  cout << vowels[0] << '\n';
  cout << vowels[4] << '\n';

  /* vector<int> test_scores (3); // 3 elements, all initialized to zero */
  /* vector<int> test_scores(3, 100); // 3 elements, all initialized to 100 */
  vector<int> test_scores{100, 98, 89};
  cout << test_scores[0] << '\n';
  cout << test_scores.at(1) << '\n';
  /* cout << test_scores.at(4) << '\n'; // error at runtime */
  cout << "There are " << test_scores.size() << " elements in test_scores\n";
  cout << sizeof(test_scores) << '\n'; // 24

  cout << "Enter 3 test scores:\n";
  cin >> test_scores.at(0);
  cin >> test_scores.at(1);
  cin >> test_scores.at(2);

  cout << test_scores.at(0) << '\n';
  cout << test_scores.at(1) << '\n';
  cout << test_scores.at(2) << '\n';

  cout << "Enter a score to add to the vector:\n";
  int score_to_add{0};
  cin >> score_to_add;
  test_scores.push_back(score_to_add);
  cout << '\n' << test_scores.at(test_scores.size() - 1) << '\n';

  // 2D vector
  vector<vector<int>> table{
      {1, 2, 3, 4}, {6, 7, 8, 9}, {11, 12, 13, 14}, {16, 17, 18, 19}};

  cout << table.at(0).at(3) << '\n';

  return 0;
}
