#ifndef NORMAL_USER_H
#define NORMAL_USER_H

#include <iostream>
#include <memory>
#include <string>
#include "user.h"
#include "menu.h"

class Normal_user : public User{
    protected:
    void load_menu() override;
    Order order;
    public:
    Normal_user(std::string username);
    void dash() override;
};

#endif
