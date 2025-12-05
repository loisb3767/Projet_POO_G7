#ifndef GRID_H
#define GRID_H

#include "CellAlive.h"

class Grid {
public:
    virtual ~Grid() = default;

    // Input: aucun | Output: int (largeur de la grille)
    virtual int getWidth() const = 0;
    // Input: aucun | Output: int (hauteur de la grille)
    virtual int getHeight() const = 0;
    // Input: int (x), int (y) | Output: CellState* (pointeur vers la cellule)
    virtual CellState* getCellule(int x, int y) = 0;

    // Input: int (x), int (y), CellState* (nouvel état) | Output: aucun (void)
    virtual void setCellule(int x, int y, CellState* state) = 0;

    // Input: int (x), int (y) | Output: int (nombre de voisins vivants)
    virtual int countVoisinsAlive(int x, int y) = 0;
    // Input: int (x), int (y), Rules* (règles) | Output: aucun (void, met à jour la cellule)
    virtual void updateCell(int x, int y, Rules* rules) = 0;
    // Input: aucun | Output: Grid* (clone de la grille)
    virtual Grid* clone() = 0;
    // Input: aucun | Output: aucun (void, libère la mémoire)
    virtual void clear() = 0;
};

#endif
