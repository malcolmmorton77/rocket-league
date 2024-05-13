#include <iostream>
#include <sstream> //std::stringstream; std::stringbuf
#include <string> //std::string
#include <fstream> //ifstream
#include <vector>
#include "menu.hpp"

int main(int num_args, char *arg_string[]){
    //Grab csv name from arguments
    if(num_args != 2)
    {
        std::cout << "Error, not the correct number of arguments.\n";
        exit(1);
    }
    
    std::cout << "Processing csv " << arg_string[1] << "\n"
              << "If this is not correct, the program will terminate undesirably.\n";
    std::string csv_name = arg_string[1];
    std::ifstream csv_reader;
    std::string line;
    std::vector<Menu> player_list;
    std::string header;
    
    csv_reader.open(csv_name, std::ifstream::in); //open the file
    std::getline(csv_reader, line); //throw the header out
    header = line;
    if(csv_reader.is_open()){
        while(std::getline(csv_reader, line)){
            Menu a{};
            a.assignValues(line);

            std::cout << a.getName() << " finished the game with " << a.getScore() << " pts." << std::endl;
            std::cout << "Points from Goals: " << a.goalPoints()  << " and Goals: " << a.getGoals() << std::endl;
            std::cout << "Points from Hat Tricks: " << a.hatTrickPoints()  << " and Goals: " << a.getGoals() << std::endl;
            std::cout << "Points from Saves: " << a.savePoints() << " and Saves: " << a.getSaves() << std::endl;
            std::cout << "Points from Saviors: " << a.saviorPoints() << " and Saves: " << a.getSaves() << std::endl;
            std::cout << "Points from Assists: " << a.assistPoints() << " and Assists: " << a.getAssists() << std::endl;
            std::cout << "Points from Playmakers: " << a.playmakerPoints() << " and Assists: " << a.getAssists() << std::endl;
            std::cout << "Points from Shots: " << a.shotPoints() << " and Shots: " << a.getShots() << std::endl;
            std::cout << "Points from ball touches, special goals, epic saves, clearing and centering: " << a.miscPoints() << "\n\n";
            
            player_list.push_back(a);
        }
    }

    // for(std::vector<Menu>::iterator it = player_list.begin(); it < player_list.end(); it++)
    //     it->print();

    csv_reader.close();

    return 0;
}