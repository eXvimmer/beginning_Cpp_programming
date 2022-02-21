#include <iostream>

using std::cin;
using std::cout;

int main() {
  cout << "Enter an amount in cents: ";
  long amount{0};
  cin >> amount;

  // In the US:
  // 1 dollar is 100 cents
  // 1 quarter is 25 cents
  // 1 dime is 10 cents
  // 1 nickel is 5 cents
  // 1 penny is 1 cent

  const long dollar_value{100};
  const long quarter_value{25};
  const long dime_value{10};
  const long nickel_value{5};

  int balance{}, dollars{}, quarters{}, dimes{}, nickels{}, pennies{};

  dollars = amount / dollar_value;
  /* balance = amount - (dollars * dollar_value); */
  // or
  balance = amount % dollar_value;

  quarters = balance / quarter_value;
  /* balance -= quarters * quarter_value; */
  // or
  balance %= quarter_value;

  dimes = balance / dime_value;
  /* balance -= dimes * dime_value; */
  // or
  balance %= dime_value;

  nickels = balance / nickel_value;
  /* balance -= nickels * nickel_value; */
  // or
  balance %= nickel_value;

  pennies = balance;

  cout << "\nYou can provide change for this change as follows:\n";
  cout << "dollars: " << dollars << '\n';
  cout << "quarters: " << quarters << '\n';
  cout << "dimes: " << dimes << '\n';
  cout << "nickels: " << nickels << '\n';
  cout << "pennies: " << pennies << '\n';

  return 0;
}
