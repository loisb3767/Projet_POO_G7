#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>
#include "Grid.h"
#include "GridNormal.h"
#include "GridToric.h"
#include "CellState.h"
#include "CellAlive.h"
#include "CellDead.h"
#include "ConwayRules.h"
#include "Game.h"

using namespace std;

// Input: Grid* (grille1), Grid* (grille2) | Output: bool (true si identiques)
bool compareGrids(Grid* grid1, Grid* grid2) {
    if (grid1->getWidth() != grid2->getWidth() ||
        grid1->getHeight() != grid2->getHeight()) {
        return false;
    }

    for (int y = 0; y < grid1->getHeight(); y++) {
        for (int x = 0; x < grid1->getWidth(); x++) {
            CellState* cell1 = grid1->getCellule(x, y);
            CellState* cell2 = grid2->getCellule(x, y);
            if (cell1->getType() != cell2->getType()) {
                return false;
            }
        }
    }
    return true;
}

// Input: vector<vector<int>> (données), bool (torique) | Output: Grid* (grille créée)
Grid* createGridFromData(const vector<vector<int>>& data, bool toric) {
    int height = data.size();
    int width = data[0].size();

    vector<vector<CellState*>> cells(height);
    for (int y = 0; y < height; y++) {
        cells[y].resize(width);
        for (int x = 0; x < width; x++) {
            if (data[y][x] == 1) {
                cells[y][x] = new CellAlive(x, y, false);
            } else {
                cells[y][x] = new CellDead(x, y, false);
            }
        }
    }

    if (toric) {
        return new GridToric(width, height, cells);
    } else {
        return new GridNormal(width, height, cells);
    }
}

// Input: Grid* (grille) | Output: aucun (void, affiche la grille)
void printGrid(Grid* grid) {
    for (int y = 0; y < grid->getHeight(); y++) {
        for (int x = 0; x < grid->getWidth(); x++) {
            CellState* cell = grid->getCellule(x, y);
            cout << (cell->getType() == "CellAlive" ? "1" : "0") << " ";
        }
        cout << endl;
    }
}

// Test 1: Bloc stable - doit lever une exception après 1 itération
void testBlockStableException() {
    cout << "\n=== Test 1: Bloc stable lève exception (Grille Normale) ===" << endl;

    vector<vector<int>> blockData = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    Grid* initial = createGridFromData(blockData, false);
    Rules* rules = new ConwayRules();
    Game game(initial, rules);

    bool exceptionThrown = false;
    string exceptionMessage;

    try {
        game.nextGeneration();
    } catch (const std::runtime_error& e) {
        exceptionThrown = true;
        exceptionMessage = e.what();
    }

    assert(exceptionThrown && "L'exception devrait être levée pour un pattern stable");
    assert(exceptionMessage == "La grille n'évolue plus." && "Message d'exception incorrect");

    cout << "✓ Exception correctement levée: \"" << exceptionMessage << "\"" << endl;
}

// Test 2: Grille Torique - Pattern stable doit aussi lever exception
void testToricStableException() {
    cout << "\n=== Test 2: Bloc stable lève exception (Grille Torique) ===" << endl;

    vector<vector<int>> blockData = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    Grid* initial = createGridFromData(blockData, true);
    Rules* rules = new ConwayRules();
    Game game(initial, rules);

    bool exceptionThrown = false;

    try {
        game.nextGeneration();
    } catch (const std::runtime_error& e) {
        exceptionThrown = true;
    }

    assert(exceptionThrown && "L'exception devrait être levée pour un pattern stable (torique)");

    cout << "✓ Exception correctement levée pour grille torique" << endl;
}

// Test 3: Blinker (oscillateur période 2) - Grille Normale
void testBlinkerNormal() {
    cout << "\n=== Test 3: Blinker période 2 (Grille Normale) ===" << endl;

    vector<vector<int>> blinkerInit = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    vector<vector<int>> blinkerExpected = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    Grid* initial = createGridFromData(blinkerInit, false);
    Grid* expected = createGridFromData(blinkerExpected, false);
    Rules* rules = new ConwayRules();
    Game game(initial->clone(), rules);

    for (int i = 0; i < 10; i++) {
        try {
            game.nextGeneration();
        } catch (const std::runtime_error&) {
            break;
        }
    }

    bool result = compareGrids(game.getGrid(), expected);
    assert(result && "Le blinker devrait revenir à son état initial après 10 itérations");

    cout << "✓ Blinker correctement simulé" << endl;
    delete expected;
}

// Test 4: Blinker (oscillateur période 2) - Grille Torique
void testBlinkerToric() {
    cout << "\n=== Test 4: Blinker période 2 (Grille Torique) ===" << endl;

    vector<vector<int>> blinkerInit = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    vector<vector<int>> blinkerExpected = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    Grid* initial = createGridFromData(blinkerInit, true);
    Grid* expected = createGridFromData(blinkerExpected, true);
    Rules* rules = new ConwayRules();
    Game game(initial->clone(), rules);

    for (int i = 0; i < 10; i++) {
        try {
            game.nextGeneration();
        } catch (const std::runtime_error&) {
            break;
        }
    }

    bool result = compareGrids(game.getGrid(), expected);
    assert(result && "Le blinker devrait revenir à son état initial après 10 itérations");

    cout << "✓ Blinker correctement simulé" << endl;
    delete expected;
}

// Test 5: Glider sur grille torique vs normale (comportement différent)
void testGliderToricVsNormal() {
    cout << "\n=== Test 5: Glider - Grille Normale vs Torique ===" << endl;

    vector<vector<int>> gliderData = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 1, 1}
    };

    Grid* normalGrid = createGridFromData(gliderData, false);
    Grid* toricGrid = createGridFromData(gliderData, true);

    Rules* rules1 = new ConwayRules();
    Rules* rules2 = new ConwayRules();

    Game gameNormal(normalGrid, rules1);
    Game gameToric(toricGrid, rules2);

    for (int i = 0; i < 4; i++) {
        try {
            gameNormal.nextGeneration();
            gameToric.nextGeneration();
        } catch (...) {
            break;
        }
    }

    bool areDifferent = !compareGrids(gameNormal.getGrid(), gameToric.getGrid());
    assert(areDifferent && "Les grilles normale et torique devraient évoluer différemment");

    cout << "✓ Grille normale et torique ont des comportements différents" << endl;
}

// Test 6: Comptage des voisins en grille torique
void testToricNeighborCount() {
    cout << "\n=== Test 6: Comptage voisins torique ===" << endl;

    vector<vector<int>> toricData = {
        {1, 0, 0, 0, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {1, 0, 0, 0, 1}
    };

    Grid* toricGrid = createGridFromData(toricData, true);

    int neighbors = toricGrid->countVoisinsAlive(0, 0);
    assert(neighbors == 3 && "La cellule (0,0) devrait avoir 3 voisins vivants en torique");

    delete toricGrid;
    cout << "✓ Comptage des voisins correct en mode torique" << endl;
}

// Test 7: Vérifier qu'un pattern vide reste vide
void testEmptyGridStaysEmpty() {
    cout << "\n=== Test 7: Grille vide reste vide ===" << endl;

    vector<vector<int>> emptyData = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    Grid* initial = createGridFromData(emptyData, false);
    Grid* expected = createGridFromData(emptyData, false);
    Rules* rules = new ConwayRules();
    Game game(initial->clone(), rules);

    bool exceptionThrown = false;
    try {
        game.nextGeneration();
    } catch (const std::runtime_error&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown && "Une grille vide devrait lever l'exception");

    cout << "✓ Grille vide lève correctement l'exception" << endl;
    delete expected;
}

// Test 8: Grille avec dimensions nulles - GridNormal
void testGridNormalZeroDimensions() {
    cout << "\n=== Test 8: Dimensions nulles lèvent exception (GridNormal) ===" << endl;

    vector<vector<CellState*>> emptyCells;

    // Test avec width = 0
    bool exception1Thrown = false;
    string message1;
    try {
        GridNormal* grid = new GridNormal(0, 5, emptyCells);
    } catch (const invalid_argument& e) {
        exception1Thrown = true;
        message1 = e.what();
    }
    assert(exception1Thrown && "Exception attendue pour width = 0");
    assert(message1 == "Width doit être > 0" && "Message incorrect pour width = 0");
    cout << "  ✓ Width = 0 lève exception: \"" << message1 << "\"" << endl;

    // Test avec height = 0
    bool exception2Thrown = false;
    string message2;
    try {
        GridNormal* grid = new GridNormal(5, 0, emptyCells);
    } catch (const invalid_argument& e) {
        exception2Thrown = true;
        message2 = e.what();
    }
    assert(exception2Thrown && "Exception attendue pour height = 0");
    assert(message2 == "Height doit être > 0" && "Message incorrect pour height = 0");
    cout << "  ✓ Height = 0 lève exception: \"" << message2 << "\"" << endl;

    // Test avec width et height négatifs
    bool exception3Thrown = false;
    try {
        GridNormal* grid = new GridNormal(-5, -3, emptyCells);
    } catch (const invalid_argument& e) {
        exception3Thrown = true;
    }
    assert(exception3Thrown && "Exception attendue pour dimensions négatives");
    cout << "  ✓ Dimensions négatives lèvent exception" << endl;
}

// Test 9: Grille avec dimensions nulles - GridToric
void testGridToricZeroDimensions() {
    cout << "\n=== Test 9: Dimensions nulles lèvent exception (GridToric) ===" << endl;

    vector<vector<CellState*>> emptyCells;

    // Test avec width = 0
    bool exception1Thrown = false;
    string message1;
    try {
        GridToric* grid = new GridToric(0, 5, emptyCells);
    } catch (const invalid_argument& e) {
        exception1Thrown = true;
        message1 = e.what();
    }
    assert(exception1Thrown && "Exception attendue pour width = 0 (torique)");
    assert(message1 == "Width doit être > 0" && "Message incorrect pour width = 0 (torique)");
    cout << "  ✓ Width = 0 lève exception: \"" << message1 << "\"" << endl;

    // Test avec height = 0
    bool exception2Thrown = false;
    string message2;
    try {
        GridToric* grid = new GridToric(5, 0, emptyCells);
    } catch (const invalid_argument& e) {
        exception2Thrown = true;
        message2 = e.what();
    }
    assert(exception2Thrown && "Exception attendue pour height = 0 (torique)");
    assert(message2 == "Height doit être > 0" && "Message incorrect pour height = 0 (torique)");
    cout << "  ✓ Height = 0 lève exception: \"" << message2 << "\"" << endl;

    // Test avec les deux à zéro
    bool exception3Thrown = false;
    try {
        GridToric* grid = new GridToric(0, 0, emptyCells);
    } catch (const invalid_argument& e) {
        exception3Thrown = true;
    }
    assert(exception3Thrown && "Exception attendue pour width = 0 et height = 0");
    cout << "  ✓ Width et Height = 0 lèvent exception" << endl;
}

// Test 10: Constructeur Game avec Grid nullptr
void testGameConstructorNullGrid() {
    cout << "\n=== Test 10: Game avec Grid nullptr ===" << endl;

    Rules* rules = new ConwayRules();

    bool exceptionThrown = false;
    string message;
    try {
        Game game(nullptr, rules);
    } catch (const invalid_argument& e) {
        exceptionThrown = true;
        message = e.what();
        delete rules; // Nettoyer car Game n'a pas été créé
    }

    assert(exceptionThrown && "Exception attendue pour Grid nullptr");
    assert(message == "Grid et Rules ne peuvent pas être null" && "Message incorrect");
    cout << "  ✓ Grid nullptr lève exception: \"" << message << "\"" << endl;
}

// Test 11: Constructeur Game avec Rules nullptr
void testGameConstructorNullRules() {
    cout << "\n=== Test 11: Game avec Rules nullptr ===" << endl;

    vector<vector<int>> blockData = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    Grid* grid = createGridFromData(blockData, false);

    bool exceptionThrown = false;
    string message;
    try {
        Game game(grid, nullptr);
    } catch (const invalid_argument& e) {
        exceptionThrown = true;
        message = e.what();
        delete grid; // Nettoyer car Game n'a pas été créé
    }

    assert(exceptionThrown && "Exception attendue pour Rules nullptr");
    assert(message == "Grid et Rules ne peuvent pas être null" && "Message incorrect");
    cout << "  ✓ Rules nullptr lève exception: \"" << message << "\"" << endl;
}


int main() {
    cout << "========================================" << endl;
    cout << "  TESTS UNITAIRES - JEU DE LA VIE" << endl;
    cout << "========================================" << endl;

    testBlockStableException();
    testToricStableException();
    testBlinkerNormal();
    testBlinkerToric();
    testGliderToricVsNormal();
    testToricNeighborCount();
    testEmptyGridStaysEmpty();
    testGridNormalZeroDimensions();
    testGridToricZeroDimensions();
    testGameConstructorNullGrid();
    testGameConstructorNullRules();


    cout << "\n========================================" << endl;
    cout << "  TOUS LES TESTS SONT PASSÉS ✓" << endl;
    cout << "========================================" << endl;

    return 0;
}
