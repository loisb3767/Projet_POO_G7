#ifndef CELLDEAD_H
#define CELLDEAD_H

#include "CellState.h"

class CellDead : public CellState {
protected:
    int x;
    int y;
    bool isObstacle;

public:
    // Input: int (x), int (y), bool (isObstacle) | Output: aucun (constructeur)
    CellDead(int x, int y, bool isObstacle);

    // Input: aucun | Output: int (coordonnée X)
    int getX() const override;
    // Input: aucun | Output: int (coordonnée Y)
    int getY() const override;
    // Input: aucun | Output: string (type "CellDead")
    string getType() override;

    // Input: int (nombre de voisins vivants), Rules* (règles du jeu) | Output: CellState* (nouvel état)
    CellState* nextState(int nbVoisins, Rules* rules) override;
    // Input: aucun | Output: CellState* (clone de la cellule morte)
    CellState* clone() override;
};

#endif
