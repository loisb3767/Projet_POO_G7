#include "GestionFichierEntree.h"
#include <fstream>
#include <filesystem>

GestionFichierEntree::GestionFichierEntree(const std::string& cheminFichier): //notre constructeur reçoit le chemin du fichier
chemin(cheminFichier) {}

std::string GestionFichierEntree::lireContenu() const {
    std::ifstream fichier(chemin); //ouverture fichier en mode lecture
    if (!fichier)
        return ""; //si l'ouverture ne peut pas être effectuée, on renvoi une chaine vide

    return std::string(     //permet d'avoir tout le fichier d'entrée en chaine de caractères
        (std::istreambuf_iterator<char>(fichier)), 
        std::istreambuf_iterator<char>()
    );
}

std::string GestionFichierEntree::getNomFichier() const {
    return std::filesystem::path(chemin).filename().string();
}
