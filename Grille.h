#ifndef GRILLE_H
#define GRILLE_H

#include <vector>

class Grille {
private:
    int largeur;
    int hauteur;
    std::vector<std::vector<int>> cellules;

public:
    Grille(int largeur, int hauteur);

    void initialiser();
    int getCellule(int x, int y) const;
    int getLargeur() const;
    int getHauteur() const;
};

#endif
