#include "BaseElement.hpp"

void BaseElement::link() {

}

void BaseElement::processAndPushDownstream(const VideoFrame& frame) {
    process(frame); // Appelle la fonction de traitement sur cette trame vidéo

}