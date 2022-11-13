#include <iostream>

// NOTE: you can also use the 'class' keyword instead of 'typename'

// clang-format off
template <typename T>
T min(T a, T b) {
  // NOTE: in this case, generic objects should support operator<
  return (a < b) ? a : b;
}
// clang-format on

template <typename T, typename U> void print_args(T a, U b) {
  std::cout << a << ' ' << b << std::endl;
}

template <typename T> void swap_values(T &a, T &b) {
  auto temp = a;
  a = b;
  b = temp;
}

struct Person {
  std::string name;
  int age;
  // NOTE: you should overload the operator< if you want to use the generic min
  // function
  bool operator<(const Person &rhs) const {
    /* return age < right.age; */
    return this->age < rhs.age;
  }
};

std::ostream &operator<<(std::ostream &os, const Person &obj) {
  os << "Name: " << obj.name << ", age: " << obj.age << '\n';
  return os;
}

int main() {
  Person p1{"Mustafa", 30};
  Person p2{.name = "Malena", .age = 26};
  Person p3{min(p1, p2)};
  std::cout << min<int>(4, 9) << '\n';
  std::cout << min(2, 3) << '\n'; // type will be deduced (inferred?)
  std::cout << min('A', 'B') << '\n';
  std::cout << min(4.5, 9.2) << '\n';
  std::cout << min(5 + 2 * 2, 40 + 7) << '\n';
  std::cout << p3.name << " is younger." << std::endl;

  print_args<int, int>(10, 20);
  print_args(10, 20);
  print_args<char, double>('A', 73.3);
  print_args(1000, "Testing");
  print_args(2000, std::string{"Mustafa"});
  print_args(p1, p2);

  int x{100}, y{200};
  std::cout << "x: " << x << ", y: " << y << std::endl;
  swap_values(x, y);
  std::cout << "x: " << x << ", y: " << y << std::endl;

  std::cout << p1.name << " " << p2.name << std::endl;
  swap_values(p1, p2);
  std::cout << p1.name << " " << p2.name << std::endl;

  return 0;
}
