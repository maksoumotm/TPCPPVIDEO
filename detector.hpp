#pragma once

#include "Frame.hpp"
#include <string>

class Detector : public VideoFrame {
private:
    static const int pattern_width = 2;
    static const int pattern_height = 1;
    char pattern[pattern_height][pattern_width] = {
        {'O', 'X'}
        };

    // char pattern[pattern_height][pattern_width] = {"OXO"};
    int KMPSearch(std::string pat, std::string txt, int base_index, int& found_index);
    void computeLPSArray(std::string pat, int M, int *lps);

public:
    void process();
    virtual ~Detector(){}
};
