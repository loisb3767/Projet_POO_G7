#ifndef CONWAYRULES_H
#define CONWAYRULES_H

#include "Rules.h"

class ConwayRules : public Rules {
public:
    // Input: int (nombre de voisins) | Output: bool (true si la cellule doit naître)
    bool shouldBeBorn(int nbVoisins) override;
    // Input: int (nombre de voisins) | Output: bool (true si la cellule doit survivre)
    bool shouldSurvive(int nbVoisins) override;
    // Input: aucun | Output: string (nom "ConwayRules")
    string getName() const override;
};

#endif
