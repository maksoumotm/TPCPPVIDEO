#include "detector.hpp"
#include <iostream>
#include <algorithm>
#include <fstream>

void Detector::process(VideoFrame& frame)
{
    std::ofstream outputFile("output.txt", std::ios::app);
    if (!outputFile.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier de sortie." << std::endl;
        return;
    }

    // Research pattern using the KMP algorithm
    for (size_t i = 0; i < static_cast<size_t>(frame.height - pattern_height + 1); ++i) {
        size_t current_video_row = i; // Video row to match with pattern row
        size_t current_pattern_row = 0; // Pattern row used to match

        bool finish = false; // If found or not

        std::vector<int> tab_index = {-1, -1, -1, -1}; // 4 = pattern_height
        int base_index = -1;

        while (!finish) {
            
            int found_index = 0; // Index found
            std::string data = std::string(pattern[current_pattern_row]); // Raw pattern to match
            size_t index = current_video_row * frame.width; // Index to get video row
            std::string s(frame.data.begin() + index, frame.data.begin() + index + frame.width);
            base_index = (base_index == -1) ? 0 : *std::max_element(tab_index.begin(), tab_index.end()); // Start research at the last index
            outputFile << "BRR" << s << std::endl;

            if (base_index == tab_index[current_pattern_row]) {
                current_pattern_row++;
                current_video_row++;
                outputFile << "BRRAHH" << s << std::endl;
                continue;
            }
            // Search in row i
            if (KMPSearch(data, s, base_index, found_index)) {

                if (current_pattern_row == pattern_height && base_index == found_index) {
                    // Print index and part of frame where pattern detected
                    // std::cout << "Pattern found at index " << found_index << " and row " << i << std::endl;
                    // outputFile << "Pattern found at index " << found_index << " and row " << i << std::endl;
                    outputFile << "TROUVE" << std::endl;
                    outputFile << "TROUVE" << std::endl;
                    outputFile << "TROUVE" << std::endl;
                    outputFile << "TROUVE" << std::endl;
                    outputFile << "TROUVE" << std::endl;
                    outputFile << "TROUVE" << std::endl;
                    outputFile << "TROUVE" << std::endl;
                    outputFile << "TROUVE" << std::endl;
                    for (size_t j = i; j < i + 4; ++j) {
                        for (size_t k = 0; k < static_cast<size_t>(frame.width); ++k) {
                            std::cout << frame.data[j * frame.width + k];
                        }
                        std::cout << "\n";
                    }
                    tab_index[0] = found_index + 1; // Continue on the same row
                    current_pattern_row = 0;
                    current_video_row = i;
                    continue;
                }

                tab_index[current_pattern_row] = found_index;
                if (base_index != found_index) {
                    if (current_pattern_row == 0) {
                        current_pattern_row++;
                        current_video_row++;
                    } else {
                        current_pattern_row = 0;
                        current_video_row = i;
                    }
                } else {
                    current_pattern_row++;
                    current_video_row++;
                }
            } else {
                finish = true;
            }
        }
    }
}

int Detector::KMPSearch(std::string pat, std::string txt, int base_index, int& found_index)
{
    // Create lps[] that will hold the longest prefix suffix values for the pattern
    size_t pattern_size = pat.length();
    int *lps = new int[static_cast<size_t>(pattern_size)];
    size_t txt_size = txt.length();

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, static_cast<int>(pattern_size), lps);

    int i = base_index; // Index for txt
    int j = 0;          // Index for pat

    while (static_cast<size_t>(i) < txt_size) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (static_cast<size_t>(j) == pattern_size) {
            found_index = i - j; // Return 1 if the pattern is found
            delete[] lps;        // Avoid memory leak
            return 1;
        }

        // Mismatch after j matches
        else if (static_cast<size_t>(i) < txt_size && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }

    delete[] lps; // Avoid memory leak

    // Return 0 if the pattern is not found
    return 0;
}

// Used in KMP Search for preprocessing the pattern
void Detector::computeLPSArray(std::string pat, int m, int *lps)
{
    // Length of the previous longest prefix suffix
    int len = 0;
    int i = 1;

    lps[0] = 0; // lps[0] is always 0

    // The loop calculates lps[i] for i = 1 to M-1
    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i++] = len;
        } else // (pat[i] != pat[len])
        {
            if (len != 0) {

                len = lps[len - 1];

                // Also, note that we do not increment i here
            } else // if (len == 0)
            {
                lps[i++] = 0;
            }
        }
    }
}
