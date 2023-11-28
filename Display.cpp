#include "display.hpp"

namespace Display {
    void clearScreen() {
        std::cout << "\033[2J\033[1;1H";
    }
}
