#ifndef PIPELINE_ELEMENT_HPP
#define PIPELINE_ELEMENT_HPP

#include "Frame.hpp" // Inclusion de la classe VideoFrame définie dans Frame.hpp

class PipelineElement {
public:
    // Fonction virtuelle pour lier cet élément à un élément en aval dans le pipeline
    virtual void link(PipelineElement* downstreamElement);

    // Fonction virtuelle pour traiter une trame vidéo
    virtual void process(const VideoFrame& frame) = 0;

    // Fonction pour traiter la trame vidéo et la passer à l'élément en aval
    virtual void processAndPushDownstream(const VideoFrame& frame);

protected:
    PipelineElement* downstream = nullptr; // Pointeur vers l'élément en aval (initialisé à nullptr)
};

#endif // PIPELINE_ELEMENT_HPP

