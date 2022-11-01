#include "Shallow.h"

Shallow::Shallow(int d) {
  data = new int;
  *data = d;
}

// NOTE: we need a deep copy rather than a shallow copy in this case.
Shallow::Shallow(const Shallow &source) : data{source.data} {}

Shallow::~Shallow() {
  delete data; // WARN: this will raise problems
}

void Shallow::set_data_value(int d) { *data = d; }

int Shallow::get_data_value() { return *data; }
