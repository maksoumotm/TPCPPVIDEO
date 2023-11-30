#include <iostream>
#include "PatternFile.hpp"

void PatternFile::savePatterns(const std::vector<std::string>& patterns) const {
    std::ofstream file("pattern.txt");
    if (file.is_open()) {
        for (const auto& pattern : patterns) {
            file << pattern << std::endl;
        }
        file.close();
    } else {
        // Gestion de l'erreur si le fichier ne peut pas être ouvert
        std::cerr << "Erreur : Impossible d'ouvrir pattern.txt pour écriture." << std::endl;
    }
}

