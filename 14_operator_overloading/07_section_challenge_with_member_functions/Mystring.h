#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <iostream>

class Mystring {
public:
  Mystring();                            // no-arg constructor
  Mystring(const char *);                // overloaded constructor
  Mystring(const Mystring &);            // copy constructor
  Mystring(Mystring &&);                 // move constructor
  ~Mystring();                           // destructor
  Mystring &operator=(const Mystring &); // copy assignment
  Mystring &operator=(Mystring &&);      // move assignment
  friend std::ostream &operator<<(std::ostream &, const Mystring &);
  friend std::istream &operator>>(std::istream &, Mystring &);
  Mystring operator-() const;                 // to make Mystring lowercase
  Mystring operator+(const Mystring &) const; // concat
  Mystring &operator+=(const Mystring &);
  Mystring operator*(int) const;
  Mystring operator*=(int);
  Mystring &operator++();   // pre-increment
  Mystring operator++(int); // post-increment
  bool operator==(const Mystring &) const;
  bool operator!=(const Mystring &) const;
  bool operator<(const Mystring &) const;
  bool operator>(const Mystring &) const;
  void display() const;
  int get_length() const;
  const char *get_str() const;

private:
  char *str;
};

#endif
