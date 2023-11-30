#include <exception>
#include <fstream>
#include <iostream>
#include "Configuration.h"

s_Configuration_t::Configuration(const std::string& fichierConfiguration)
{
    std::ifstream file(fichierConfiguration);
    if (!file.is_open())
        throw std::runtime_error("Le fichier de configuration n'a pu être ouvert");

    try {
        readFrameWidth(file);
        readFrameHeight(file);
        readFramePixel(file);
        readPattern(file);
    } catch (const std::exception& e) {
        std::cerr << "Erreur de lecture du fichier de configuration : " << e.what() << std::endl;
        file.close();
        throw;
    }

    file.close();
}

void s_Configuration_t::readFrameWidth(std::ifstream& file)
{
    if (readAndSplitLine(file))
        if (token == "FRAME_WIDTH" and not value.empty()) {
            _frameWidth = std::stoi(value);
			return;
		}

    throw std::runtime_error("Erreur de lecteur du parametre FRAME_WIDTH");
}

void s_Configuration_t::readFrameHeight(std::ifstream& file)
{
    if (readAndSplitLine(file))
        if (token == "FRAME_HEIGHT" and not value.empty()) {
            _frameHeight = std::stoi(value);
			return;
		}

    throw std::runtime_error("Erreur de lecteur du parametre FRAME_HEIGHT");
}


void s_Configuration_t::readFramePixel(std::ifstream& file)
{
    if (readAndSplitLine(file))
        if (token == "FRAME_PIXEL_TYPE" and not value.empty() and value.size() == 2) {
            _pixelTypeOn = value.at(0);
            _pixelTypeOff = value.at(1);
			return;
		}

    throw std::runtime_error("Erreur de lecteur du parametre FRAME_PIXEL_TYPE");
}


void s_Configuration_t::readPattern(std::ifstream& file)
{
    if (std::getline(file, line) and line == "PATTERN") {
        while(std::getline(file, line))
            _pattern.addLine(std::vector<char>(line.begin(), line.end()));
        if (not _pattern.exist())
            throw std::runtime_error("Erreur de lecteur du parametre PATTERN : le pattern n'est pas défini");
    } else
        throw std::runtime_error("Erreur de lecteur du parametre PATTERN");
}