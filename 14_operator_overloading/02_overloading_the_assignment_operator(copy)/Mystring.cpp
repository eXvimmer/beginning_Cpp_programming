#include "Mystring.h"
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

Mystring &Mystring::operator=(const Mystring &rhs) {
  if (this == &rhs) { // avoid self assignment. e.g. p1 = p1;
    return *this;
  }
  delete[] str; // remove the previous this->str from heap
  str = new char[std::strlen(rhs.str) + 1];
  std::strcpy(str, rhs.str);
  return *this;
}

void Mystring::display() const {
  std::cout << str << ": " << get_length() << std::endl;
}

int Mystring::get_length() const { return std::strlen(str); }

const char *Mystring::get_str() const { return str; }
