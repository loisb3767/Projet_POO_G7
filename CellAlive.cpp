#include "CellAlive.h"
#include "CellDead.h"
#include "ConwayRules.h"


CellAlive::CellAlive(int x, int y, bool isObstacle) {
    this->x = x;
    this->y = y;
    this->isObstacle = isObstacle;
}

int CellAlive::getX() const {
    return x;
}
int CellAlive::getY() const {
    return y;
}

CellState* CellAlive::nextState(int nbVoisins, Rules* rules) {
    if(!this->isObstacle) {
        if(!rules->shouldSurvive(nbVoisins)) {
            return new CellDead(this->x, this->y, this->isObstacle);
        }
    }
    return clone();
}
CellState* CellAlive::clone() {
    return new CellAlive(this->x, this->y, this->isObstacle);
}
string CellAlive::getType() {
    return "CellAlive";
}