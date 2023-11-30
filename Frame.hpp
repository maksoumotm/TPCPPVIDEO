#ifndef FRAME_HPP
#define FRAME_HPP

#include <iostream>
#include <vector>

class Frame {
public:
    int defineWidth(); // Fonction pour définir la largeur de la vidéo
    int defineHeight(); // Fonction pour définir la hauteur de la vidéo
    void generateRandomData(); // Fonction pour générer des données vidéo aléatoires
    void displayData() const; // Fonction pour afficher les données vidéo
    int getWidth() const;
    int getHeight() const;
    std::vector<char> getDataContainer() const;

private:
    int _mWidth; // Largeur de la vidéo
    int _mHeight; // Hauteur de la vidéo
    std::vector<std::vector<char>> _dataContainer; // Conteneur de données vidéo
};

#endif // FRAME_HPP

