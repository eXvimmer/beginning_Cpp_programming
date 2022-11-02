#include "Mystring.h"
#include <cctype>
#include <cstring>
#include <iostream>

// No-args constructor
Mystring::Mystring() : str{nullptr} {
  str = new char[1];
  *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) : str{nullptr} {
  if (s == nullptr) {
    str = new char[1];
    *str = '\0';
  } else {
    str = new char[std::strlen(s) + 1];
    std::strcpy(str, s);
  }
}

// copy constructor
Mystring::Mystring(const Mystring &source) : str{nullptr} {
  str = new char[std::strlen(source.str) + 1];
  std::strcpy(str, source.str);
}

// Move constructor
Mystring::Mystring(Mystring &&source) noexcept : str{source.str} {
  source.str = nullptr;
}

// destructor
Mystring::~Mystring() { delete[] str; }

// copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
  if (this == &rhs) { // avoid self assignment. e.g. p1 = p1;
    return *this;
  }
  delete[] str; // remove the previous this->str from heap
  str = new char[std::strlen(rhs.str) + 1];
  std::strcpy(str, rhs.str);
  return *this;
}

// move assignment
Mystring &Mystring::operator=(Mystring &&rhs) {
  if (this == &rhs) { // is this even possible?
    return *this;
  }
  delete[] str;
  str = rhs.str;     // steal the pointer
  rhs.str = nullptr; // null out the rhs object
  return *this;
}

// unary - operator to turn Mystring to lower case.
Mystring Mystring::operator-() const {
  char *buff{new char[std::strlen(str) + 1]};
  std::strcpy(buff, str);
  for (size_t i{0}; i < std::strlen(buff); ++i) {
    buff[i] = std::tolower(buff[i]);
  }
  Mystring temp{buff};
  delete[] buff;
  return temp;
}

// binary == operator for comparison; compares two string not the address of
// objects.
bool Mystring::operator==(const Mystring &rhs) const {
  return (std::strcmp(str, rhs.str) == 0);
}

// binary + operator for concatination
Mystring Mystring::operator+(const Mystring &rhs) const {
  char *buff{new char[std::strlen(/*this->*/ str) + std::strlen(rhs.str) + 1]};
  std::strcpy(buff, this->str);
  std::strcat(buff, rhs.str);
  Mystring temp{buff};
  delete[] buff;
  return temp;
}

void Mystring::display() const {
  std::cout << str << ": " << get_length() << std::endl;
}

int Mystring::get_length() const { return std::strlen(str); }

const char *Mystring::get_str() const { return str; }
