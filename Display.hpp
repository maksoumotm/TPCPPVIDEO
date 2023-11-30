#include <iostream>
#include <vector>

class Display {
public:
    void displayData() const; // Fonction pour afficher les données vidéo
    int getWidth() const;
    int getHeight() const;
    std::vector<char> getDataContainer() const;

private:
    int _mWidth; // Largeur de la vidéo
    int _mHeight; // Hauteur de la vidéo
    std::vector<std::vector<char>> _dataContainer; // Conteneur de données vidéo
};