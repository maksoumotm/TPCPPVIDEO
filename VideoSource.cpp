#include "VideoSource.hpp"

VideoSource::VideoSource(unsigned int width, unsigned int height) : currentFrame(width, height) {
    // Initialize any other properties if needed
}

void VideoSource::generateFrame() {
    // Simulate generating a frame with random two-color pixels
    // For simplicity, we use 'A' and 'B' to represent two colors

    for (unsigned int i = 0; i < currentFrame.data.size(); ++i) {
        currentFrame.data[i] = (i % 2 == 0) ? 'A' : 'B';
    }

    // Push the generated frame downstream
    processAndPushDownstream(currentFrame);
}
