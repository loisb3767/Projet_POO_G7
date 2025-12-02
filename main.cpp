#include "Grille.h"
#include "AffichageGraphique.h"
#include <SFML/System.hpp>

int main() {
    const int largeur = 80;
    const int hauteur = 80;
    const int tailleCellule = 10;

    Grille grille(largeur, hauteur);
    grille.initialiser();

    AffichageGraphique affichage(tailleCellule);
    affichage.init();

    sf::Clock horloge;             
    const sf::Time intervalle = sf::seconds(3.0f); //1 seconde

    while (affichage.estOuvert()) {
        if (!affichage.handleInput())   //Gestion évènements
            break;

        if (horloge.getElapsedTime() >= intervalle) {   //Verification 1 seconde passée
            grille.initialiser();  // Recrée une nouvelle grille
            horloge.restart();     // Réinitialise l’horloge
        }

        affichage.clear();      //Rendu
        affichage.render(&grille);
    }
    affichage.close();

    //affichage.close();
    return 0;
}
