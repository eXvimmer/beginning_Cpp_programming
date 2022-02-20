#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main() {
  vector<int> vector1{}, vector2{};

  vector1.push_back(10);
  vector1.push_back(20);
  cout << vector1.at(0) << '\n';
  cout << vector1.at(1) << '\n';
  cout << "The size of vector1 is: " << vector1.size() << '\n';

  vector2.push_back(100);
  vector2.push_back(200);
  cout << vector2.at(0) << '\n';
  cout << vector2.at(1) << '\n';
  cout << "The size of vector2 is: " << vector2.size() << '\n';

  vector<vector<int>> vector_2d{};
  vector_2d.push_back(vector1);
  vector_2d.push_back(vector2);

  cout << "Vector_2d:\n";
  cout << vector_2d.at(0).at(0) << '\n';
  cout << vector_2d.at(0).at(1) << '\n';
  cout << vector_2d.at(1).at(0) << '\n';
  cout << vector_2d.at(1).at(1) << '\n';

  vector1.at(0) = 1000;

  cout << "Vector_2d after change:\n";
  cout << vector_2d.at(0).at(0) << '\n'; // NOTE: not changed
  cout << vector_2d.at(0).at(1) << '\n';
  cout << vector_2d.at(1).at(0) << '\n';
  cout << vector_2d.at(1).at(1) << '\n';

  cout << "Vector1 after change:\n";
  cout << vector1.at(0) << '\n'; // NOTE: changed
  cout << vector1.at(1) << '\n';
  cout << "The size of vector1 is: " << vector1.size() << '\n';

  return 0;
}
