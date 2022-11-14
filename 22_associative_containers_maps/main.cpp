#include <iostream>
#include <map>
#include <set>
#include <string>

void display(const std::map<std::string, std::set<int>> &m) {
  std::cout << "[ ";
  for (const auto &map_el : m) {
    std::cout << map_el.first << ":[ ";
    for (const auto &set_el : map_el.second) {
      std::cout << set_el << " ";
    }
    std::cout << "] ";
  }
  std::cout << "]\n";
}

template <typename T, typename U> void display(const std::map<T, U> &m) {
  std::cout << "[ ";
  for (const auto &elem : m) {
    std::cout << elem.first << ":" << elem.second << " ";
  }
  std::cout << "]\n";
}

void test1() {
  std::cout << "======================TEST1=======================\n";
  // NOTE: Maps are ordered by key and duplicates are not allowed; If you want
  // duplicates or unordered maps use multimap, unordered_map or
  // unordered_multimap.
  std::map<std::string, int> m{{"Mustafa", 30}, {"Malena", 26}, {"Emily", 24}};
  display(m);

  m.insert(std::pair<std::string, int>("Sadie", 22));
  display(m);

  m.insert(std::make_pair("Maya", 24));
  display(m);

  m["Margot"] = 32;
  display(m);

  m["Mustafa"] -= 10;
  display(m);

  m.erase("Mustafa");
  display(m);

  std::cout << "Count for Emily: " << m.count("Emily") << '\n';
  std::cout << "Count for Mustafa: " << m.count("Mustafa") << '\n';

  auto it = m.find("Margot");
  if (it != m.end()) {
    std::cout << "Found: " << it->first << ":" << it->second << '\n';
  }

  m.clear();
  display(m);
}

void test2() {
  std::cout << "======================TEST2=======================\n";
  std::map<std::string, std::set<int>> grades{
      {"Mustafa", {100, 100, 99}}, {"Malena", {94}}, {"Emily", {100}}};
  // NOTE: duplicates grades will be removed, becase second is a set
  display(grades);
  grades["Malena"].insert(97);
  display(grades);

  auto it = grades.find("Emily");
  if (it != grades.end()) {
    it->second.insert(98);
  }
  display(grades);
}

int main() {
  test1();
  test2();

  return 0;
}
