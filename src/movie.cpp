#include "../include/movie.h"

Movie::Movie(std::string name, std::string director, std::string year, std::string schedule, std::string seats): name(name), director(director), year(year), schedule(schedule), seats(seats){};

void Movie::short_info(){
  std::cout << name << std::endl;
  std::cout << "Director: " << director << std::endl;
  std::cout << "Year: " << year << std::endl;
  std::cout << "When: " << schedule << std::endl;
}

std::string Movie::get_Name(){
  return name;
}

std::string Movie::get_Date(){
  return schedule;
}