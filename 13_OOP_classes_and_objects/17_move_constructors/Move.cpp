#include "Move.h"
#include <iostream>

// constructor
Move::Move(int d) {
  data = new int;
  *data = d;
  std::cout << "constructor for " << d << '\n';
}

// destructor
Move::~Move() {
  if (data == nullptr) {
    std::cout << "Destructor freeing data for nullptr\n";
  } else {
    std::cout << "Destructor freeing data for " << *data << '\n';
  }
  delete data;
}

// copy constructor
Move::Move(const Move &source) : Move{*source.data} {
  std::cout << "copy constructor, deep copying for:" << *data << std::endl;
}

// NOTE: Steal the data and then null out the source pointer; Kinda like Rust's
// ownership and borrowing.
Move::Move(Move &&source) noexcept : data{source.data} {
  source.data = nullptr;
  std::cout << "move constructor, moving resources for:" << *data << std::endl;
}
