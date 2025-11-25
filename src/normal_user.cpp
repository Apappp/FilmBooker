#include "../include/normal_user.h"

Normal_user::Normal_user(std::string username) : Normal_user::User(username), order(username){
    load_menu();
    dash();
};

void Normal_user::load_menu(){
    main_menu = std::make_unique<Menu>("user_menu");
}

void Normal_user::dash(){
    switch(main_menu->choose()){
      case 1:
        track();
        dash();
        break;
      case 2:
        order.loadOrdersByUser();
        dash();
        break;
      case 3:
        std::exit(0);
        break;
      case 4:
        break;
      default:
        dash();
    }
}
