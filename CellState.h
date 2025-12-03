#ifndef CELLSTATE_H
#define CELLSTATE_H

#include <iostream>
#include "Rules.h"

using namespace std;


class CellState {
public:
    virtual ~CellState() = default;
    virtual int getX() const = 0;
    virtual int getY() const = 0;
    virtual string getType() = 0;
    virtual CellState* nextState(int nbVoisins, Rules* rules) = 0;
    virtual CellState* clone() = 0;
};

#endif