#ifndef _ILLEGAL_BALANCE_EXCEPTION_H_
#define _ILLEGAL_BALANCE_EXCEPTION_H_

#include <exception>
#include <iostream>

class IllegalBalanceException : public std::exception {
public:
  IllegalBalanceException() noexcept = default;
  ~IllegalBalanceException() = default;
  virtual const char *what() const noexcept override {
    return "illegal balance exception";
  }
};

#endif // _ILLEGAL_BALANCE_EXCEPTION_H_
