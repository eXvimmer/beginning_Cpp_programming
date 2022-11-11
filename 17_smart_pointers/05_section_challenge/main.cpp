#include <iostream>
#include <memory>
#include <vector>

class Test {
private:
  int data;

public:
  Test() : data{0} {
    std::cout << "Test constructor (" << data << ")" << std::endl;
  }
  Test(int data) : data{data} {
    std::cout << "Test constructor (" << data << ")" << std::endl;
  }
  int get_data() const { return data; }
  ~Test() { std::cout << "Test destructor (" << data << ")" << std::endl; }
};

// Function prototypes
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
void fill(std::vector<std::shared_ptr<Test>> &vec, int num);
void display(const std::vector<std::shared_ptr<Test>> &vec);

int main() {
  std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
  vec_ptr = make();
  std::cout << "How many data points do you want to enter: ";
  int num;
  std::cin >> num;
  fill(*vec_ptr, num);
  display(*vec_ptr);
  return 0;
}

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make() {
  return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void fill(std::vector<std::shared_ptr<Test>> &vec, int num) {
  int data;
  for (int i{0}; i < num; ++i) {
    std::cout << "\nEnter an integer [#" << i + 1 << "]: ";
    std::cin >> data;
    vec.push_back(std::make_shared<Test>(data));
  }
}

void display(const std::vector<std::shared_ptr<Test>> &vec) {
  std::cout << "\nDisplaying vector data" << std::endl;
  std::cout << "======================" << std::endl;
  for (const auto &t : vec) {
    std::cout << t->get_data() << '\n';
  }
  std::cout << "======================\n" << std::endl;
}
