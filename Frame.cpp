#include "frame.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int VideoFrame::defineWidth() {
    std::cout << "Input the weight of the video = ";
    std::cin >> _mWidth;
    return _mWidth;
}

int VideoFrame::defineHeight() {
    std::cout << "Input the height of the video = ";
    std::cin >> _mHeight;
    return _mHeight;
}

void VideoFrame::generateRandomData() {
    srand(time(0));

    _dataContainer = new char*[_mHeight];
    for (int i = 0; i < _mHeight; ++i) {
        _dataContainer[i] = new char[_mWidth];
    }

    for (int i = 0; i < _mHeight; ++i) {
        for (int j = 0; j < _mWidth; ++j) {
            int randomValue = rand() % 2;
            _dataContainer[i][j] = (randomValue == 0) ? 'X' : 'O';
        }
    }
}

void VideoFrame::displayData() {
    std::cout << "Generated data in the container :" << std::endl;
    for (int i = 0; i < _mHeight; ++i) {
        for (int j = 0; j < _mWidth; ++j) {
            std::cout << _dataContainer[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
