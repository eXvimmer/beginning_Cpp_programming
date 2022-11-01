#ifndef _DEEP_H_
#define _DEEP_H_

class Deep {
public:
  Deep(int);
  Deep(const Deep &);
  ~Deep();
  void set_data_value(int);
  int get_data_value();

private:
  int *data;
};

#endif
