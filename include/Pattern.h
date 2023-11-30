#pragma once

#include <vector>

struct Pattern
{
	unsigned int width = 0;
	unsigned int height = 0;
	std::vector<std::vector<char>> img;
	void addLine(const std::vector<char>&);
	bool exist();
	void print();
};
