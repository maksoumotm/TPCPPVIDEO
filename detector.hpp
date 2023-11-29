#pragma once

#include "baseElement.hpp"
#include <string>

class Detector : public BaseElement {
private:
    static const int pattern_width = 4;
    static const int pattern_height = 4;
    char pattern[pattern_height][pattern_width] = {"0x0",
                                                   "xxx",
                                                   "0x0",
                                                   "x0x"};
    int KMPSearch(std::string pat, std::string txt, int base_index, int& found_index);
    void computeLPSArray(std::string pat, int M, int *lps);

public:
    void process(VideoFrame frame);
    virtual ~Detector(){}
};