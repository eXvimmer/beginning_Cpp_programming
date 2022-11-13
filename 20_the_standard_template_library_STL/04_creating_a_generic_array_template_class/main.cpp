#include <exception>
#include <iostream>
#include <string>

class OutOfRange : public std::exception {
public:
  virtual const char *what() const noexcept override {
    return "Index out of range";
  }
};

// NOTE: if you need an array use std::array
template <typename T, unsigned long N> class Array {
public:
  Array() = default;

  Array(T init_val) {
    for (auto &item : values) {
      item = init_val;
    }
  }

  void fill(T val) {
    for (auto &item : values) {
      item = val;
    }
  }

  int get_size() const { return size; }

  T &operator[](int index) {
    if (index >= size) {
      throw OutOfRange();
    }
    return values[index];
  }

private:
  int size{N};
  T values[N];

  friend std::ostream &operator<<(std::ostream &os, const Array<T, N> &arr) {
    os << '[';
    for (const auto &val : arr.values) {
      os << val << ' ';
    }
    os << ']' << std::endl;
    return os;
  }
};

int main() {
  Array<int, 5> nums;
  std::cout << "The size of nums is: " << nums.get_size() << std::endl;
  std::cout << nums << std::endl;

  nums.fill(0);
  std::cout << "The size of nums is: " << nums.get_size() << std::endl;
  std::cout << nums << std::endl;

  nums.fill(10);
  std::cout << nums << std::endl;

  nums[0] = 1000;
  nums[3] = 2000;
  std::cout << nums << std::endl;

  Array<int, 100> nums2{13};
  std::cout << "The size of nums2 is: " << nums2.get_size() << std::endl;
  std::cout << nums2 << std::endl;

  Array<std::string, 12> months;
  try {
    months[0] = "January";
    months[1] = "February";
    months[2] = "March";
    months[3] = "April";
    months[4] = "May";
    months[5] = "June";
    months[6] = "July";
    months[7] = "August";
    months[8] = "September";
    months[9] = "October";
    months[10] = "November";
    months[11] = "December";
    months[12] = "Mehr";
  } catch (OutOfRange &ex) {
    std::cerr << ex.what() << std::endl;
  }

  std::cout << "Size of months: " << months.get_size() << std::endl;
  std::cout << months << std::endl;

  Array<std::string, 10> strings("Mustafa");
  std::cout << "Size of strings: " << strings.get_size() << std::endl;
  std::cout << strings << std::endl;

  strings[0] = "Malena";
  std::cout << strings << std::endl;

  strings.fill(std::string{"X"});
  std::cout << strings << std::endl;

  return 0;
}
