#include <iostream>
#include <type_traits>
#include <vector>

// enum struct GroceryItem { Milk = 350, Bread = 250, Apple = 132, Orange = 100
// };
enum class GroceryItem { Milk = 350, Bread = 250, Apple = 132, Orange = 100 };

std::ostream &operator<<(std::ostream &os, GroceryItem gi) {
  std::underlying_type_t<GroceryItem> underlying_type =
      std::underlying_type_t<GroceryItem>(gi); // type cast
  switch (gi) {
  case GroceryItem::Apple:
    os << "Apple";
    break;
  case GroceryItem::Milk:
    os << "Milk";
    break;
  case GroceryItem::Bread:
    os << "Bread";
    break;
  case GroceryItem::Orange:
    os << "Orange";
    break;
  default:
    os << "Invalid item";
  }
  std::cout << " : " << underlying_type;
  return os;
}

bool is_valid_grocery_item(const GroceryItem &gi) {
  switch (gi) {
  case GroceryItem::Apple:
  case GroceryItem::Bread:
  case GroceryItem::Milk:
  case GroceryItem::Orange:
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

class Player {
public:
  enum class Mode { Attack, Defense, Idle };
  enum class Direction { North, South, East, West };

  Player(std::string name, Mode mode = Mode::Idle,
         Direction direction = Direction::North)
      : name{name}, mode{mode}, direction{direction} {}

  std::string get_name() const { return name; }
  void set_name(std::string name) { this->name = name; }

  Mode get_mode() const { return mode; }
  void set_mode(Mode mode) { this->mode = mode; }

  Direction get_direction() const { return direction; }
  void set_direction(Direction direction) { this->direction = direction; }

private:
  std::string name;
  Mode mode;
  Direction direction;
  friend std::ostream &operator<<(std::ostream &os, const Player &p);
};

std::string get_player_mode(Player::Mode mode) {
  std::string result;
  switch (mode) {
  case Player::Mode::Attack:
    result = "Attack";
    break;
  case Player::Mode::Defense:
    result = "Defense";
    break;
  case Player::Mode::Idle:
    result = "Idle";
    break;
  };
  return result;
}

std::string get_player_direction(Player::Direction direction) {
  std::string result;
  switch (direction) {
  case Player::Direction::North:
    result = "North";
    break;
  case Player::Direction::South:
    result = "South";
    break;
  case Player::Direction::East:
    result = "East";
    break;
  case Player::Direction::West:
    result = "West";
    break;
  };
  return result;
}

std::ostream &operator<<(std::ostream &os, const Player &p) {
  os << "Player name:      " << p.get_name() << "\n"
     << "Player mode:      " << get_player_mode(p.mode) << "\n"
     << "Player direction: " << get_player_direction(p.direction) << std::endl;
  return os;
}

void test1() {
  std::cout << "======================TEST1=======================\n";
  std::vector<GroceryItem> shopping_list;
  shopping_list.push_back(GroceryItem::Apple);
  shopping_list.push_back(GroceryItem::Milk);
  shopping_list.push_back(GroceryItem::Orange);
  int Helicopter{1000};
  /* shopping_list.push_back(Helicopter); // ERROR */
  shopping_list.push_back(GroceryItem(Helicopter)); // invalid item
  shopping_list.push_back(GroceryItem(350));        // Milk
  display_grocery_list(shopping_list);
}

void test2() {
  std::cout << "======================TEST2=======================\n";
  Player p1{"Cloud Strife", Player::Mode::Attack, Player::Direction::North};
  Player p2{"Tifa Lockhart", Player::Mode::Defense, Player::Direction::West};
  Player p3{"Sephiroth", Player::Mode::Idle, Player::Direction::South};
  std::cout << p1 << std::endl;
  std::cout << p2 << std::endl;
  std::cout << p3 << std::endl;
}

int main() {
  test1();
  test2();
  return 0;
}
