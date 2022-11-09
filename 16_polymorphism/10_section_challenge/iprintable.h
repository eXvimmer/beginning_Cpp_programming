#ifndef _IPRINTABLE_H_
#define _IPRINTABLE_H_
#include <iostream>

class IPrintable {
public:
  virtual void print(std::ostream &os) const = 0;
  virtual ~IPrintable() = default;
  friend std::ostream &operator<<(std::ostream &os, const IPrintable &obj);
};

#endif // _I_PRINTABLE_H_
