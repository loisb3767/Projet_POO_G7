#ifndef AFFICHAGECONSOLE_H
#define AFFICHAGECONSOLE_H

#include "Affichage.h"

class Grille;

class AffichageConsole: public Affichage{
    private:
        char symboleVivant;
        char symboleMort;
        char symboleImmortel;
    public:
        AffichageConsole(char vivant, char mort, char immortel){}
        void render(Grille* grille) override;
        void clear() override;    
        void init() override;
        void close() override;
        bool handleInput() override;
        void setSymboles(char vivant, char mort, char immortel);
};

#endif