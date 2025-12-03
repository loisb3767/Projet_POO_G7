#include "ConwayRules.h"

bool ConwayRules::shouldBeBorn(int nbVoisins) {
    if (nbVoisins == 3) {
        return true;
    } return false;
}
bool ConwayRules::shouldSurvive(int nbVoisins) {
    if (nbVoisins == 2 || nbVoisins == 3) {
        return true;
    } return false;
}
string ConwayRules::getName() const {
    return "ConwayRules";
}
