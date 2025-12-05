#ifndef RULES_H
#define RULES_H

#include <string>

using namespace std;

class Rules {
public:
    virtual ~Rules() = default;

    // Input: int (nombre de voisins) | Output: bool (true si la cellule doit naître)
    virtual bool shouldBeBorn(int nbVoisins) = 0;
    // Input: int (nombre de voisins) | Output: bool (true si la cellule doit survivre)
    virtual bool shouldSurvive(int nbVoisins) = 0;
    // Input: aucun | Output: string (nom des règles)
    virtual string getName() const = 0;
};

#endif
