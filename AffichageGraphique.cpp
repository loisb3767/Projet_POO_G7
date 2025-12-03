#include "AffichageGraphique.h"
#include "Grid.h"
#include <iostream>

AffichageGraphique::AffichageGraphique(int taille)
    : tailleCellule(taille), couleurVivant(sf::Color::Black),
      couleurMort(sf::Color::White), fenetre(nullptr), grille(nullptr) {}

void AffichageGraphique::init() {
    fenetre = new sf::RenderWindow(sf::VideoMode(400, 400), "Jeu de la vie - POO G7");
}

void AffichageGraphique::clear() {
    if (fenetre)
        fenetre->clear(couleurMort);
}

void AffichageGraphique::setGrid(Grid* g) {
    this->grille = g;
}

void AffichageGraphique::render(Grid* g) {
    Grid* gridToDraw = g ? g : grille;
    if (!gridToDraw || !fenetre) return;

    sf::RectangleShape cellule(sf::Vector2f(tailleCellule - 1, tailleCellule - 1));
    cellule.setFillColor(couleurVivant);

    for (int y = 0; y < gridToDraw->getHeight(); ++y) {
        for (int x = 0; x < gridToDraw->getWidth(); ++x) {
            CellState* cell = gridToDraw->getCellule(x, y);
            if (cell && cell->getType() == "CellAlive") {
                cellule.setPosition(x * tailleCellule, y * tailleCellule);
                fenetre->draw(cellule);
            }
        }
    }

    fenetre->display();
}

void AffichageGraphique::close() {
    if (fenetre) {
        fenetre->close();
        delete fenetre;
        fenetre = nullptr;
    }
}

bool AffichageGraphique::handleInput() {
    if (!fenetre) return false;

    sf::Event event;
    while (fenetre->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            return false;
    }
    return true;
}

bool AffichageGraphique::estOuvert() {
    return fenetre && fenetre->isOpen();
}

