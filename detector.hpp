#pragma once

#include "Frame.hpp"
#include <string>

class Detector : public VideoFrame {
private:
    static const int pattern_width = 4;
    static const int pattern_height = 4;
    char pattern[pattern_height][pattern_width] = {"OXO",
                                                   "XXX",
                                                   "OXO",
                                                   "XOX"};
    int KMPSearch(std::string pat, std::string txt, int base_index, int& found_index);
    void computeLPSArray(std::string pat, int M, int *lps);

public:
    void process(VideoFrame VideoFrame);
    virtual ~Detector(){}
};