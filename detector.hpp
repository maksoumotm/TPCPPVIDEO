#pragma once
#include "PipelineElement.hpp"
#include <string>
#include <vector>

class Detector : public PipelineElement {
private:
    static const int pattern_width = 2;
    static const int pattern_height = 1;
    char pattern[pattern_height][pattern_width] = {"OXO",
                                                   "XXX",
                                                   "OXO",
                                                   "XOX"};

    int KMPSearch(std::string pat, std::string txt, int base_index, int& found_index);
    void computeLPSArray(std::string pat, int M, int *lps);
    void process(const Frame& frame) override;

public:
    virtual ~Detector(){}
};
