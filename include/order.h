#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "seat.h"

class Order {
private:
    std::string movieName;
    std::string userName;
    std::string date;
    int row;
    int col;

public:
    Order(const std::string& movieName, const std::string& userName, const std::string& date, 
          int row, int col);
    Order(const std::string& userName);

    std::string getMovieName() const;
    std::string getUserName() const;
    std::string getDate() const;
    const std::vector<std::pair<int, int>>& getSeats() const;

    void saveToUserFile() const;
    void loadOrdersByUser(); 
};

#endif