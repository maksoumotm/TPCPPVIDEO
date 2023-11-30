#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <fstream>
#include <string>

// Forward declaration of Pattern
struct Pattern;

struct s_Configuration {
    unsigned int _frameWidth;
    unsigned int _frameHeight;
    char _pixelTypeOn;
    char _pixelTypeOff;
    Pattern _pattern;

    // Constructor declaration
    s_Configuration(const std::string&);

    // Function declarations
    void readFrameWidth(std::ifstream&);
    void readFrameHeight(std::ifstream&);
    void readFramePixel(std::ifstream&);
    void readPattern(std::ifstream&);
};

#endif // CONFIGURATION_H
