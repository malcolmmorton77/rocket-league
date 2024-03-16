#include <iostream>
#include <sstream> //std::stringstream; std::stringbuf
#include <string> // std::string
#include "menu.hpp"

int main(){
    // Here we need to read in a csv
    Menu a{}; // empty parentheses were disambiguated as a function declaration, use {}
    Menu m{773, 4, 2, 0, 7};
    a.print();
    m.print();
    return 0;
}