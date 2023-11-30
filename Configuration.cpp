#include <exception>
#include <fstream>
#include <iostream>
#include "Configuration.hpp"


Configuration::Configuration(const std::string& fichierConfiguration)
{
	std::ifstream file(fichierConfiguration);
	if (not file.is_open())
	{
		throw "Le fichier de configuration n'a pu être ouvert";
	}

	std::string line;
	std::string delimiter = "=";
	std::string token, value;

	auto const readAndSplitLine = [&]() -> bool
	{
		if (std::getline(file, line))
		{
			size_t pos = line.find(delimiter);
			if (pos != std::string::npos)
			{
				token = line.substr(0, pos);
				value = line.substr(pos + delimiter.size(), line.size());
				return true;
			}
		}
		return false;
	};

	auto const  readFrameWidth = [&]() -> bool
	{
		bool ret =  readAndSplitLine()
			and token == "FRAME_WIDTH"
			and not value.empty();

		if (ret)
			_frameWidth = stoi(value);
		else
			std::cout << "Erreur de lecteur du parametre FRAME_WIDTH" << std::endl;

		return ret;
	};

	auto const  readFrameHeight = [&]() -> bool
	{
		bool ret =  readAndSplitLine()
			and token == "FRAME_HEIGHT"
			and not value.empty();

		if (ret)
		{
			_frameHeight = stoi(value);
		}
		else
		{
			std::cout << "Erreur de lecteur du parametre FRAME_HEIGHT" << std::endl;
		}

		return ret;
	};

	auto const  readFramePixel = [&]() -> bool
	{
		bool ret =  readAndSplitLine()
			and token == "FRAME_PIXEL_TYPE"
			and not value.empty()
			and value.size() == 2;

		if (ret)
		{
			_pixelTypeOn = value.at(0);
			_pixelTypeOff = value.at(1);
		}
		else
		{
			std::cout << "Erreur de lecteur du parametre FRAME_PIXEL_TYPE" << std::endl;
		}

		return ret;
	};

	auto const readPattern = [&]() -> bool
	{
		if (std::getline(file, line) and line == "PATTERN")
		{
			while(std::getline(file, line))
			{
				_pattern.addLine(std::vector<char>(line.begin(), line.end()));
			}

			if (not _pattern.exist())
				std::cout << "Erreur de lecteur du parametre PATTERN : le pattern n'est pas défini" << std::endl;
			else
				return true;
		}
		else
			std::cout << "Erreur de lecteur du parametre PATTERN" << std::endl;

		return false;
	};



	bool res =  readFrameWidth()
		and readFrameHeight()
		and readFramePixel()
		and readPattern();


	file.close();

	if (not res)
	{
		exit(1);
	}
}

