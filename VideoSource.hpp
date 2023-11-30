#pragma once

#include "PipelineElement.hpp"

class VideoSource : public PipelineElement {
public:
    VideoSource(unsigned int width, unsigned int height);
    void generateFrame();

private:
    VideoFrame currentFrame;
};
