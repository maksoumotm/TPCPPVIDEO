#ifndef PATTERNFILE_HPP
#define PATTERNFILE_HPP
#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

class PatternFile {
public:
    void savePatterns(const std::vector<std::string>& patterns) const;
};

#endif // PATTERNFILE_HPP
