#include <iomanip>
#include <iostream>
#include <string>

double calc_cost(double base_cost, double tax_rate = 0.06,
                 double shipping = 3.50);

void greeting(std::string name, std::string prefix = "Mr.",
              std::string suffix = "");

int main() {
  std::cout << std::fixed << std::setprecision(2);

  greeting("Mustafa Hayati", "Professor", "Ph.D.");
  greeting("Mustafa Hayati", "Dr.");
  greeting("Mustafa Hayati");

  double cost{0};

  cost = calc_cost(100, 0.08, 4.25);
  std::cout << "Cost is: " << cost << '\n';

  cost = calc_cost(100, 0.08);
  std::cout << "Cost is: " << cost << '\n';

  cost = calc_cost(200);
  std::cout << "Cost is: " << cost << '\n';

  return 0;
}

double calc_cost(double base_cost, double tax_rate, double shipping) {
  return base_cost += (base_cost * tax_rate) + shipping;
}

void greeting(std::string name, std::string prefix, std::string suffix) {
  std::cout << "Hello, " << prefix + ' ' + name + ' ' + suffix << "\n";
}
