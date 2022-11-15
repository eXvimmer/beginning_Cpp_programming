#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

// enum_key enum_name: enum_type {}

// unscoped enumeration
enum Direction { North, South, East, West };

// another unscoped enumeration
enum GroceryItem { Milk, Bread, Apple, Orange };

enum State { Engine_Failure, Inclement_Weather, Nominal, Unknown };
enum Sequence { Abort, Hold, Launch };

std::string direction_to_string(Direction dir) {
  switch (dir) {
  case North:
    return "North";
  case South:
    return "South";
  case East:
    return "East";
  case West:
    return "West";
  default:
    return "Unknown direction";
  }
}

std::ostream &operator<<(std::ostream &os, const GroceryItem &gi) {
  switch (gi) {
  case Bread:
    os << "Bread";
    break;
  case Milk:
    os << "Milk";
    break;
  case Apple:
    os << "Apple";
    break;
  case Orange:
    os << "Orange";
    break;
  default:
    os << "Invalid Item";
  }
  return os;
}

std::istream &operator>>(std::istream &is, State &state) {
  std::underlying_type_t<State> user_input;
  /* int user_input; */
  is >> user_input;
  switch (user_input) {
  case Engine_Failure:
  case Inclement_Weather:
  case Nominal:
  case Unknown:
    state = State(user_input);
    break;
  default:
    std::cout << "User input is not a valid launch state.\n";
    state = Unknown;
  }
  return is;
}

std::ostream &operator<<(std::ostream &os, const Sequence &seq) {
  switch (seq) {
  case Abort:
    os << "Abort";
    break;
  case Hold:
    os << "Hold";
    break;
  case Launch:
    os << "Launch";
    break;
  }
  return os;
}

void initiate(Sequence seq) {
  std::cout << "Initiate " << seq << " sequence.\n";
}

bool is_valid_grocery_item(GroceryItem gi) {
  switch (gi) {
  case Orange:
  case Apple:
  case Bread:
  case Milk:
    return true;
  default:
    return false;
  }
}

void display_grocery_list(const std::vector<GroceryItem> &gv) {
  int invalid_item_count{0}, valid_item_count{0};
  for (const GroceryItem &item : gv) {
    std::cout << item << '\n';
    if (is_valid_grocery_item(item)) {
      ++valid_item_count;
    } else {
      ++invalid_item_count;
    }
  }
  std::cout << "==================================================\n";
  std::cout << "Valid items: " << valid_item_count << '\n';
  std::cout << "Invalid items: " << invalid_item_count << '\n';
  std::cout << "Total items: " << valid_item_count + invalid_item_count << '\n';
}

void test1() {
  std::cout << "======================TEST1=======================\n";
  Direction direction{North};
  std::cout << "Direction: " << direction << '\n';
  std::cout << "Direction: " << direction_to_string(direction) << '\n';

  direction = West;
  std::cout << "Direction: " << direction << '\n';
  std::cout << "Direction: " << direction_to_string(direction) << '\n';

  // WARN: be careful casting, since the compiler will assume you know what you
  // are doing
  direction = Direction(100);
  std::cout << "Direction: " << direction << '\n';
  std::cout << "Direction: " << direction_to_string(direction) << '\n';

  direction = static_cast<Direction>(100);
  std::cout << "Direction: " << direction << '\n';
  std::cout << "Direction: " << direction_to_string(direction) << '\n';
}

void test2() {
  std::cout << "======================TEST2=======================\n";
  std::vector<GroceryItem> shopping_list;
  shopping_list.push_back(Apple);
  shopping_list.push_back(Apple);
  shopping_list.push_back(Milk);
  shopping_list.push_back(Orange);
  int Helicopter{1000};
  shopping_list.push_back(GroceryItem(Helicopter)); // invalid item
  shopping_list.push_back(GroceryItem(0));          // Milk
  display_grocery_list(shopping_list);
}

void test3() {
  std::cout << "======================TEST3=======================\n";
  State state;
  std::cout << "Launch state: ";
  std::cin >> state; // overloaded operator>>
  switch (state) {
  case Engine_Failure:
  case Unknown:
    initiate(Abort);
    break;
  case Inclement_Weather:
    initiate(Hold);
    break;
  case Nominal:
    initiate(Launch);
    break;
  }
}

int main() {
  test1();
  test2();
  test3();
  return 0;
}
