#include <fstream> //ifstream
#include <iostream>
#include <sstream> //std::stringstream; std::stringbuf
#include <string> //std::string
#include <vector>
#include "menu.hpp"

int main(int num_args, char *arg_string[]){
    //Grab csv name from arguments
    if(num_args != 2)
    {
        std::cout << "Error, not the correct number of arguments.\n"
                  << "Usage: ./executable /path/to/data.csv\n";
        exit(1);
    }
    
    std::cout << "Processing csv " << arg_string[1] << "\n"
              << "If the syntax inside the csv is not correct, the program will terminate undesirably.\n";
    std::string csv_name = arg_string[1];
    std::ifstream csv_reader;
    std::string line;
    std::vector<Menu*> player_list;
    std::string header;
    
    csv_reader.open(csv_name, std::ifstream::in); //open the file
    std::getline(csv_reader, line); //throw the header out
    header = line;
    if(csv_reader.is_open()){
        while(std::getline(csv_reader, line)){
            Menu* a = new Menu;
            a->assignValues(line);
            player_list.push_back(a);
        }
    }

    csv_reader.close();

    for(int i = 0; i <= player_list.size()-2; i++)
    {
        if(player_list[i]->getTeamId() == player_list[i+1]->getTeamId())
        {
            std::cout << player_list[i]->getName() << " and " << player_list[i+1]->getName() << " are on the same team\n";
            
            // We would want to call calculate stolen goals between any two players if they are on the same team
            int difference = player_list[i]->calculateStolenGoals( player_list[i], player_list[i+1]);
            if (difference > 0 )
                std::cout << player_list[i]->getName() << " and " << player_list[i+1]->getName() << " had a mismatch of " << difference << " in goals.\n";
        }
        player_list[i]->print();
        // player_list[i]->printMatchPoints();
        // player_list[i]->printPoints();
    }

    return 0;
}