#include <iostream>
#include <vector>

int main() {
  std::vector<int> vector1{}, vector2{};

  vector1.push_back(10);
  vector1.push_back(20);
  std::cout << vector1.at(0) << '\n';
  std::cout << vector1.at(1) << '\n';
  std::cout << "The size of vector1 is: " << vector1.size() << '\n';

  vector2.push_back(100);
  vector2.push_back(200);
  std::cout << vector2.at(0) << '\n';
  std::cout << vector2.at(1) << '\n';
  std::cout << "The size of vector2 is: " << vector2.size() << '\n';

  std::vector<std::vector<int>> vector_2d{};
  vector_2d.push_back(vector1);
  vector_2d.push_back(vector2);

  std::cout << "Vector_2d:\n";
  std::cout << vector_2d.at(0).at(0) << '\n';
  std::cout << vector_2d.at(0).at(1) << '\n';
  std::cout << vector_2d.at(1).at(0) << '\n';
  std::cout << vector_2d.at(1).at(1) << '\n';

  vector1.at(0) = 1000;

  std::cout << "Vector_2d after change:\n";
  std::cout << vector_2d.at(0).at(0) << '\n'; // NOTE: not changed
  std::cout << vector_2d.at(0).at(1) << '\n';
  std::cout << vector_2d.at(1).at(0) << '\n';
  std::cout << vector_2d.at(1).at(1) << '\n';

  std::cout << "Vector1 after change:\n";
  std::cout << vector1.at(0) << '\n'; // NOTE: changed
  std::cout << vector1.at(1) << '\n';
  std::cout << "The size of vector1 is: " << vector1.size() << '\n';

  return 0;
}
