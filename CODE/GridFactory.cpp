#include "GridFactory.h"
#include <random>
#include <stdexcept>

Grid* GridFactory::createEmpty(int width, int height, bool toric) {
    vector data(height, vector(width, 0));
    return createFromMatrix(width, height, data, toric);
}

Grid* GridFactory::createFromMatrix(int width, int height, 
                                     const vector<vector<int>>& data, 
                                     bool toric) {
    if (width <= 0 || height <= 0) {
        throw invalid_argument("Width et height doivent être > 0");
    }
    
    vector<vector<CellState*>> cells = initializeCells(width, height, data);
    
    if (toric) {
        return new GridToric(width, height, cells);
    }
    return new GridNormal(width, height, cells);
}

Grid* GridFactory::createRandom(int width, int height, double density, bool toric) {
    if (density < 0.0 || density > 1.0) {
        throw invalid_argument("La densité doit être entre 0.0 et 1.0");
    }
    
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    
    vector data(height, vector(width, 0));
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            data[y][x] = (dis(gen) < density) ? 1 : 0;
        }
    }
    
    return createFromMatrix(width, height, data, toric);
}

vector<vector<CellState*>> GridFactory::initializeCells(
    int width, int height, 
    const vector<vector<int>>& data) {
    
    vector<vector<CellState*>> cells(height);
    
    for (int y = 0; y < height; y++) {
        cells[y].resize(width);
        for (int x = 0; x < width; x++) {
            bool isAlive = (y < static_cast<int>(data.size()) && 
                           x < static_cast<int>(data[y].size()) && 
                           data[y][x] == 1);
            
            // Les cellules normales n'ont pas d'obstacles (false)
            if (isAlive) {
                cells[y][x] = new CellAlive(x, y, false);
            } else {
                cells[y][x] = new CellDead(x, y, false);
            }
        }
    }
    
    return cells;
}

