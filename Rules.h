#ifndef RULES_H
#define RULES_H

#include <string>

using namespace std;


class Rules {
public:
    virtual ~Rules() = default;
    virtual bool shouldBeBorn(int nbVoisins) = 0;
    virtual bool shouldSurvive(int nbVoisins) = 0;
    virtual string getName() const = 0;
};

#endif