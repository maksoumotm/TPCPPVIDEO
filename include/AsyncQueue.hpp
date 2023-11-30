#ifndef ASYNCQUEUE_HPP
#define ASYNCQUEUE_HPP

#include <vector>
#include "Frame.hpp"

class AsyncQueue {
private:
    std::vector<VideoFrame> imageQueue;

public:
    void addImage(const VideoFrame& frame);
    void processImages() const;
};

#endif // ASYNCQUEUE_HPP
