#include "GestionnaireFichiers.h"
#include <iostream>

int main() {
    std::string chemin;
    std::cout << "Chemin du fichier .txt : ";
    std::getline(std::cin, chemin);

    GestionnaireFichiers manager;

    if (manager.traiter(chemin, "./sortie")) {
        std::cout << "Fichier créé avec succès.\n";
    }

    return 0;
}
