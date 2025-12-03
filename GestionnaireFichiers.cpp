#include "GestionnaireFichiers.h"
#include <iostream>

bool GestionnaireFichiers::traiter(const std::string& cheminEntree, const std::string& dossierSortie){
    GestionFichierEntree entree(cheminEntree);
    GestionFichiersSortie sortie(dossierSortie);

    std::string contenu = entree.lireContenu(); 
    if (contenu.empty()) {  //gérer le cas où l'utilisateur rend un fichier vide
        std::cerr << "Fichier vide, impossible de lire le contenu.\n";
        return false;
    }

    std::string nomFichierSortie = entree.getNomFichier();

    if (!sortie.creerFichier(nomFichierSortie, contenu)) { //gérer le cas où le fichier n'a pas pu être créé
        std::cerr << "Erreur création fichier sortie.\n";
        return false;
    }

    return true;
}
