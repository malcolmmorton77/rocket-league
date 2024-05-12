#include <iostream>
#include <boost/algorithm/string.hpp>
#include <vector>
#include "menu.hpp"
#include <math.h>

Menu::Menu(std::string name, int score, int goals, int assists, int saves, int shots){
    this->name = name;
    this->score = score;
    this->goals = goals;
    this->assists = assists;
    this->saves = saves;
    this->shots = shots;
}

void Menu::assignValues(std::string line){
    std::vector<std::string> values;
    boost::split(values, line, boost::is_any_of(","));

    name = values[0];
    score = stoi(values[1]);
    goals = stoi(values[2]);
    assists = stoi(values[3]);
    saves = stoi(values[4]);
    shots = stoi(values[5]);
}

int Menu::hatTrickPoints() const{
    return floor(goals/3) * 25;
}

Menu::~Menu(){};

void Menu::print() const{
    std::cout << "Player: " << name << "\n";
    std::cout << "========================\n";
    std::cout << "Score: " << score << "\n"
                << "Goals: " << goals << "\n"
                << "Assists: " << assists << "\n"
                << "Saves: " << saves << "\n"
                << "Shots: " << shots << "\n\n";
};