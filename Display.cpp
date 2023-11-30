#include <iostream>
#include <thread>
#include <chrono>

#include "Display.hpp"

void Display::displayData() const {
    std::cout << "Generated data in the container:" << std::endl;
    for (const auto& row : _dataContainer) {
        for (char ch : row) {
            std::cout << ch;
        }
        std::cout << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}