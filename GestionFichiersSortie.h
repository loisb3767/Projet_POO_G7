#ifndef GESTIONFICHIERSSORTIE_H
#define GESTIONFICHIERSSORTIE_H

#include <string>

class GestionFichiersSortie {
    private:
        std::string dossierSortie;
    public:
        GestionFichiersSortie(const std::string& dossier);

        bool creerFichier(const std::string& nomFichier, const std::string& contenu) const;
};

#endif
