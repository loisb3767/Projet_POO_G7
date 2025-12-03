#include "Game.h"

Game::Game(Grid* grid, Rules* rules)
    : currentGrid(grid), nextGrid(nullptr), rules(rules), generation(0) {
    if (grid == nullptr || rules == nullptr) {
        throw std::invalid_argument("Grid et Rules ne peuvent pas être null");
    }
}

Game::~Game() {
    if (currentGrid != nullptr) {
        currentGrid->clear();
        delete currentGrid;
    }
    if (nextGrid != nullptr) {
        nextGrid->clear();
        delete nextGrid;
    }
    delete rules;
}

void Game::nextGeneration() {
    // Cloner la grille actuelle pour la prochaine génération
    nextGrid = currentGrid->clone();

    int width = currentGrid->getWidth();
    int height = currentGrid->getHeight();

    // Calculer le nouvel état basé sur currentGrid
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Compter les voisins sur la grille ORIGINALE
            int nbVoisins = currentGrid->countVoisinsAlive(x, y);

            // Obtenir la cellule actuelle
            CellState* currentCell = currentGrid->getCellule(x, y);

            // Calculer le nouvel état
            CellState* newCell = currentCell->nextState(nbVoisins, rules);

            // Mettre à jour la nouvelle grille
            if (newCell != currentCell) {
                delete nextGrid->getCellule(x, y);   // ok, nextGrid a été cloné
                nextGrid->setCellule(x, y, newCell); // transfer ownership
                // ne pas delete newCell ici
            } else {
                delete newCell; // clone() peut retourner un clone identique
            }
        }
    }

    // Nettoyer l'ancienne grille
    currentGrid->clear();
    delete currentGrid;

    // La nouvelle grille devient la grille actuelle
    currentGrid = nextGrid;
    nextGrid = nullptr;

    generation++;
}

void Game::run(int iterations) {
    for (int i = 0; i < iterations; i++) {
        nextGeneration();
    }
}

Grid* Game::getGrid() const {
    return currentGrid;
}

Rules* Game::getRules() const {
    return rules;
}

int Game::getGeneration() const {
    return generation;
}

void Game::reset(Grid* newGrid) {
    if (newGrid == nullptr) {
        throw std::invalid_argument("La nouvelle grille ne peut pas être null");
    }

    if (currentGrid != nullptr) {
        currentGrid->clear();
        delete currentGrid;
    }

    currentGrid = newGrid;
    generation = 0;
}

void Game::setRules(Rules* newRules) {
    if (newRules == nullptr) {
        throw std::invalid_argument("Les nouvelles règles ne peuvent pas être null");
    }

    delete rules;
    rules = newRules;
}
