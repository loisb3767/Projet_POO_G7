#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>
#include "Grid.h"


using namespace std;

class FileManager {
public:
    // Charge une grille depuis un fichier texte
    // Format: première ligne = largeur hauteur
    // Lignes suivantes: 0 (mort), 1 (vivant)
    static vector<vector<int>> loadFromFile(const string& filename);
    
    // Sauvegarde une grille dans un fichier texte
    static void saveToFile(const string& filename, Grid* grid);
    
    // Charge les dimensions depuis un fichier
    static pair<int, int> getDimensions(const string& filename);

private:
    // Parse un fichier au format texte simple
    static vector<vector<int>> parseTXT(const string& filename);
    
    // Vérifie si le fichier existe
    static bool fileExists(const string& filename);
};

#endif