#include "../include/user.h"

User::User(std::string username): username(username){
  movie_track = std::make_unique<Track>(1, 10, 5, username); 
}

void User::track(){
  movie_track->track_logic();    
}
