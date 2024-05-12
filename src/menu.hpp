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
    Menu(std::string="", int score=0, int goals=0, int assists=0, int saves=0, int shots=0);
    ~Menu();

    void assignValues(std::string);
    void print() const;

    std::string getName() const { return name; }
    int getScore() const { return score; }
    int getGoals() const { return goals; }
    int getAssists() const { return assists; }
    int getSaves() const { return saves; }
    int getShots() const { return shots; }
    
};

#endif