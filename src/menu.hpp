#ifndef MENU_H
#define MENU_H

class Menu
{
private:
    std::string name{};
    int score{};
    int goals{};
    int assists{};
    int saves{};
    int shots{};

public:

    /* name: Menu
    * description: default constructor*/
    Menu(std::string="", int score=0, int goals=0, int assists=0, int saves=0, int shots=0);

    /* name: ~Menu
    * description: default destructor*/
    ~Menu();

    /* name: assignValues
    * description: assigns values using Boost libs to parse line
    * into a Menu object*/
    void assignValues(std::string);

    /* name: print
     * description: prints the values associated with the Player*/
    void print() const;

    /* list of getters
     * used to get particular data from the Menu objects*/
    std::string getName() const { return name; }
    int getScore() const { return score; }
    int getGoals() const { return goals; }
    int getAssists() const { return assists; }
    int getSaves() const { return saves; }
    int getShots() const { return shots; }
    
    /* name: hatTrickPoints
    * description: returns the amount of points earned from hat tricks
    * not including the actual goals themselves*/
    int hatTrickPoints() const;

};

#endif