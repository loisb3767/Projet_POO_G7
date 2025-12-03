#ifndef CONWAYRULES_H
#define CONWAYRULES_H

#include "Rules.h"

class ConwayRules : public Rules {
public:
    bool shouldBeBorn(int nbVoisins) override;
    bool shouldSurvive(int nbVoisins) override;
    string getName() const override;
};

#endif