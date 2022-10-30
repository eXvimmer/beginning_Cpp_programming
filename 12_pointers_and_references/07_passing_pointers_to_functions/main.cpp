#include <iostream>
#include <string>
#include <vector>

void doubleIt(int *val);

void swap(int *a, int *b);

void display(std::vector<std::string> *vec);
void display(int *array, int sentinel);

int main() {
  int value{13};
  int *pVal{nullptr};

  std::cout << "Value is " << value << '\n';
  doubleIt(&value);
  std::cout << "Value is " << value << '\n';

  std::cout << "====================================\n";

  pVal = &value;
  doubleIt(pVal);
  std::cout << "Value is " << value << '\n';

  std::cout << "====================================\n";
  int x{100}, y{200};
  std::cout << "x is " << x << '\n';
  std::cout << "y is " << y << '\n';

  swap(&x, &y);

  std::cout << "x is " << x << '\n';
  std::cout << "y is " << y << '\n';

  std::cout << "====================================\n";
  std::vector<std::string> names{"Amadeus", "Rubuis", "Morbius", "Dovahkiin"};
  display(&names);

  std::cout << "====================================\n";
  int scores[]{100, 99, 98, -1};
  display(scores, -1);

  return 0;
}

void doubleIt(int *val) {
  *val *= 2; // *val = *val * 2
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void display(std::vector<std::string> *vec) {
  for (std::string s : *vec)
    std::cout << s << ' ';

  std::cout << '\n';
}

/* void display(int array[], int sentinel) { */
void display(int *array, int sentinel) {
  while (*array != sentinel)
    std::cout << *array++ << ' ';
  std::cout << '\n';
}
