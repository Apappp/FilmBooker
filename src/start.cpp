#include "../include/start.h"

void welcome(){
    std::unique_ptr<Menu> starting_menu = std::make_unique<Menu>("welcome");
    switch(starting_menu->choose()){
        case 1:
            login();
            welcome();
            break;
        case 2:
            reg();
            break;
        case 3:
            about();
            break;
        case 4:
            std::exit(0);
            break;
        default:
            std::cout << "ee" << std::endl;
    }
}

void login(){
    std::string username;
    std::string password;
    bool exists = false;
    bool err = false;
    int index {};
    InterpretFile accounts("secret_data/accounts");
    std::map<int, std::vector<std::string>> data = accounts.getRecords(3);
    while(!exists){
        std::cout << "\033[H\033[2J" << std::flush;
        std::cout << " ------ " << "login" << " ------\n" << std::endl;
        if(err){
            std::cout << " Wrong username, try again..." << std::endl;
        }
        err = true;
        std::cout << " Enter your login: ";
        std::cin >> username;
        for (auto record : data){
            if(record.second[0] == username){
                index = record.first;
                exists = true;
                err = false;
                break;
            }
        }
    }
    bool correct = false;
    while(!correct){
        std::cout << "\033[H\033[2J" << std::flush;
        std::cout << " ------ Log into " << username << " ------\n" << std::endl;
        if(err){
            std::cout << " Wrong password, Try again..." << std::endl;
        }
        err = true;
        std::cout << " Enter your password: ";
        disableEcho();
        std::cin >> password;
        restoreEcho();
        if(password==data.at(index)[1]){
            correct = true;
        }
    }
    if(data.at(index)[2] == "user"){
        std::unique_ptr<User> session = std::make_unique<Normal_user>(username);
    }
}

void reg(){
    std::string username;
    std::string password;
    bool exists = false;
    bool password_ok = true;
    InterpretFile accounts("secret_data/accounts");
    std::map<int, std::vector<std::string>> data = accounts.getRecords(3);
    do{
        std::cout << "\033[H\033[2J" << std::flush;
        std::cout << " ------ " << "register" << " ------\n" << std::endl;
        if(exists){
            std::cout << "Username already in use, try again..." << std::endl;
            exists = false;
        }
        std::cout << "Enter your login: ";
        std::cin >> username;
        for(auto record : data){
            if(username == record.second[0]){
                exists = true; 
                break;
            } 
        }
    }
    while(exists);
    do{
        std::cout << "\033[H\033[2J" << std::flush;
        std::cout << " ------ " << "register" << " ------\n" << std::endl;
        if(!password_ok){
            std::cout << "Password too short, try again..." << std::endl;
            password_ok = true;
        }
        std::cout << "Enter your new password:";
        disableEcho();
        std::cin >> password;
        restoreEcho();
        if(password.length() < 6){
            password_ok = false;
        }
        
    }
    while(!password_ok);
    if(accounts.insertRecords({username, password, "user"})){
        welcome();
    }
}

void about(){
    std::string t;
    std::cout << "\033[H\033[2J" << std::flush;
    std::cout << " ------ about ------" << std::endl;
    std::cin >> t;
    welcome();
}
