#include "FakeVideoSource.hpp"
#include <iostream>

FakeVideoSource::FakeVideoSource(unsigned int w, unsigned int h, unsigned int rate)
    : width(w), height(h), frameRate(rate), isRunning(false) {
    std::srand(std::time(0)); // Seed for random values
}

void FakeVideoSource::start() {
    isRunning = true;
    while (isRunning) {
        generateFrame();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / frameRate));
    }
}

void FakeVideoSource::generateFrame() {
    VideoFrame frame(width, height);

    for (char& pixel : frame.data) {
        pixel = (std::rand() % 2 == 0) ? '0' : '1'; // Randomly choose '0' or '1'
    }
    std::cout << "TEST9";
    processAndPushDownstream(frame);
}

void FakeVideoSource::process(VideoFrame& frame) {
    // Optional: Implement specific processing logic for the fake video source
    // This function is overridden from the base class PipelineElement
}
