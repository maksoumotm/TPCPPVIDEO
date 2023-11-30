#include "FakeVideoSource.hpp"
#include "DisplayOutput.hpp"
#include "Detector.hpp"


int main() {
    // Demander à l'utilisateur de saisir la largeur, la hauteur et le taux de trame
    unsigned int width, height, frameRate;
    std::cout << "Enter width: ";
    std::cin >> width;
    std::cout << "Enter height: ";
    std::cin >> height;
    std::cout << "Enter frame rate: ";
    std::cin >> frameRate;

    // Instantiate elements
    std::cout << "TEST10";
    FakeVideoSource source(width, height, frameRate);
    std::cout << "TEST1";
    DisplayOutput display;
    std::cout << "TEST2";
    Detector detector;
    std::cout << "TEST3";

    source.link(&detector);  // Link the source to the detector
    std::cout << "TEST4";
    detector.link(&display);  // Link the detector to the display
    std::cout << "TEST5";

    // Run the pipeline by starting the video source
    std::cout << "TEST6";
    source.start();

    return 0;
}
