#include "../include/room.h"
#include <iostream>
#include <fstream>

Room::Room(int roomNumber, int rows, int columns) 
    : roomNumber(roomNumber), rows(rows), columns(columns){
    for (int i = 0; i < rows; ++i) {
        std::vector<Seat> rowSeats;
        for (int j = 0; j < columns; ++j) {
            rowSeats.push_back(Seat(i, j));
        }
        seats.push_back(rowSeats);
    }
}

void Room::displaySeats() const {
    for (const auto& row : seats) {
        for (const auto& seat : row) {
            seat.displaySeat();
        }
        std::cout << std::endl;
    }
}

bool Room::bookSeat(int row, int col) {
    if (row >= rows || col >= columns || !seats[row][col].getAvailability()) {
        return false;
    }
    seats[row][col].bookSeat();
    return true;
}

void Room::saveToFile() {
    std::ofstream file("../secret_data/movies/" + movie, std::ios::out);
    if (!file) {
        std::cerr << "Unable to open file for saving: " << movie << std::endl;
        return;
    }

    file << roomNumber << " " << rows << " " << columns << "\n";
    for (const auto& row : seats) {
        for (const auto& seat : row) {
            file << seat.getAvailability() << " ";
        }
        file << "\n";
    }
    file.close();
}

void Room::loadFromFile() {
    std::ifstream file("../secret_data/movies/" + movie, std::ios::in);
    if (!file) {
        saveToFile();
    }
    else{

    file >> roomNumber >> rows >> columns;

    seats.clear();
    for (int i = 0; i < rows; ++i) {
        std::vector<Seat> rowSeats;
        for (int j = 0; j < columns; ++j) {
            bool isAvailable;
            file >> isAvailable;
            Seat seat(i, j);
            if (!isAvailable) {
                seat.bookSeat();
            }
            rowSeats.push_back(seat);
        }
        seats.push_back(rowSeats);
    }}
    file.close();

}

void Room::set_movie(std::string name){
    movie = name;
    for (int i = 0; i < rows; ++i) {
    std::vector<Seat> rowSeats;
    for (int j = 0; j < columns; ++j) {
        rowSeats.push_back(Seat(i, j));
    }
    seats.clear();
    seats.push_back(rowSeats);
    }
}
