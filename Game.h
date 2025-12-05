#ifndef GAME_H
#define GAME_H

#include "Grid.h"
#include "Rules.h"

class Game {
private:
    Grid* currentGrid;
    Grid* nextGrid;
    Rules* rules;
    int generation;

public:
    // Input: Grid* (grille initiale), Rules* (règles du jeu) | Output: aucun (constructeur)
    Game(Grid* grid, Rules* rules);
    // Input: aucun | Output: aucun (destructeur, libère la mémoire)
    ~Game();

    // Input: aucun | Output: Grid* (grille actuelle)
    Grid* getGrid() const;
    // Input: aucun | Output: Rules* (règles actuelles)
    Rules* getRules() const;
    // Input: aucun | Output: int (numéro de génération)
    int getGeneration() const;

    // Input: Rules* (nouvelles règles) | Output: aucun (void, change les règles)
    void setRules(Rules* newRules);

    // Input: aucun | Output: aucun (void, calcule la génération suivante)
    void nextGeneration();
    // Input: int (nombre d'itérations) | Output: aucun (void, exécute plusieurs générations)
    void run(int iterations);
    // Input: Grid* (nouvelle grille) | Output: aucun (void, réinitialise le jeu)
    void reset(Grid* newGrid);
};

#endif
