#ifndef _SHALLOW_H_
#define _SHALLOW_H_

class Shallow {
public:
  Shallow(int);             // constructor
  Shallow(const Shallow &); // copy constructor
  ~Shallow();               // destructor
  void set_data_value(int);
  int get_data_value();

private:
  int *data; // NOTE: raw paointer
};

#endif
