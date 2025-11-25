#ifndef SEAT_H
#define SEAT_H

#include <iostream>
#include <string>

class Seat {
private:
    int row;
    int column;
    bool isAvailable;

public:
    Seat(int row, int column);
    bool getAvailability() const;
    void bookSeat();
    void displaySeat() const;
};

#endif