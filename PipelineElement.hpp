#ifndef PIPELINE_ELEMENT_HPP
#define PIPELINE_ELEMENT_HPP
#pragma once
#include "Frame.hpp" // Inclusion de la classe VideoFrame définie dans Frame.hpp

class PipelineElement {
public:
    // Fonction virtuelle pour lier cet élément à un élément en aval dans le pipeline
    void link(PipelineElement* downstreamElement);


protected:
    PipelineElement* downstream = nullptr; // Pointeur vers l'élément en aval (initialisé à nullptr)
        // Fonction virtuelle pour traiter une trame vidéo
    virtual void process(const Frame& frame) = 0;
    // Fonction pour traiter la trame vidéo et la passer à l'élément en aval
    void processAndPushDownstream(const Frame& frame);
};

#endif // PIPELINE_ELEMENT_HPP

