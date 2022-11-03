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
  friend Mystring operator-(const Mystring &); // to make Mystring lowercase
  friend Mystring operator+(const Mystring &, const Mystring &); // concat
  friend Mystring &operator+=(Mystring &, const Mystring &);
  friend Mystring operator*(const Mystring &, int);
  friend Mystring operator*=(Mystring &, int);
  friend Mystring &operator++(Mystring &);     // pre-increment
  friend Mystring operator++(Mystring &, int); // post-increment
  friend bool operator==(const Mystring &, const Mystring &);
  friend bool operator!=(const Mystring &, const Mystring &);
  friend bool operator<(const Mystring &, const Mystring &);
  friend bool operator>(const Mystring &, const Mystring &);
  void display() const;
  int get_length() const;
  const char *get_str() const;

private:
  char *str;
};

#endif
