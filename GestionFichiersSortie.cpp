//afficher n itérations, pour chacunes 1 fichier état actuel grille
// 1 - écrire dans un fichier 
// 2 - changer le nom selon itération
// 3 - faire des classes de gestion de fichiers
// 3 - intégrer
#include "GestionFichiersSortie.h"
#include <fstream>

GestionFichiersSortie::GestionFichiersSortie(const std::string& dossier)
    : dossierSortie(dossier) {}

bool GestionFichiersSortie::creerFichier(const std::string& nomFichier, const std::string& contenu) const {
    std::ofstream fichier(dossierSortie + "/" + nomFichier);
    if (!fichier)
        return false;

    fichier << contenu;
    return true;
}


