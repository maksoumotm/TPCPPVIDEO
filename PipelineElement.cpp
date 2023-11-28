#include "PipelineElement.hpp"

void PipelineElement::link(PipelineElement* downstreamElement) {
    downstream = downstreamElement; // Associe l'élément en aval à cet élément
}

void PipelineElement::processAndPushDownstream(const VideoFrame& frame) {
    process(frame); // Appelle la fonction de traitement sur cette trame vidéo
    if (downstream != nullptr) {
        downstream->processAndPushDownstream(frame); // Passe la trame vidéo à l'élément en aval s'il existe
    }
}
