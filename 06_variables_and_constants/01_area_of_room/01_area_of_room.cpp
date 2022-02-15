#include <iostream>

using std::cin;
using std::cout;

int main() {
  int room_width{0};
  cout << "Please enter the width of the room: ";
  cin >> room_width;

  int room_length{0};
  cout << "Please enter the length of the room: ";
  cin >> room_length;

  cout << "The area of the room is " << room_width * room_length
       << " square meters\n";

  return 0;
}
