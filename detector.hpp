#ifndef DETECTOR_HPP
#define DETECTOR_HPP

#include "PipelineElement.hpp"
#include "Frame.hpp" /

#include <string>
#include <vector>

class Detector : public PipelineElement {
private:
    static const int pattern_width = 3; // Ajout d'une colonne pour la compatibilité
    static const int pattern_height = 4; // Correction de la hauteur du motif
    char pattern[pattern_height][pattern_width] = {
        "OXO",
        "XXX",
        "OXO",
        "XOX"
    };

    int KMPSearch(const std::string& pat, const std::string& txt, int base_index, int& found_index);
    void computeLPSArray(const std::string& pat, int m, int* lps);
    void process(const Frame& frame) override;

public:
    virtual ~Detector() {}
};

#endif // DETECTOR_HPP
