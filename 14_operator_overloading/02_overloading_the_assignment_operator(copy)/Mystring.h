#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring {
public:
  Mystring();                            // no-args constructor
  Mystring(const char *s);               // overloaded constructor
  Mystring(const Mystring &);            // copy constructor
  Mystring(Mystring &&) noexcept;        // move constructor
  ~Mystring();                           // destructor
  Mystring &operator=(const Mystring &); // copy assignment
  void display() const;
  int get_length() const;
  const char *get_str() const;

private:
  char *str; // pinter to a char[] that holds a C-style string
};

#endif
