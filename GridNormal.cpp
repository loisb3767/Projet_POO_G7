#include "GridNormal.h"


GridNormal::GridNormal(int w, int h, const vector<vector<CellState*>> &cells)
        : width(w > 0 ? w : throw invalid_argument("Width doit être > 0")),
          height(h > 0 ? h : throw invalid_argument("Height doit être > 0")),
          cells(cells) {
}

int GridNormal::getWidth() const {
    return width;
}
int GridNormal::getHeight() const {
    return height;
}

CellState* GridNormal::getCellule(int x, int y) {
    return cells[y][x];  // y = ligne, x = colonne
}

void GridNormal::setCellule(int x, int y, CellState* state) {
    cells[y][x] = state;  // y = ligne, x = colonne
}

int GridNormal::countVoisinsAlive(int x, int y) {
    int count = 0;

    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dx == 0 && dy == 0) continue;

            int voisinX = x + dx;
            int voisinY = y + dy;

            if (voisinX >= 0 && voisinX < static_cast<int>(width) &&
                voisinY >= 0 && voisinY < static_cast<int>(height)) {

                if (cells[voisinY][voisinX]->getType() == "CellAlive") {
                    count++;
                }
            }
        }
    }
    return count;
}
void GridNormal::updateCell(int x, int y, Rules* rules) {
    CellState* currentCell = cells[y][x];
    int nbVoisins = countVoisinsAlive(x, y);
    CellState* newCell = currentCell->nextState(nbVoisins, rules);

    if (newCell != currentCell) {
        delete currentCell;
        cells[y][x] = newCell;
    }
}
Grid* GridNormal::clone() {
    vector<vector<CellState*>> newCells(height);
    for (int y = 0; y < height; y++) {
        newCells[y].resize(width);
        for (int x = 0; x < width; x++) {
            newCells[y][x] = cells[y][x]->clone();
        }
    }
    return new GridNormal(width, height, newCells);
}
void GridNormal::clear() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            delete cells[y][x];
        }
    }
    cells.clear();
}

