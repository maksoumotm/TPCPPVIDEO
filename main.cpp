#include <iostream>
#include "Frame.hpp"
using namespace std;

int main(){
    cout << "TEST2" << endl;
    VideoFrame videoFrame;

    // Définition de la largeur et de la hauteur de la vidéo
    int width = videoFrame.defineWidth();
    int height = videoFrame.defineHeight();

    // Génération de données aléatoires 'X' et 'O'
    videoFrame.generateRandomData();

    // Affichage des données générées
    videoFrame.displayData();

    return 0;

    return 0;
}