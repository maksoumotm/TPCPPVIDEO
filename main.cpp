#include "Frame.hpp"
#include "AsyncQueue.hpp"
#include "Detector.hpp"
#include <iostream>

int main() {
    Frame frame1;
    frame1.defineWidth();
    frame1.defineHeight();

    // Générer des images aléatoires et les stocker dans AsyncQueue
    AsyncQueue queue;

    const int NUMBER_OF_FRAMES_TO_GENERATE = 100; // Modifier le nombre d'images à générer si nécessaire

    for (int i = 0; i < NUMBER_OF_FRAMES_TO_GENERATE; ++i) {
        frame1.generateRandomData();
        frame1.displayData();
        
        // Stocker l'image générée dans la file d'attente
        queue.addImage(frame1);
    }

    // Processus de détection des motifs dans les images en file d'attente
    Detector detector;

    // Traitement des images stockées dans la file d'attente
    queue.processImages();

    // Processus de détection des motifs dans les images de la file d'attente
    detector.process();

    return 0;
}

