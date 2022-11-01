#ifndef _MOVE_H_
#define _MOVE_H_

class Move {
public:
  Move(int);              // constructor
  ~Move();                // destructor
  Move(const Move &);     // copy constructor
  Move(Move &&) noexcept; // move constructor: moving is more efficient than
                          // copying
  void set_data_value(int);
  int get_data_value();

private:
  int *data;
};

#endif
