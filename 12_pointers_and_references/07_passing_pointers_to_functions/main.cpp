#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

void doubleIt(int *val);

void swap(int *a, int *b);

void display(vector<string> *vec);
void display(int *array, int sentinel);

int main() {
  int value{13};
  int *pVal{nullptr};

  cout << "Value is " << value << '\n';
  doubleIt(&value);
  cout << "Value is " << value << '\n';

  cout << "====================================\n";

  pVal = &value;
  doubleIt(pVal);
  cout << "Value is " << value << '\n';

  cout << "====================================\n";
  int x{100}, y{200};
  cout << "x is " << x << '\n';
  cout << "y is " << y << '\n';

  swap(&x, &y);

  cout << "x is " << x << '\n';
  cout << "y is " << y << '\n';

  cout << "====================================\n";
  vector<string> names{"Amadeus", "Rubuis", "Morbius", "Dovahkiin"};
  display(&names);

  cout << "====================================\n";
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

void display(vector<string> *vec) {
  for (string s : *vec)
    cout << s << ' ';

  cout << '\n';
}

void display(int *array, int sentinel) {
  while (*array != sentinel)
    cout << *array++ << ' ';
  cout << '\n';
}
