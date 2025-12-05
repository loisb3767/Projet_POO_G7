#ifndef AFFICHAGEGRAPHIQUE_H
#define AFFICHAGEGRAPHIQUE_H

#include "Grid.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Grid;

class AffichageGraphique{
    private:
        int tailleCellule;
        sf::Color couleurVivant;
        sf::Color couleurMort;
        sf::RenderWindow* fenetre;
        Grid* grille;
    public:
        // Input: int (taille des cellules en pixels) | Output: aucun (constructeur)
        AffichageGraphique(int taille);

        // Input: Grid* (grille à afficher) | Output: aucun (void, définit la grille par défaut)
        void setGrid(Grid* grille);
        // Input: Grid* (grille à dessiner, optionnel) | Output: aucun (void, dessine la grille)
        void render(Grid* grille);
        // Input: aucun | Output: aucun (void, efface la fenêtre)
        void clear();
        // Input: aucun | Output: aucun (void, initialise la fenêtre SFML)
        void init();
        // Input: aucun | Output: aucun (void, ferme et détruit la fenêtre)
        void close();
        // Input: aucun | Output: bool (false si l'utilisateur ferme la fenêtre, true sinon)
        bool handleInput();
        // Input: aucun | Output: bool (true si la fenêtre est ouverte)
        bool estOuvert();
};

#endif