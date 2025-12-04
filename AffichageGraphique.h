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
        AffichageGraphique(int taille);
        void setGrid(Grid* grille);
        void render(Grid* grille);
        void clear();    
        void init();
        void close();
        bool handleInput();
        bool estOuvert();
};

#endif