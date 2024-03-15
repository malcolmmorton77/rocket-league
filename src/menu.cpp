#include <iostream>
#include "menu.hpp"

Menu::Menu(int score, int goals, int assists, int saves, int shots){
    this->score = score;
    this->goals = goals;
    this->assists = assists;
    this->saves = saves;
    this->shots = shots; 
};

void Menu::print() const{
    std::cout << "Score: " << score << "\n"
                << "Goals: " << goals << "\n"
                << "Assists: " << assists << "\n"
                << "Saves: " << saves << "\n"
                << "Shots: " << shots << "\n";
};