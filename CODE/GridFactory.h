#ifndef GRIDFACTORY_H
#define GRIDFACTORY_H

#include <vector>
#include <random>
#include "Grid.h"
#include "GridNormal.h"
#include "GridToric.h"
#include "CellState.h"
#include "CellAlive.h"
#include "CellDead.h"

using namespace std;

class GridFactory {
public:
    // Input: int (largeur), int (hauteur), bool (torique) | Output: Grid* (grille vide)
    static Grid* createEmpty(int width, int height, bool toric);
    // Input: int (largeur), int (hauteur), vector<vector<int>> (données), bool (torique) | Output: Grid* (grille initialisée)
    static Grid* createFromMatrix(int width, int height, const vector<vector<int>>& data, bool toric);
    // Input: int (largeur), int (hauteur), double (densité), bool (torique) | Output: Grid* (grille aléatoire)
    static Grid* createRandom(int width, int height, double density, bool toric);

private:
    // Input: int (largeur), int (hauteur), vector<vector<int>> (données) | Output: vector<vector<CellState*>> (matrice de cellules)
    static vector<vector<CellState*>> initializeCells(
        int width, int height,
        const vector<vector<int>>& data);
};

#endif
