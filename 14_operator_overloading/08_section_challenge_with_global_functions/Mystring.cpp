#include "Mystring.h"
#include <cstring>
#include <cwctype>

// no args constructor
Mystring::Mystring() : str{nullptr} {
  str = new char[1];
  *str = '\0';
}

// overloaded constructor
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

// move constructor
Mystring::Mystring(Mystring &&source) : str{source.str} {
  source.str = nullptr;
}

// destructor
Mystring::~Mystring() { delete[] str; }

// copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
  if (this == &rhs) {
    return *this;
  }
  delete[] str;
  str = new char[std::strlen(rhs.str) + 1];
  std::strcpy(str, rhs.str);
  return *this;
}

// move assignment
Mystring &Mystring::operator=(Mystring &&rhs) {
  if (this == &rhs) {
    return *this;
  }
  delete[] str;
  str = rhs.str;
  rhs.str = nullptr;
  return *this;
}

// return a lowercase Mystring
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

// concat to Mystring objects and return a new Mystring
Mystring operator+(const Mystring &lhs, const Mystring &rhs) {
  char *buff{new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1]};
  std::strcpy(buff, lhs.str);
  std::strcat(buff, rhs.str);
  Mystring temp{buff};
  delete[] buff;
  return temp;
}

Mystring &operator+=(Mystring &lhs, const Mystring &rhs) {
  lhs = lhs + rhs;
  return lhs;
}

// repeat a Mystring object n times
Mystring operator*(const Mystring &lhs, int n) {
  Mystring temp;
  for (int i{0}; i < n; ++i) {
    temp += lhs;
  }
  return temp;
}

Mystring operator*=(Mystring &lhs, int n) {
  lhs = lhs * n;
  return lhs;
}

// pre-increment for making a string uppercase
Mystring &operator++(Mystring &rhs) {
  for (size_t i{0}; i < std::strlen(rhs.str); ++i) {
    rhs.str[i] = std::toupper(rhs.str[i]);
  }
  return rhs;
}

// post-increment to make evaluate Mystring and make it uppercase
Mystring operator++(Mystring &lhs, int) {
  Mystring temp(lhs);
  ++lhs;
  return temp;
}

bool operator==(const Mystring &lhs, const Mystring &rhs) {
  return (std::strcmp(lhs.str, rhs.str) == 0);
}

bool operator!=(const Mystring &lhs, const Mystring &rhs) {
  return !operator==(lhs, rhs);
}

bool operator<(const Mystring &lhs, const Mystring &rhs) {
  return (std::strcmp(lhs.str, rhs.str) < 0);
}

bool operator>(const Mystring &lhs, const Mystring &rhs) {
  return (std::strcmp(lhs.str, rhs.str) > 0);
}

std::ostream &operator<<(std::ostream &os, const Mystring &obj) {
  os << obj.str;
  return os;
}

std::istream &operator>>(std::istream &is, Mystring &obj) {
  char *buff{new char[1000]};
  /* is >> buff; */
  is.get(buff, 1000); // TODO: check this, I'm not sure
  obj = Mystring{buff};
  delete[] buff;
  return is;
}

// NOTE: use the operator<< instead
void Mystring::display() const {
  std::cout << str << ": " << get_length() << std::endl;
}

int Mystring::get_length() const { return std::strlen(str); }

const char *Mystring::get_str() const { return str; }
