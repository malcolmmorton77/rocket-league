#include <iostream>
#include <boost/algorithm/string.hpp>
#include "menu.hpp"

Menu::Menu(std::string name, int score, int goals, int assists, int saves, int shots){
    this->name = name;
    this->score = score;
    this->goals = goals;
    this->assists = assists;
    this->saves = saves;
    this->shots = shots; 
}

void Menu::assignValues(std::string line){
    // use boost library here
}

Menu::~Menu(){
    std::cout << "Class destroyed.\n";
};

void Menu::print() const{
    std::cout << "Score: " << score << "\n"
                << "Goals: " << goals << "\n"
                << "Assists: " << assists << "\n"
                << "Saves: " << saves << "\n"
                << "Shots: " << shots << "\n";
};