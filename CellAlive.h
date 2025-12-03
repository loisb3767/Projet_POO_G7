#ifndef CELLALIVE_H
#define CELLALIVE_H

#include "CellState.h"

class CellAlive : public CellState {
protected:
    int x;
    int y;
    bool isObstacle;

public:
    CellAlive(int x, int y, bool isObstacle);
    int getX() const override;
    int getY() const override;
    string getType() override;
    CellState* nextState(int nbVoisins, Rules* rules) override;
    CellState* clone() override;
};














#endif