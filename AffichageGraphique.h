#ifndef AFFICHAGEGRAPHIQUE_H
#define AFFICHAGEGRAPHIQUE_H

#include "Affichage.h"
#include <SFML/Graphics.hpp>

class Grille;

class AffichageGraphique: public Affichage{
    private:
        int tailleCellule;
        sf::Color couleurVivant;
        sf::Color couleurMort;
        //sf::Color couleurImmortel;
        sf::RenderWindow* fenetre;
    public:
        AffichageGraphique(int taille);
        void render(Grille* grille) override;
        void clear() override;    
        void init() override;
        void close() override;
        bool handleInput() override;
        bool estOuvert() const;
        void onCellClick(int x, int y);
};

#endif