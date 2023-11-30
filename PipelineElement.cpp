#include "PipelineElement.hpp"

void PipelineElement::link() {
    
}

void PipelineElement::processAndPushDownstream(const Frame& frame) {
    process(frame); // Appelle la fonction de traitement sur cette trame vidéo
    
}
