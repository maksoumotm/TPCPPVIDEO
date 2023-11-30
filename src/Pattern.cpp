#include <iostream>
#include "Pattern.h"


void Pattern::addLine(const std::vector<char>& line)
{
	auto aLine = line;
	if (width > line.size())
	{
		aLine.resize(width, ' ');
	}
	else if (width < line.size())
	{
		width = aLine.size();
		for(auto & v : img)
		{
			v.resize(width, ' ');
		}
	}

	img.push_back(aLine);
	height++;
}

bool Pattern::exist()
{
	return img.size();
}


void Pattern::print()
{
	for(const auto & v : img)
	{
		for(auto const elt : v)
		{
			std::cout << elt;
		}
		std::cout << "\n";
	}
}
