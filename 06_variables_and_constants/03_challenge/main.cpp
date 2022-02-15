#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const double small_room_fee{25.0};
const double large_room_fee{35.0};
const double tax_rate{0.06};
const int valid_days{30};

int main() {
  int small_rooms_count{0}, large_rooms_count{0};

  cout << "How many large rooms would you like cleaned? ";
  cin >> large_rooms_count;

  cout << "How many small rooms would you like cleaned? ";
  cin >> small_rooms_count;

  cout << "Estimate for carpet cleaning service:\n";
  cout << "Number of small rooms: " << small_rooms_count << "\n";
  cout << "Number of large rooms: " << large_rooms_count << "\n";
  cout << "Price per small room: $" << small_room_fee << "\n";
  cout << "Price per large room: $" << large_room_fee << "\n";
  double cost =
      small_rooms_count * small_room_fee + large_rooms_count * large_room_fee;
  cout << "Cost: $" << cost << "\n";
  cout << "Tax: $" << cost * tax_rate << "\n";
  cout << "==============================================================\n";
  double total = cost * tax_rate + cost;
  cout << "Total estimate: $" << total << '\n';
  cout << "This estimate is valid for " << valid_days << " days." << endl;
  return 0;
}
