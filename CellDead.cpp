#include "CellDead.h"
#include "CellAlive.h"
#include "ConwayRules.h"

CellDead::CellDead(int x, int y, bool isObstacle) {
    this->x = x;
    this->y = y;
    this->isObstacle = isObstacle;
}

int CellDead::getX() const {
    return x;
}
int CellDead::getY() const {
    return y;
}

CellState* CellDead::nextState(int nbVoisins, Rules* rules) {
    if(!this->isObstacle) {
        if(rules->shouldBeBorn(nbVoisins)) {
            return new CellAlive(this->x, this->y, this->isObstacle);
        }
    }
    return clone();
}
CellState* CellDead::clone() {
    return new CellDead(this->x, this->y, this->isObstacle);
}
string CellDead::getType() {
    return "CellDead";

}
