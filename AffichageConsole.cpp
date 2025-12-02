#include "AffichageConsole.h"
#include <iostream>

AffichageConsole::AffichageConsole(char vivant, char mort, char immortel): 
symboleVivant(vivant), symboleMort(mort), symboleImmortel(immortel){}

void AffichageConsole::render(Grille* grille){
    std::cout << "Sauvegarder grille dans un fichier" << std::endl;
}

void AffichageConsole::clear(){
    //a voir
}
void AffichageConsole::init(){
    //a voir
}
void AffichageConsole::close(){
    std::cout << "Arrêt du mode console" << std::endl;
}
bool AffichageConsole::handleInput(){
    //a voir
}
void AffichageConsole::setSymboles(char vivant, char mort, char immortel){
    symboleVivant = vivant;
    symboleMort = mort;
    symboleImmortel = immortel;
}