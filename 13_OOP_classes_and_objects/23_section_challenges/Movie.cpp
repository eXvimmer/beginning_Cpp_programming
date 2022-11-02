#include "Movie.h"
#include <iostream>

Movie::Movie(std::string title, Movie::Rating rating_val, int watched_times)
    : name{title}, rating{rating_val}, watched{watched_times} {}

Movie::Movie(const Movie &source)
    : Movie{source.name, source.rating, source.watched} {}

Movie::~Movie() {}

void Movie::set_name(std::string name) { this->name = name; }

std::string Movie::get_name() const { return name; }

std::string Movie::get_rating() const {
  switch (rating) {
  case G:
    return "G";
  case PG:
    return "PG";
  case PG13:
    return "PG-13";
  case R:
    return "R";
  case X:
    return "X";
  default:
    return "Rating unknown";
  }
}

void Movie::set_watched(int watched) { this->watched = watched; }

int Movie::get_watched() const { return watched; }

void Movie::increment_watched() { ++watched; };

void Movie::display() const {
  std::cout << name << ", " << get_rating() << ", " << watched << std::endl;
};
