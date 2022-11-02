#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <string>

class Movie {
public:
  enum Rating { G, PG, PG13, R, X };
  Movie(std::string title, Rating rating_val, int watched_times);
  Movie(const Movie &);
  ~Movie();

  void set_name(std::string name);
  std::string get_name() const;
  void set_rating(Rating rating);
  std::string get_rating() const;
  void set_watched(int watched);
  int get_watched() const;
  void increment_watched();
  void display() const;

private:
  std::string name; // the name of the movie
  Rating rating;    // the movie rating G,PG, PG13, R
  int watched;      // the number of times you've watched the movie
};

#endif // _MOVIE_H_
