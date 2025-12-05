#ifndef GRIDNORMAL_H
#define GRIDNORMAL_H

#include <vector>
#include "Grid.h"

using namespace std;

class GridNormal : public Grid {
protected:
    int const width;
    int const height;
    vector<vector<CellState*>> cells;

public:
    // Input: int (largeur), int (hauteur), vector<vector<CellState*>> (cellules) | Output: aucun (constructeur)
    GridNormal(int width, int height, const vector<vector<CellState*>> &cells);

    // Input: aucun | Output: int (largeur de la grille)
    int getWidth() const override;
    // Input: aucun | Output: int (hauteur de la grille)
    int getHeight() const override;
    // Input: int (x), int (y) | Output: CellState* (pointeur vers la cellule)
    CellState* getCellule(int x, int y) override;

    // Input: int (x), int (y), CellState* (nouvel état) | Output: aucun (void)
    void setCellule(int x, int y, CellState* state) override;

    // Input: int (x), int (y) | Output: int (nombre de voisins vivants)
    int countVoisinsAlive(int x, int y) override;
    // Input: int (x), int (y), Rules* (règles) | Output: aucun (void, met à jour la cellule)
    void updateCell(int x, int y, Rules* rules) override;
    // Input: aucun | Output: Grid* (clone de la grille normale)
    Grid* clone() override;
    // Input: aucun | Output: aucun (void, libère la mémoire)
    void clear() override;
};

#endif
