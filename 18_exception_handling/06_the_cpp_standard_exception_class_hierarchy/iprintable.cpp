#include "iprintable.h"
#include <ostream>

std::ostream &operator<<(std::ostream &os, const IPrintable &obj) {
  obj.print(os);
  return os;
}
