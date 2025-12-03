#include "GridToric.h"

GridToric::GridToric(int w, int h, const vector<vector<CellState*>> &cells)
        : width(w > 0 ? w : throw invalid_argument("Width doit être > 0")),
          height(h > 0 ? h : throw invalid_argument("Height doit être > 0")),
          cells(cells) {
}

int GridToric::getWidth() const {
    return width;
}
int GridToric::getHeight() const {
    return height;
}
CellState* GridToric::getCellule(int x, int y) {
    // Normaliser les coordonnées avec modulo pour gérer le tore
    int normalizedX = (x % width + width) % width;
    int normalizedY = (y % height + height) % height;

    return cells[normalizedY][normalizedX];
}

void GridToric::setCellule(int x, int y, CellState* state) {
    int normalizedX = (x % width + width) % width;
    int normalizedY = (y % height + height) % height;
    
    cells[normalizedY][normalizedX] = state;
}

int GridToric::countVoisinsAlive(int x, int y) {
    int count = 0;
    
    // Parcourir les 8 voisins
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            // Ignorer la cellule centrale
            if (dx == 0 && dy == 0) {
                continue;
            }

            // Calculer les coordonnées du voisin avec effet torique
            // (x + dx + width) % width gère les cas négatifs
            int tx = ((x + dx) % width + width) % width;
            int ty = ((y + dy) % height + height) % height;

            if (cells[ty][tx]->getType() == "CellAlive") {
                count++;
            }
        }
    }
    
    return count;
}
void GridToric::updateCell(int x, int y, Rules* rules) {
    CellState* currentCell = cells[y][x];
    int nbVoisins = countVoisinsAlive(x, y);
    CellState* newCell = currentCell->nextState(nbVoisins, rules);

    if (newCell != currentCell) {
        delete currentCell;
        cells[y][x] = newCell;
    }
}
Grid* GridToric::clone() {
    vector<vector<CellState*>> newCells(height);
    for (int y = 0; y < height; y++) {
        newCells[y].resize(width);
        for (int x = 0; x < width; x++) {
            newCells[y][x] = cells[y][x]->clone();
        }
    }
    return new GridToric(width, height, newCells);
}
void GridToric::clear() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            delete cells[y][x];
        }
    }
    cells.clear();
}