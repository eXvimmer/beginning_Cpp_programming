#include <iostream>
#include <string>
#include <vector>

// NOTE: template classes are typically completely contained in header files. So
// we would have the template class in item.h and no item.cpp would be  used.
template <typename T> class Item {
public:
  Item(std::string name, T value) : name{name}, value{value} {}
  ~Item() = default;
  std::string get_name() const { return name; }
  T get_value() const { return value; }

private:
  std::string name;
  T value;
};

template <typename T, typename U> struct MyPair {
  T first;
  U second;
};

int main() {
  Item<int> item1{"Mustafa", 100};
  std::cout << item1.get_name() << ' ' << item1.get_value() << std::endl;

  Item<std::string> item2{"Malena", "artist"};
  std::cout << item2.get_name() << ' ' << item2.get_value() << std::endl;

  Item<Item<std::string>> item3{"Sadie", {"C++", "Magician"}};
  std::cout << item3.get_name() << ' ' << item3.get_value().get_name() << ' '
            << item3.get_value().get_value() << std::endl;

  std::cout << "=====================================================\n";
  std::vector<Item<double>> vec{};
  vec.push_back(Item<double>{"Maya", 69.96});
  vec.push_back(Item<double>("Sydney", 87.89));
  vec.push_back(Item<double>("Emily", 47.13));

  for (const auto &item : vec) {
    std::cout << item.get_name() << ", " << item.get_value() << std::endl;
  }

  std::cout << "=====================================================\n";
  MyPair<std::string, int> p1{"Margot", 32};
  MyPair<double, int> p2{1399.09, 92};
  std::cout << p1.first << ", " << p1.second << std::endl;
  std::cout << p2.first << ", " << p2.second << std::endl;

  return 0;
}
