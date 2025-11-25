#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include <chrono>

class Movie {
  private:
  std::string name;
  std::string director; 
  std::string year; 
  std::string schedule; 
  std::string seats; 
  public:
  Movie(std::string name, std::string director, std::string year, std::string schedule, std::string seats);
  void short_info();
  void show_seats();
  std::string get_Name();
  std::string get_Date();

};

#endif // !MOVIE_H
