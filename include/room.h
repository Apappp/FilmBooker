#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include <string>
#include <fstream>
#include "seat.h"

class Room {
private:
    int roomNumber;
    int rows;
    int columns;
    std::string movie;
    std::vector<std::vector<Seat>> seats;

public:
    Room(int roomNumber, int rows, int columns);

    void displaySeats() const;
    bool bookSeat(int row, int col);
    void saveToFile();
    void loadFromFile(); 
    void set_movie(std::string name);
};

#endif
