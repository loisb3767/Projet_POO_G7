#include "GridFactory.h"
#include <random>


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

Grid* GridFactory::createFromPattern(int width, int height, 
                                      const string& patternName, 
                                      bool toric) {
    vector<vector<int>> pattern;
    
    if (patternName == "glider") {
        pattern = getGliderPattern();
    } else if (patternName == "blinker") {
        pattern = getBlinkerPattern();
    } else if (patternName == "glider_gun") {
        pattern = getGliderGunPattern();
    } else {
        throw invalid_argument("Pattern inconnu: " + patternName);
    }
    
    // Créer une grille vide et placer le pattern au centre
    vector data(height, vector(width, 0));
    
    int patternHeight = pattern.size();
    int patternWidth = pattern[0].size();
    
    int startY = (height - patternHeight) / 2;
    int startX = (width - patternWidth) / 2;
    
    for (int y = 0; y < patternHeight; y++) {
        for (int x = 0; x < patternWidth; x++) {
            int targetY = startY + y;
            int targetX = startX + x;
            if (targetY >= 0 && targetY < height && targetX >= 0 && targetX < width) {
                data[targetY][targetX] = pattern[y][x];
            }
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

vector<vector<int>> GridFactory::getGliderPattern() {
    return {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1}
    };
}

vector<vector<int>> GridFactory::getBlinkerPattern() {
    return {
        {1, 1, 1}
    };
}

vector<vector<int>> GridFactory::getGliderGunPattern() {
    // Pattern du Gosper Glider Gun (simplifié)
    return {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
        {1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    };
}
