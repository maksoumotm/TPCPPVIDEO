#include <string>

class BaseElement {
public:
    // Fonction virtuelle pour lier cet élément à un élément en aval dans le pipeline
    void link(BaseElement* downstreamElement);
    // Fonction virtuelle pour traiter une trame vidéo
    virtual void process(const VideoFrame& frame) = 0;
    // Fonction pour traiter la trame vidéo et la passer à l'élément en aval
    void processAndPushDownstream(const VideoFrame& frame);
};