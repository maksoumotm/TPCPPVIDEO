#include <iostream>
#include <vector>


class VideoFrame {
public:
    void generateRandomData(); // Fonction pour générer des données vidéo aléatoires
    void displayData() const; // Fonction pour afficher les données vidéo
    int getWidth() const;
    int getHeight() const;
    std::vector<char> getDataContainer() const;

private:
    int _frameWidth; // Largeur de la vidéo
    int _frameHeight; // Hauteur de la vidéo
    std::vector<std::vector<char>> _dataContainer; // Conteneur de données vidéo
};
