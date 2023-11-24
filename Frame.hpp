#ifndef VIDEO_FRAME_HPP
#define VIDEO_FRAME_HPP

class VideoFrame {
public:
    int defineWidth();
    int defineHeight();
    void generateRandomData();
    void displayData();

private:
    int _mWidth;
    int _mHeight;
    char** _dataContainer;
};

#endif // VIDEO_FRAME_HPP