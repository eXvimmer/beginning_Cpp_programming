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

// friend function, binary == operator for equality
bool operator==(const Mystring &lhs, const Mystring &rhs) {
  return (std::strcmp(lhs.str, rhs.str) == 0);
}

// friend function, unary - operator to make Mystring lower case
Mystring operator-(const Mystring &obj) {
  char *buff{new char[std::strlen(obj.str) + 1]};
  std::strcpy(buff, obj.str);
  for (size_t i{0}; i < std::strlen(buff); ++i) {
    buff[i] = std::tolower(buff[i]);
  }
  Mystring temp{buff};
  delete[] buff;
  return temp;
}

// friend function, binary + operator for concatination
Mystring operator+(const Mystring &lhs, const Mystring &rhs) {
  char *buff{new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1]};
  std::strcpy(buff, lhs.str);
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
