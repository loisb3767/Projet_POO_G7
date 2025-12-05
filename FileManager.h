#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>
#include "Grid.h"
#include <utility>

class FileManager {
public:
    // Input: string (nom du fichier) | Output: pair<int, int> (largeur, hauteur)
    static pair<int, int> getDimensions(const string& filename);

    // Input: string (nom du fichier) | Output: vector<vector<int>> (matrice de données chargées)
    static vector<vector<int>> loadFromFile(const string& filename);
    // Input: string (nom du fichier), Grid* (grille à sauvegarder) | Output: aucun (void, sauvegarde dans fichier)
    static void saveToFile(const string& filename, Grid* grid);

private:
    // Input: string (nom du fichier) | Output: vector<vector<int>> (données parsées)
    static vector<vector<int>> parseTXT(const string& filename);
    // Input: string (nom du fichier) | Output: bool (true si le fichier existe)
    static bool fileExists(const string& filename);
};

#endif
