#ifndef MENU_H
#define MENU_H

class Menu
{
private:
    int score{};
    int goals{};
    int assists{};
    int saves{};
    int shots{};

public:
    Menu(int score=0, int goals=0, int assists=0, int saves=0, int shots=0);

    void print() const;

    int getScore() const { return score; }
    int getGoals() const { return goals; }
    int getAssists() const { return assists; }
    int getSaves() const { return saves; }
    int getShots() const { return shots; }
    
};

#endif