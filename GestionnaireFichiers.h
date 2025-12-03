#ifndef GESTIONNAIREFICHIERS_H
#define GESTIONNAIREFICHIERS_H

#include "GestionnaireFichiers.h"
#include "GestionFichiersSortie.h"
#include "GestionFichierEntree.h"

class GestionnaireFichiers {
public:
    bool traiter(const std::string& cheminEntree, const std::string& dossierSortie);
};

#endif
