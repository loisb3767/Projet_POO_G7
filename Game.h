#ifndef GAME_H
#define GAME_H

#include "Grid.h"
#include "Rules.h"


class Game {
private:
    Grid* currentGrid;
    Grid* nextGrid;
    Rules* rules;
    int generation;

public:
    Game(Grid* grid, Rules* rules);
    ~Game();
    
    void nextGeneration();
    void run(int iterations);
    
    Grid* getGrid() const;
    Rules* getRules() const;
    int getGeneration() const;
    
    void reset(Grid* newGrid);
    void setRules(Rules* newRules);
};

#endif