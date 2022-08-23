#include <iostream>

int main() {
  int room_width{0};
  std::cout << "Please enter the width of the room: ";
  std::cin >> room_width;

  int room_length{0};
  std::cout << "Please enter the length of the room: ";
  std::cin >> room_length;

  std::cout << "The area of the room is " << room_width * room_length
            << " square meters\n";

  return 0;
}
