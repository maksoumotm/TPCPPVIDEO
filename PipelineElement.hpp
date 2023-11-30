#pragma once

#include "VideoFrame.hpp"
#include <vector>  // Include vector header for downstreamElements

class PipelineElement {
public:
    virtual void process(VideoFrame& frame) = 0;  // Virtual, but not pure virtual
    void link(PipelineElement* downstream); // This function remains pure virtual
    void processAndPushDownstream(VideoFrame& frame); // This function remains pure virtual

protected:
    std::vector<PipelineElement*> downstreamElements; // Declare downstreamElements as a protected member
};
