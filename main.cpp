#include "Frame.hpp"
#include "AsyncQueue.hpp"
#include "Display.hpp"
#include <iostream>
#include <chrono>
#include <thread>

int main() {
 // Création d'un objet VideoFrame et manipulation TEST
    VideoFrame frame1;
    frame1.defineWidth();
    frame1.defineHeight();
    frame1.generateRandomData();
    frame1.displayData();

    // Création d'un objet AsyncQueue et ajout des images
    AsyncQueue queue;
    queue.addImage(frame1);

    // Traitement des images dans la file d'attente
    queue.processImages();


    return 0;
}

