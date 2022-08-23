#include <iostream>

int main() {
  int test_scores[5]{1, 2, 3, 4, 5};
  test_scores[0] = 90;

  int high_scores_per_level[10]{3, 5}; // {3, 5, 0, 0, ...}
  const int DAYS_IN_YEAR{365};
  double high_temperature[DAYS_IN_YEAR]{0}; // init all to zero
  int another_array[]{1, 2, 3, 4, 5};       // size is calculated automatically

  char vowels[]{'a', 'e', 'i', 'o', 'u'};
  double high_temps[]{90.1, 89.8, 77.5, 81.6};
  high_temps[0] = 100.7;

  int scores[5]; // {junk, junk, junk, junk, junk}
  // it's better to initialize your arrays
  /* int better_scores[5]{}; // initializes to 0 */
  int better_scores[5]{100, 90};
  // initializes 1st element to 100, 2nd to 90 and the rest to 0.

  return 0;
}
