#include "Frame.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>  // Include the <thread> header for sleep_for
#include <chrono>  // Include the <chrono> header for duration_cast

int VideoFrame::defineWidth() {
    std::cout << "Input the width of the video = ";
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

void VideoFrame::displayData() const {
    std::cout << "Generated data in the container :" << std::endl;
    for (int i = 0; i < _mHeight; ++i) {
        for (int j = 0; j < _mWidth; ++j) {
            // std::cout << _dataContainer[i][j] << " ";
            std::cout << _dataContainer[i][j];
        }
        std::cout << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    // std::cout << "\033[2J" << "\033[1;1H";
}
