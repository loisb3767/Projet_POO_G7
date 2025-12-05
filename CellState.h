#ifndef CELLSTATE_H
#define CELLSTATE_H

#include <string>
#include "Rules.h"

using namespace std;

class CellState {
public:
    virtual ~CellState() = default;

    // Input: aucun | Output: int (coordonnée X)
    virtual int getX() const = 0;
    // Input: aucun | Output: int (coordonnée Y)
    virtual int getY() const = 0;
    // Input: aucun | Output: string (type de cellule)
    virtual string getType() = 0;

    // Input: int (nombre de voisins vivants), Rules* (règles du jeu) | Output: CellState* (nouvel état)
    virtual CellState* nextState(int nbVoisins, Rules* rules) = 0;
    // Input: aucun | Output: CellState* (clone de la cellule)
    virtual CellState* clone() = 0;
};

#endif
