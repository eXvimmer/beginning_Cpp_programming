#include <iomanip>
#include <iostream>
#include <string>

using std::cout;
using std::string;

double calc_cost(double base_cost, double tax_rate = 0.06,
                 double shipping = 3.50);

void greeting(string name, string prefix = "Mr.", string suffix = "");

int main() {
  cout << std::fixed << std::setprecision(2);

  greeting("Mustafa Hayati", "Professor", "Ph.D.");
  greeting("Mustafa Hayati", "Dr.");
  greeting("Mustafa Hayati");

  double cost{0};

  cost = calc_cost(100, 0.08, 4.25);
  cout << "Cost is: " << cost << '\n';

  cost = calc_cost(100, 0.08);
  cout << "Cost is: " << cost << '\n';

  cost = calc_cost(200);
  cout << "Cost is: " << cost << '\n';

  return 0;
}

double calc_cost(double base_cost, double tax_rate, double shipping) {
  return base_cost += (base_cost * tax_rate) + shipping;
}

void greeting(string name, string prefix, string suffix) {
  cout << "Hello, " << prefix + ' ' + name + ' ' + suffix << "\n";
}
