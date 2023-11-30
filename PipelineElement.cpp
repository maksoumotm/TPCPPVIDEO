#include "PipelineElement.hpp"

void PipelineElement::link(PipelineElement* downstream) {
    downstreamElements.push_back(downstream);
}

void PipelineElement::processAndPushDownstream(VideoFrame& frame) {
    process(frame);  // Call the virtual function for this element
    for (auto& downstream : downstreamElements) {
        downstream->processAndPushDownstream(frame);  // Propagate the frame downstream
    }
}

void MyFunction(VideoFrame& frame) {
    (void)frame;
}
