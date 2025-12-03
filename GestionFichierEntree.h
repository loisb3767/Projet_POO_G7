#ifndef GESTIONFICHIERENTREE_H
#define GESTIONFICHIERENTREE_H

#include <string>

class GestionFichierEntree {
private:
    std::string chemin; //prends un chemin pour le fichier d'entrée
public:
    GestionFichierEntree(const std::string& cheminFichier);

    std::string lireContenu() const; //méthode permettant de lire le contenu du fichier en entrée
    std::string getNomFichier() const; //méthode permettant de lire le nom du fichier en entrée
};

#endif
