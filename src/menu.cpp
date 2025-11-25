#include "../include/menu.h"

Menu::Menu(std::string pathToPreset){
    try{
        InterpretFile file("menus/" + pathToPreset);
        items = file.simpleVector();
        title = items[0];
        items.erase(items.begin());
        n = items.size();
    }
    catch(const std::invalid_argument e){
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void Menu::showList(){
    std::cout << "\033[H\033[2J" << std::flush;
    std::cout << " ------ " << title << " ------\n" << std::endl;
    int i = 1;
    for (auto item : items){
        std::cout << " " << i << ") " << item << std::endl;
        i++;
    }
    if(errorMessage){
        std::cout << "\nOut of range element. Try again.";
    }
    std::cout << "\nChoose from the list:";

}

int Menu::choose() {
    int inputi = 0;
    errorMessage = false;

    while (true) {
        showList();
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

std::vector<std::string> Menu::getItems(){
    return items;
}
