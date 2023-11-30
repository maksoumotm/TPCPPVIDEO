#include "Frame.hpp"
#include <cstdlib>
#include <ctime>

// Asks the user for the width and returns it.
int VideoFrame::defineWidth() {
    std::cout << "Input the width of the video = ";
    std::cin >> width;
    setWidth(width);
}

// Asks the user for the height and returns it.
int VideoFrame::defineHeight() {
    std::cout << "Input the height of the video = ";
    std::cin >> height;
    VideoFrame::setHeight(height);
}

// Generates random video-like data.
void VideoFrame::generateRandomData() {
    srand(time(0));

    _dataContainer = new char*[_mHeight];
    for (int i = 0; i < _mHeight; ++i)
        _dataContainer[i] = new char[_mWidth];

    for (int i = 0; i < _mHeight; ++i)
        for (int j = 0; j < _mWidth; ++j) {
            int randomValue = rand() % 2;
            _dataContainer[i][j] = (randomValue == 0) ? 'X' : 'O';
        }
}

// Display Data
void VideoFrame::displayData() const {
    std::cout << "Generated data in the container :" << std::endl;
    for (int i = 0; i < _mHeight; ++i) {
        for (int j = 0; j < _mWidth; ++j) {
            std::cout << _dataContainer[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
