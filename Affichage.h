#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "Grid.h"

class Grid;

class Affichage{
    public:
        Affichage(){}
        virtual void render(Grid* grille) = 0;
        virtual void clear() = 0;    
        virtual void init() = 0;
        virtual void close() = 0;
        virtual bool handleInput() = 0;
        virtual bool estOuvert() = 0;
        virtual ~Affichage(){}
    };

#endif
