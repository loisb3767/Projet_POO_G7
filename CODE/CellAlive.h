#ifndef CELLALIVE_H
#define CELLALIVE_H

#include "CellState.h"

class CellAlive : public CellState {
protected:
    int x;
    int y;
    bool isObstacle;

public:
    // Input: int (x), int (y), bool (isObstacle) | Output: aucun (constructeur)
    CellAlive(int x, int y, bool isObstacle);

    // Input: aucun | Output: int (coordonnée X)
    int getX() const override;
    // Input: aucun | Output: int (coordonnée Y)
    int getY() const override;
    // Input: aucun | Output: string (type "CellAlive")
    string getType() override;

    // Input: int (nombre de voisins vivants), Rules* (règles du jeu) | Output: CellState* (nouvel état)
    CellState* nextState(int nbVoisins, Rules* rules) override;
    // Input: aucun | Output: CellState* (clone de la cellule vivante)
    CellState* clone() override;
};

#endif
