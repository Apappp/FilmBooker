#include "../include/track.h"

Track::Track(int roomNumber, int rows, int columns, std::string username) 
    : room(roomNumber, rows, columns), username(username) {
        load_movies();
        errorMessage = false;
    }

void Track::manageTrack(int ch) {
    std::cout << "\033[H\033[2J" << std::flush;
    std::cout << " ------ Choose your seat ------\n" << std::endl;
    room.displaySeats();
    int row, col, t;
    std::cout << "Enter which row: ";
    std::cin >> row;
    std::cout << "Enter which column: ";
    std::cin >> col;
    if (room.bookSeat(row-1, col-1)) {
        Order order1(movies[ch-1]->get_Name(), username, movies[ch-1]->get_Date(), row, col);
        order1.saveToUserFile();
        std::cout << "Seat booked successfully!\n";
    } else {
        std::cout << "Seat is unavailable or invalid.\n";
    }
    std::cin >> t;
}

void Track::saveRoomState(){
    room.saveToFile();
}

void Track::loadRoomState() {
    room.loadFromFile();
}

void Track::load_movies(){
  InterpretFile file("/secret_data/upcoming_movies");
  std::map<int, std::vector<std::string>> data = file.getRecords(5);
  for(auto record : data) {
    movies.push_back(std::make_unique<Movie>(record.second[0], record.second[1], record.second[2], record.second[3], record.second[4]));
  }
}

void Track::show_track(){
    std::cout << "\033[H\033[2J" << std::flush;

  n = 1;
  for (auto& movie : movies) {
    std::cout << n << ") ";
    movie->short_info();
    std::cout << std::endl;
    n++;
  } 
  std::cout << n << ") Return to menu" << std::endl;
  if(errorMessage){
      std::cout << "\nOut of range element. Try again.";
  }
  std::cout << "\nChoose from the list:";
}

int Track::choose(){
    int inputi = 0;
    errorMessage = false;

    while (true) {
        show_track();
        std::string input;
        std::cin >> input;

        try {
            inputi = std::stoi(input); 
            if (inputi <= 0 || inputi > n) { 
                errorMessage = true;
            } else {
                break; 
            }
        } catch (const std::invalid_argument& e) {
            errorMessage = true; 
        }

        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    }

    return inputi; 
}

void Track::track_logic(){
  int ch = choose();
  if(ch < n){
    room.set_movie(movies[ch-1]->get_Name());
    loadRoomState();
    manageTrack(ch);
    saveRoomState();
  }
}