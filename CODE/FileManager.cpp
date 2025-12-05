#include "FileManager.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <filesystem>
#include <iostream>

vector<vector<int>> FileManager::loadFromFile(const string& filename) {
    if (!fileExists(filename)) {
        throw runtime_error("Fichier introuvable: " + filename);
    }
    
    return parseTXT(filename);
}

void FileManager::saveToFile(const string& filename, Grid* grid) {
    if (grid == nullptr) {
        throw invalid_argument("La grille ne peut pas être null");
    }
    
    std::string folder = "out";
    std::filesystem::create_directories(folder);

    std::string fullPath = folder + "/" + filename;

    ofstream file(fullPath);
    if (!file.is_open()) {
        throw runtime_error("Impossible d'ouvrir le fichier: " + fullPath);
    }
    
    int width = grid->getWidth();
    int height = grid->getHeight();
    
    // Écrire les dimensions
    file << width << " " << height << endl;
    
    // Écrire la grille (matrice binaire)
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            CellState* cell = grid->getCellule(x, y);
            if (cell->getType() == "CellAlive") {
                file << "1";
            } else {
                file << "0";
            }
            if (x < width - 1) {
                file << " ";
            }
        }
        file << endl;
    }

    file.close();
}

pair<int, int> FileManager::getDimensions(const string& filename) {
    if (!fileExists(filename)) {
        throw runtime_error("Fichier introuvable: " + filename);
    }

    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Impossible d'ouvrir le fichier: " + filename);
    }

    string line;
    getline(file, line);

    istringstream iss(line);
    int width, height;

    if (!(iss >> width >> height)) {
        throw runtime_error("Format de fichier invalide (dimensions manquantes)");
    }

    file.close();
    return make_pair(width, height);
}

vector<vector<int>> FileManager::parseTXT(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Impossible d'ouvrir le fichier: " + filename);
    }

    string line;
    vector<vector<int>> data;

    // Lire la première ligne pour les dimensions
    getline(file, line);
    istringstream dimStream(line);
    int width, height;

    if (!(dimStream >> width >> height)) {
        throw runtime_error("Format de fichier invalide (dimensions)");
    }

    if (width <= 0 || height <= 0) {
        throw runtime_error("Dimensions invalides dans le fichier");
    }

    // Lire les lignes de données (matrice binaire)
    int lineCount = 0;
    while (getline(file, line) && lineCount < height) {
        vector<int> row;
        istringstream iss(line);
        int value;

        while (iss >> value) {
            if (value != 0 && value != 1) {
                throw runtime_error("Valeur invalide dans le fichier (doit être 0 ou 1)");
            }
            row.push_back(value);
        }
        
        if (row.size() != static_cast<size_t>(width)) {
            throw runtime_error("Nombre de colonnes incorrect à la ligne " + 
                              to_string(lineCount + 2));
        }
        
        data.push_back(row);
        lineCount++;
    }
    
    if (lineCount != height) {
        throw runtime_error("Nombre de lignes incorrect dans le fichier");
    }
    
    file.close();
    return data;
}

bool FileManager::fileExists(const string& filename) {
    ifstream file(filename);
    return file.good();
}
