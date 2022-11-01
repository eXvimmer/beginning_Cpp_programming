// NOTE: the this keyword is a pointer to the object and can only be used in
// class scope.

class Account {
public:
  void set_balance(double balance) { this->balance = balance; }
  bool compare_balance(const Account &other) { return this == &other; }

private:
  double balance;
};
