#ifndef PIPELINE_ELEMENT_HPP
#define PIPELINE_ELEMENT_HPP

#include "Frame.hpp" // Assuming Frame.hpp contains VideoFrame class definition

class PipelineElement {
public:
    virtual void link(PipelineElement* downstreamElement);
    virtual void process(const VideoFrame& frame) = 0;
    virtual void processAndPushDownstream(const VideoFrame& frame);

protected:
    PipelineElement* downstream = nullptr;
};

#endif // PIPELINE_ELEMENT_HPP
