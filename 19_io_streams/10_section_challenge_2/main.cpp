#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class CannotOpenTheFile : std::exception {
public:
  CannotOpenTheFile() = default;
  ~CannotOpenTheFile() = default;
  virtual const char *what() const noexcept override {
    return "cannot open the file";
  }
};

inline std::string trim(std::string &str) {
  str.erase(str.find_last_not_of(' ') + 1); // suffixing spaces
  str.erase(0, str.find_first_not_of(' ')); // prefixing spaces
  return str;
}

struct Student {
  std::string name;
  int grade;
};

void print_student(Student &s) {
  std::cout << std::setw(20) << std::left << s.name << std::setw(20)
            << std::right << s.grade << '\n';
}

void print_header() {
  std::cout << std::setw(20) << std::left << "Name" << std::setw(20)
            << std::right << "Grade" << std::endl;
  std::cout << std::setw(40) << std::setfill('=') << "" << std::endl;
  std::cout << std::setfill(' ');
}

void print_footer(int total_grades, std::vector<Student> &students) {
  std::cout << std::setw(40) << std::setfill('=') << "" << std::endl;
  std::cout << std::setfill(' ');
  std::cout << std::setw(20) << std::left << "Average" << std::setw(20)
            << std::right
            << (total_grades / static_cast<double>(students.size()))
            << std::endl;
}

std::unique_ptr<std::vector<Student>>
get_students_data_from_file(std::string filename, int &total_grades) {
  std::ifstream in_file;
  in_file.open(filename);
  if (!in_file) {
    throw CannotOpenTheFile();
  }
  std::string answer_key;
  /* std::getline(in_file, answer_key); */
  in_file >> answer_key;
  answer_key = trim(answer_key);

  std::string student_name;
  std::string student_answers;

  auto students = std::make_unique<std::vector<Student>>();
  while (in_file >> student_name >> student_answers) {
    /* Student student{student_name, 0}; */
    Student student{.name = trim(student_name), .grade = 0};
    student_answers = trim(student_answers);
    for (size_t i{0}; i < student_answers.length(); ++i) {
      if (student_answers.at(i) == answer_key.at(i)) {
        ++student.grade;
      }
    }
    total_grades += student.grade;
    students->push_back(student);
  }

  in_file.close();
  return students;
}

int main() {
  int total_grades{0};
  std::unique_ptr<std::vector<Student>> students;
  try {
    students = get_students_data_from_file("./responses.txt", total_grades);
  } catch (CannotOpenTheFile &ex) {
    std::cerr << ex.what() << std::endl;
    return 1;
  }
  print_header();
  for (Student s : *students) {
    print_student(s);
  }
  if (students->size() != 0) {
    print_footer(total_grades, *students);
  }
  return 0;
}
