#include "detector.hpp"
#include "iostream"
#include <algorithm>
#include <vector>


void Detector::process(VideoFrame VideoFrame)
{
    // research pattern using the KMP algorythm
    for (int i = 0; i < VideoFrame._mHeight - pattern_height + 1; i++) {
        int current_video_row = i; // video row to math with pattern row
        int current_pattern_row = 0; // patter row used to match

        bool finish = false; // if find or not

        std::vector<int> tab_index = {-1,-1,-1,-1}; // 4 = pattern_height
        int base_index = -1;

        while(!finish) {
            
            int found_index = 0; // indice found
            std::string data = std::string(pattern[current_pattern_row]); // raw pattern to match
            int index = current_video_row * VideoFrame._mWidth; // index to get video row
            char** s (VideoFrame._dataContainer.begin() + index, frame._data.begin() + index + frame._width);

            base_index = (base_index == -1) ? 0 : *std::max_element(tab_index.begin(), tab_index.end()); // start research at the last index

            if(base_index == tab_index[current_pattern_row]) { // don't process if pattern row index is at bae_index
                current_pattern_row++;
                current_video_row++;
                continue;
            }
            // search in row i
            if (KMPSearch(data, s, base_index, found_index)) {

                if (current_pattern_row == pattern_height && base_index == found_index) {
                    // print index and part of frame where of pattern detected
                    std::cout << "pattern found " << found_index <<  " " << i << std::endl;
                    for (int j = i; j < i+4 ; j++) {
                        for (int k = 0; k < frame._width; k++) {
                            std::cout <<frame._data[ j * frame._width + k];
                        }
                        std::cout << "\n";
                    }
                    tab_index[0] = found_index +1; // continue on the same row
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


/** KMP algorithme
 * input pat : current pattern row to find
 * input txt : current video row used to find
 * input base_index : index where starting research in txt
 * output found_idex : index find
 */
int Detector::KMPSearch(std::string pat, std::string txt, int base_index, int& found_index)
{
    // create lps[] that will hold the longest
    // prefix suffix values for pattern
    int pattern_size = pat.length();
    int *lps = (int *)malloc(sizeof(int)*pattern_size);
    int txt_size = txt.length();
     
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, pattern_size, lps);
 
    int i = base_index; // index for txt
    int j = 0; // index for pat
    
    while (i < txt_size)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == pattern_size)
        {
            found_index = i - j;// return 1 is pattern is found
            return 1;
        }
         
        // mismatch after j matches
        else if (i < txt_size && pat[j] != txt[i])
        {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    free(lps); // to avoid memory leak
     
    // return 0 is pattern is not found
    return 0;
}

// Used in KMP Search for preprocessing the pattern
void Detector::computeLPSArray(std::string pat, int m, int *lps)
{
    // length of the previous longest prefix suffix
    int len = 0;
    int i = 1;
 
    lps[0] = 0; // lps[0] is always 0
 
    // the loop calculates lps[i] for i = 1 to M-1
    while (i < m)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i++] = len;
        }
        else // (pat[i] != pat[len])
        {
            if (len != 0)
            {
                
                len = lps[len - 1];
 
                // Also, note that we do not increment i here
            }
            else // if (len == 0)
            {
                lps[i++] = 0;
            }
        }
    }
}