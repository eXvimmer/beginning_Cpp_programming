#include "Deep.h"

Deep::Deep(int d) {
  data = new int;
  *data = d;
}

/* Deep::Deep(const Deep &source) { */
/*   data = new int; */
/*   *data = *source.data; */
/* } */

Deep::Deep(const Deep &source) : Deep{*source.data} {}

Deep::~Deep() { delete data; }

void Deep::set_data_value(int d) { *data = d; }

int Deep::get_data_value() { return *data; }
