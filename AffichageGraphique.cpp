#include "AffichageGraphique.h"
#include "Grille.h"
#include <iostream>

AffichageGraphique::AffichageGraphique(int taille): 
    tailleCellule(taille), 
    couleurVivant(sf::Color::White), 
    couleurMort(sf::Color::Black), 
    fenetre(nullptr){}

void AffichageGraphique::init(){
    fenetre = new sf::RenderWindow(sf::VideoMode(400, 400), "Jeu de la vie - POO G7");
}

void AffichageGraphique::clear(){
    fenetre->clear(couleurMort);
}

void AffichageGraphique::render(Grille* grille){
    
    sf::RectangleShape cellule(sf::Vector2f(tailleCellule - 1, tailleCellule - 1));
    cellule.setFillColor(couleurVivant);

    for (int x = 0; x < grille->getLargeur(); ++x) {
        for (int y = 0; y < grille->getHauteur(); ++y) {
            if (grille->getCellule(x, y) == 1) {
                cellule.setPosition(x * tailleCellule, y * tailleCellule);
                fenetre->draw(cellule);
            }
        }
    }

    fenetre->display();
}

void AffichageGraphique::close(){
    fenetre->close();
    delete fenetre;
}   
bool AffichageGraphique::handleInput(){
    sf::Event event;
    while (fenetre->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            return false;
    }
    return true;
}
bool AffichageGraphique::estOuvert() const {
    return fenetre->isOpen();
}
void AffichageGraphique::onCellClick(int x, int y){
    std::cout << "Click : " << x << "," << y << std::endl;
}