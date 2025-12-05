#include <iostream>
#include <vector>
#include "GridNormal.h"
#include "GridToric.h"
#include "CellAlive.h"
#include "CellDead.h"
#include "ConwayRules.h"
#include "Game.h"
#include "FileManager.h"
#include "AffichageGraphique.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

int main() {
    std::string cheminFichier;
    std::cout << "Saisir chemin fichier d'entrée : ";
    std::cin >> cheminFichier;

    try {
        // --- Charger la grille depuis le fichier ---
        vector<vector<int>> cellsInt = FileManager::loadFromFile(cheminFichier);
        int hauteur = cellsInt.size();
        int largeur = cellsInt[0].size();
        bool isObstacle = false;
        
        // --- Conversion en CellState* ---
        vector<vector<CellState*>> cells(hauteur, vector<CellState*>(largeur));
        for (int y = 0; y < hauteur; y++) {
            for (int x = 0; x < largeur; x++) {
                if (cellsInt[y][x] == 1)
                    cells[y][x] = new CellAlive(x, y, isObstacle);
                else
                    cells[y][x] = new CellDead(x, y, isObstacle);
            }
        }

        // Choix grille (Torique ou Normale)
        std::string choix_grille;
        std::cout << "Grille torique ou normale (t/n) ? ";
        std::cin >> choix_grille;

        Grid* grille = nullptr; //Création grille pointeur nul pour le choix de la grille

        //Choix type de Grille (Torique || Normale)
        if (choix_grille == "t"){
            grille = new GridToric(largeur, hauteur, cells);
        }
        else if (choix_grille == "n"){
            grille = new GridNormal(largeur, hauteur, cells);
        } else{
            std::cout << "Choix de grille non valide";
            return 1; //stop si choix pas compatible
        }

        // Créer les règles de Conway, le jeu
        Rules* rules = new ConwayRules();
        Game game(grille, rules);

        // Choix mode
        std::string mode;
        std::cout << "Mode console ou graphique (c/g) ? ";
        std::cin >> mode;

        if (mode == "c") {
            int iterations;
            std::cout << "Nombre d'itérations : ";
            std::cin >> iterations;
            for (int i = 0; i < iterations; i++) {
                game.nextGeneration();
                FileManager::saveToFile(cheminFichier + "_out" + std::to_string(i+1) + ".txt", game.getGrid());
            }
        } else {
            AffichageGraphique affichage(10);
            affichage.setGrid(game.getGrid());
            affichage.init();

            while (affichage.estOuvert()) {
                if (!affichage.handleInput()) break;
                game.nextGeneration();
                affichage.clear();
                affichage.render(game.getGrid());
                sf::sleep(sf::milliseconds(80));
            }
            affichage.close();
        }

        // --- Nettoyage mémoire ---
        delete grille;
        delete rules;

    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}


