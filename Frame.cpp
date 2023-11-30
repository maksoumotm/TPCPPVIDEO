#include "Frame.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>
#include <chrono>

int Frame::defineWidth() {
    std::cout << "Input the width of the video = ";
    std::cin >> _mWidth;
    return _mWidth;
}

int Frame::defineHeight() {
    std::cout << "Input the height of the video = ";
    std::cin >> _mHeight;
    return _mHeight;
}

void Frame::generateRandomData() {
    srand(static_cast<unsigned int>(time(0)));

    _dataContainer.clear(); // Clear previous data if any
    for (int i = 0; i < _mHeight; ++i) {
        std::vector<char> row;
        for (int j = 0; j < _mWidth; ++j) {
            int randomValue = rand() % 2;
            row.push_back((randomValue == 0) ? 'X' : 'O');
        }
        _dataContainer.push_back(row);
    }
}

void Frame::displayData() const {
    std::cout << "Generated data in the container:" << std::endl;
    for (const auto& row : _dataContainer) {
        for (char ch : row) {
            std::cout << ch;
        }
        std::cout << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

int Frame::getWidth() const {
    return _mWidth;
}

int Frame::getHeight() const {
    return _mHeight;
}

std::vector<char> Frame::getDataContainer() const {
    std::vector<char> flattenedData;
    for (const auto& row : _dataContainer) {
        for (char ch : row) {
            flattenedData.push_back(ch);
        }
    }
    return flattenedData;
}
