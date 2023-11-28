#ifndef ASYNCQUEUE_HPP
#define ASYNCQUEUE_HPP

#include <vector>
#include "Frame.hpp"

class AsyncQueue {
private:
    std::vector<VideoFrame> imageQueue; // File d'attente pour les trames vidéo

public:
    void addImage(const VideoFrame& frame); // Ajoute une trame vidéo à la file d'attente
    void processImages() const; // Traite les trames vidéo dans la file d'attente
};

#endif // ASYNCQUEUE_HPP
