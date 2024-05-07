#include <iostream>
#include <sstream> //std::stringstream; std::stringbuf
#include <string> //std::string
#include <fstream> //ifstream
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
    
    csv_reader.open(csv_name, std::ifstream::in); //open the file
    std::getline(csv_reader, line); //throw the header out?
    if(csv_reader.is_open()){
        while(std::getline(csv_reader, line)){
            Menu a{};
            a.assignValues(line);
            std::cout << "Assigned values for " << line << std::endl;
        }
    }


    csv_reader.close();

    Menu a{}; // empty parentheses were disambiguated as a function declaration, use {}
    Menu m{"Eaurius", 773, 4, 2, 0, 7};
    a.print();
    m.print();
    return 0;
}