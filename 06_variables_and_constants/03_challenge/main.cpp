#include <iostream>

const double small_room_fee{25.0};
const double large_room_fee{35.0};
const double tax_rate{0.06};
const int valid_days{30};

int main() {
  int small_rooms_count{0}, large_rooms_count{0};

  std::cout << "How many large rooms would you like cleaned? ";
  std::cin >> large_rooms_count;

  std::cout << "How many small rooms would you like cleaned? ";
  std::cin >> small_rooms_count;

  std::cout << "Estimate for carpet cleaning service:\n";
  std::cout << "Number of small rooms: " << small_rooms_count << "\n";
  std::cout << "Number of large rooms: " << large_rooms_count << "\n";
  std::cout << "Price per small room: $" << small_room_fee << "\n";
  std::cout << "Price per large room: $" << large_room_fee << "\n";
  double cost =
      small_rooms_count * small_room_fee + large_rooms_count * large_room_fee;
  std::cout << "Cost: $" << cost << "\n";
  std::cout << "Tax: $" << cost * tax_rate << "\n";
  std::cout
      << "==============================================================\n";
  double total = cost * tax_rate + cost;
  std::cout << "Total estimate: $" << total << '\n';
  std::cout << "This estimate is valid for " << valid_days << " days."
            << std::endl;
  return 0;
}
