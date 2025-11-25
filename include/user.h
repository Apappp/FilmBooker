#ifndef USER_H
#define USER_H

#include <iostream>
#include <memory>
#include <string>
#include "menu.h"
#include "track.h"
#include "order.h"

class User{
    protected:
    std::string username;
    std::unique_ptr<Menu> main_menu;
    std::unique_ptr<Track> movie_track;
    virtual void load_menu() = 0;
    void track();
    public:
    User(std::string username);
    virtual ~User() = default;
    virtual void dash() = 0;    
};

#endif
