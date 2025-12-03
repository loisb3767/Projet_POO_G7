#ifndef GRIDFACTORY_H
#define GRIDFACTORY_H

#include <string>
#include <vector>
#include "Grid.h"
#include "GridNormal.h"
#include "GridToric.h"
#include "CellState.h"
#include "CellAlive.h"
#include "CellDead.h"

using namespace std;

class GridFactory {
public:
    // Crée une grille vide (toutes cellules mortes)
    static Grid* createEmpty(int width, int height, bool toric);
    
    // Crée une grille à partir d'une matrice de données
    static Grid* createFromMatrix(int width, int height, 
                                   const vector<vector<int>>& data, 
                                   bool toric);
    
    // Crée une grille aléatoire avec une densité donnée
    static Grid* createRandom(int width, int height, double density, bool toric);

private:
    // Méthode helper pour initialiser la matrice de cellules
    static vector<vector<CellState*>> initializeCells(
        int width, int height, 
        const vector<vector<int>>& data);
};

#endif
