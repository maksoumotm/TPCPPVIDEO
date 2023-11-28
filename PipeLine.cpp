#include "PipeLine.hpp"

void PipelineElement::link(PipelineElement* downstreamElement) {
    downstream = downstreamElement;
}

void PipelineElement::processAndPushDownstream(const VideoFrame& frame) {
    process(frame);
    if (downstream != nullptr) {
        downstream->processAndPushDownstream(frame);
    }
}
