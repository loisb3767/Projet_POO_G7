#ifndef CELLDEAD_H
#define CELLDEAD_H

#include "CellState.h"


class CellDead : public CellState {
protected:
    int x;
    int y;
    bool isObstacle;

public:
    CellDead(int x, int y, bool isObstacle);
    int getX() const override;
    int getY() const override;
    string getType() override;
    CellState* nextState(int nbVoisins, Rules* rules) override;
    CellState* clone() override;
};














#endif