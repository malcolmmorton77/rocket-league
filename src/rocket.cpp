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
    std::vector<Menu> player_list;
    std::string header;
    
    csv_reader.open(csv_name, std::ifstream::in); //open the file
    std::getline(csv_reader, line); //throw the header out
    header = line;
    if(csv_reader.is_open()){
        while(std::getline(csv_reader, line)){
            Menu a{};
            a.assignValues(line);
            player_list.push_back(a);
        }
    }

    csv_reader.close();

    for(std::vector<Menu>::iterator it = player_list.begin(); it != player_list.end()-1; it++)
    {
        if(it->getTeamId() == (std::next(it)->getTeamId()))
        {
            std::cout << it->getName() << " and " << std::next(it)->getName() << " are on the same team\n";
            
            // We would want to call calculate stolen goals between any two players if they are on the same team
        }
        // it->printMatchPoints();
        // it->printPoints();
    }

    return 0;
}