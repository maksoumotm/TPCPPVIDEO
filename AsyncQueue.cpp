#include "AsyncQueue.hpp"
#include <iostream>

void AsyncQueue::addImage(const VideoFrame& frame) {
    VideoFrame newFrame = frame; // Crée une copie de la trame vidéo
    imageQueue.push_back(newFrame); // Ajoute la trame vidéo à la file d'attente
}

void AsyncQueue::processImages() const {
    for (const auto& frame : imageQueue) {
        std::cout << "Processing Image:" << std::endl;
        frame.displayData(); // Affiche les données de la trame vidéo
        std::cout << std::endl;
    }
}



