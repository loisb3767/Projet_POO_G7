#ifndef GRIDTORIC_H
#define GRIDTORIC_H

#include <vector>
#include "Grid.h"

using namespace std;

class GridToric : public Grid {
protected:
    int const width;
    int const height;
    vector<vector<CellState*>> cells;

public:
    GridToric(int width, int height, const vector<vector<CellState*>> &cells);
    int getWidth() const override;
    int getHeight() const override;

    CellState* getCellule(int x, int y) override;
    void setCellule(int x, int y, CellState* state) override;
    int countVoisinsAlive(int x, int y) override;
    void updateCell(int x, int y, Rules* rules) override;
    Grid* clone() override;
    void clear() override;
};

#endif