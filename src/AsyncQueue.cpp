#include "AsyncQueue.hpp"
#include <iostream>

void AsyncQueue::addImage(const VideoFrame& frame) {
    VideoFrame newFrame = frame;
    imageQueue.push_back(newFrame);
}

void AsyncQueue::processImages() const {
    for (const auto& frame : imageQueue) {
        std::cout << "Processing Image:" << std::endl;
        frame.displayData();
        std::cout << std::endl;
    }
}