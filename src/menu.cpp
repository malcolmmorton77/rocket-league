#include <iostream>
#include <boost/algorithm/string.hpp>
#include <vector>
#include "menu.hpp"
#include <math.h>

Menu::Menu(std::string team_id, std::string name, int score, int goals, int assists, int saves, int shots){
    this->team_id = team_id;
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

    team_id = values[0];
    name = values[1];
    score = stoi(values[2]);
    goals = stoi(values[3]);
    assists = stoi(values[4]);
    saves = stoi(values[5]);
    shots = stoi(values[6]);
}

int Menu::goalPoints() const{
    return goals * 100;
}

int Menu::hatTrickPoints() const{
    return floor(goals/3) * 25;
}

int Menu::savePoints() const{
    return saves*50;
}

int Menu::saviorPoints() const{
    return floor(saves/3) * 25;
}

int Menu::assistPoints() const{
    return assists*50;
}

int Menu::playmakerPoints() const{
    return floor(assists/3) * 25;
}

int Menu::shotPoints() const{
    return shots * 10;
}

int Menu::miscPoints() const{
    return score - (goalPoints() + hatTrickPoints()+ savePoints() + saviorPoints() + assistPoints() + playmakerPoints() + shotPoints());
}

Menu::~Menu(){};

void Menu::print() const{
    std::cout << "Team: " << team_id << " Player: " << name << "\n";
    std::cout << "===============================================\n";
    std::cout << "Score: " << score << "\n"
                << "Goals: " << goals << "\n"
                << "Assists: " << assists << "\n"
                << "Saves: " << saves << "\n"
                << "Shots: " << shots << "\n\n";
};

void Menu::printPoints() const{
    std::cout << name << " finished the game with " << score << " pts." << std::endl;
    std::cout << "Points from Goals: " << goalPoints()  << " and Goals: " << goals << std::endl;
    std::cout << "Points from Hat Tricks: " << hatTrickPoints()  << " and Goals: " << goals << std::endl;
    std::cout << "Points from Saves: " << savePoints() << " and Saves: " << saves << std::endl;
    std::cout << "Points from Saviors: " << saviorPoints() << " and Saves: " << saves << std::endl;
    std::cout << "Points from Assists: " << assistPoints() << " and Assists: " << assists << std::endl;
    std::cout << "Points from Playmakers: " << playmakerPoints() << " and Assists: " << assists << std::endl;
    std::cout << "Points from Shots: " << shotPoints() << " and Shots: " << shots << std::endl;
    std::cout << "Points from ball touches, special goals, epic saves, clearing and centering: " << miscPoints() << "\n\n";
}

void Menu::printMatchPoints() const{
    if (goals != 0 && goals == saves)
        std::cout << name << " returned every save for a goal against.\n";
    else
        std::cout << name << " was not as zealous about vengeance.\n";
}

int Menu::calculateStolenGoals(Menu *player1, Menu *player2) const{
    // For both cases, check that there is a possibility of stolen goals
    // check that either player has a positive difference of goals - shots
    // then check if the other player has a positive difference of shots - goals
    // that could account for those missing shots
    if (player1->goals > player1->shots){
        if ( player2->shots - player2->goals >= player1->goals - player1->shots ) {
            return (player1->goals - player1->shots);
        }
    }
    else if (player2->goals > player2->shots){
        if ( player1->shots - player1->goals >= player2->goals - player2->shots ) {
            return (player2->goals - player2->shots);
        }
    }
    return -1;
}