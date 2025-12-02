#include "Grille.h"
#include <cstdlib>
#include <ctime>

Grille::Grille(int largeur, int hauteur)
    : largeur(largeur), hauteur(hauteur),
      cellules(largeur, std::vector<int>(hauteur)) {}

void Grille::initialiser() {
    std::srand(std::time(nullptr));
    for (int x = 0; x < largeur; ++x) {
        for (int y = 0; y < hauteur; ++y) {
            cellules[x][y] = std::rand() % 2;
        }
    }
}

int Grille::getCellule(int x, int y) const {
    return cellules[x][y];
}

int Grille::getLargeur() const { return largeur; }
int Grille::getHauteur() const { return hauteur; }
