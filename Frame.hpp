#ifndef FRAME_HPP
#define FRAME_HPP

#include <iostream>

class VideoFrame {
public:
    int defineWidth(); // Fonction pour définir la largeur de la vidéo
    int defineHeight(); // Fonction pour définir la hauteur de la vidéo
    void generateRandomData(); // Fonction pour générer des données vidéo aléatoires
    void displayData() const; // Fonction pour afficher les données vidéo

private:
    int _mWidth; // Largeur de la vidéo
    int _mHeight; // Hauteur de la vidéo
    char** _dataContainer; // Conteneur de données vidéo
};

#endif // FRAME_HPP

