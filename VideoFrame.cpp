#include <iostream>

#include "VideoFrame.hpp"

void VideoFrame::generateRandomData() {
    srand(static_cast<unsigned int>(time(0)));

    _dataContainer.clear(); // Clear previous data if any
    for (int i = 0; i < _frameHeight; ++i) {
        std::vector<char> row;
        for (int j = 0; j < _frameWidth; ++j) {
            int randomValue = rand() % 2;
            row.push_back((randomValue == 0) ? 'X' : 'O');
        }
        _dataContainer.push_back(row);
    }
}

