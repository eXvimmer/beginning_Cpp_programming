#ifndef _MOVIES_H_
#define _MOVIES_H_
#include "Movie.h"
#include <string>
#include <vector>

class Movies {
public:
  bool add_movie(std::string name, Movie::Rating rating, int watched);
  bool increment_watched(std::string name);
  void display() const;

private:
  std::vector<Movie> movies;
};

#endif // _MOVIES_H_
