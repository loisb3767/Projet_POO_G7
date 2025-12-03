#ifndef GRID_H
#define GRID_H

#include "CellAlive.h"

class Grid {
public:
    virtual ~Grid() = default;
    virtual int getWidth() const = 0;
    virtual int getHeight() const = 0;
    virtual CellState* getCellule(int x, int y) = 0;
    virtual void setCellule(int x, int y, CellState* state) = 0;
    virtual int countVoisinsAlive(int x, int y) = 0;
    virtual void updateCell(int x, int y, Rules* rules) = 0;
    virtual Grid* clone() = 0;
    virtual void clear() = 0;
};

#endif