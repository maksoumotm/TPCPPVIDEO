#ifndef FRAME_HPP
#define FRAME_HPP

#include <iostream>

class VideoFrame {
    public:
        int defineWidth();
        int defineHeight();
        // int getWitdh();
        // int getHeight();
        // void setWidth();
        // void setHeight();
        void generateRandomData();
        void displayData() const;

    private:
        int _mWidth;
        int _mHeight;
        char** _dataContainer;

    int getWidth() {
        return _mWidth;
    }

    int getHeight() {
        return _mHeight;
    }

    void setWidth(int width) {
        _mWidth = width;
    }


    void setHeight(int height) {
        _mHeight = height;
    }
};

#endif // FRAME_HPP
