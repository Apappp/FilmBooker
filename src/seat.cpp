#include "../include/seat.h"

Seat::Seat(int row, int column) : row(row), column(column), isAvailable(true) {}

bool Seat::getAvailability() const { return isAvailable; }
void Seat::bookSeat() { isAvailable = false; }
void Seat::displaySeat() const {
    std::cout << (isAvailable ? "[ ]" : "[X]");
}