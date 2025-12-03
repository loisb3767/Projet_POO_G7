#ifndef AFFICHAGEGRAPHIQUE_H
#define AFFICHAGEGRAPHIQUE_H

#include "Affichage.h"
#include "Grid.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Grid;

class AffichageGraphique: public Affichage{
    private:
        int tailleCellule;
        sf::Color couleurVivant;
        sf::Color couleurMort;
        sf::RenderWindow* fenetre;
        Grid* grille;
    public:
        AffichageGraphique(int taille);
        void setGrid(Grid* grille);
        void render(Grid* grille) override;
        void clear() override;    
        void init() override;
        void close() override;
        bool handleInput() override;
        bool estOuvert() override;
};

#endif