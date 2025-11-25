#include "../include/order.h"

Order::Order(const std::string& movieName, const std::string& userName, const std::string& date, 
             int row, int col)
    : movieName(movieName), userName(userName), date(date), row(row), col(col) {}

    Order::Order(const std::string& userName) : userName(userName){}


std::string Order::getMovieName() const {
    return movieName;
}

std::string Order::getUserName() const {
    return userName;
}

std::string Order::getDate() const {
    return date;
}

void Order::saveToUserFile() const {
    std::string filename = "../secret_data/orders/" + userName + ".txt"; 
    std::ofstream file(filename, std::ios::app); 
    if (!file) {
        std::cerr << "Unable to open file for saving: " << filename << std::endl;
        return;
    }

    file << "Movie: " << movieName << "\n";
    file << "Date: " << date << "\n";
    file << "Seat: ";
    file << "(" << row << ", " << col << ") ";
    file << "\n";
    file << "--------------------------\n"; 
    file.close();
}

void Order::loadOrdersByUser() {
    std::string filename = "../secret_data/orders/" + userName + ".txt"; 
    std::ifstream file(filename, std::ios::in);
    int t;
    std::cout << "\033[H\033[2J" << std::flush;
    std::cout << " ------ Your orders ------" << std::endl;
    if (!file) {
        std::cout << "You have no orders" << std::endl;
        std::cin >> t;
    }else{
    
    std::string line;

    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    std::cin >> t;
    }
    file.close();
}
