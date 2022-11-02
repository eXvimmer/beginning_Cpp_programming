#include "Movies.h"
#include <iostream>

bool Movies::add_movie(std::string name, Movie::Rating rating, int watched) {
  for (const Movie &m : movies) {
    if (m.get_name() == name) {
      return false;
    }
  }
  movies.push_back(Movie(name, rating, watched));
  return true;
}

bool Movies::increment_watched(std::string name) {
  for (Movie &m : movies) {
    if (m.get_name() == name) {
      m.increment_watched();
      return true;
    }
  }
  return false;
};

void Movies::display() const {
  if (movies.size() <= 0) {
    std::cout << "No movies to show\n";
    return;
  }
  std::cout << "\n============================================\n";
  for (const Movie &m : movies) {
    m.display();
  }
  std::cout << "============================================\n";
}
