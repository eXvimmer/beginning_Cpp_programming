#include "Movie.h"
#include "Movies.h"
#include <cstdlib>
#include <iostream>

void increment_watched(Movies &movies, std::string name);
void add_movie(Movies &, std::string name, Movie::Rating rating, int watched);

int main() {
  Movies my_movies;
  my_movies.display();

  add_movie(my_movies, "Big", Movie::Rating::PG13, 2);
  add_movie(my_movies, "Star Wars", Movie::Rating::PG, 5);
  add_movie(my_movies, "Cinderella", Movie::Rating::PG, 7);
  my_movies.display(); // Big, Star Wars, Cinderella

  add_movie(my_movies, "Cinderella", Movie::Rating::PG, 7); // Already exists
  add_movie(my_movies, "Ice Age", Movie::Rating::PG, 12);   // OK
  my_movies.display(); // Big, Star Wars, Cinderella, Ice Age

  increment_watched(my_movies, "Big");     // OK
  increment_watched(my_movies, "Ice Age"); // OK
  my_movies.display(); // Big and Ice Age watched count incremented by 1

  increment_watched(my_movies, "XXX"); // XXX not found

  return EXIT_SUCCESS;
}

void increment_watched(Movies &movies, std::string name) {
  if (movies.increment_watched(name)) {
    std::cout << name << " watch incremented" << std::endl;
  } else {
    std::cout << name << " not found" << std::endl;
  }
}

void add_movie(Movies &movies, std::string name, Movie::Rating rating,
               int watched) {
  if (movies.add_movie(name, rating, watched)) {
    std::cout << name << " added" << std::endl;
  } else {
    std::cout << name << " already exists" << std::endl;
  }
}
