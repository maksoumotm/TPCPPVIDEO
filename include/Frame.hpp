#ifndef FRAME_HPP
#define FRAME_HPP

#include <iostream>

class VideoFrame {
public:
    int defineWidth();
    int defineHeight();
    void generateRandomData();
    void displayData() const;

private:
    int _mWidth;
    int _mHeight;
    char** _dataContainer;
};

#endif // FRAME_HPP
