#ifndef TRACK_H
#define TRACK_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <map>
#include "movie.h"
#include "interpretFile.h"
#include "room.h"
#include "order.h"

class Track {
private:
    bool errorMessage;
    int n;
    std::string username;
    std::vector<std::unique_ptr<Movie>> movies;
    Room room;
    void load_movies();
public:
    Track(int roomNumber, int rows, int columns, std::string username);

    void loadMovies();
    void manageTrack(int ch);
    void saveRoomState();
    void loadRoomState();
    void show_track();
    int choose();
    void track_logic();
};

#endif
