#pragma once

#include "Pattern.h"
#include <string>

struct Configuration
{
	unsigned int _frameWidth;
	unsigned int _frameHeight;
	char _pixelTypeOn;
	char _pixelTypeOff;
	Pattern _pattern;
	Configuration(const std::string&);
};
