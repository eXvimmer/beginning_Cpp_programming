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
  Mystring &operator=(Mystring &&);      // move assignment
  // unary - operator, to turn Mystring to lwoer case (don't do this IRL)
  Mystring operator-() const;
  // binary + operator for concatination
  Mystring operator+(const Mystring &) const;
  // binary == for comparison
  bool operator==(const Mystring &) const;
  void display() const;
  int get_length() const;
  const char *get_str() const;

private:
  char *str; // pinter to a char[] that holds a C-style string
};

#endif
