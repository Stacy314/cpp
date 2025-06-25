#include "Harl.hpp"
#include <iostream>

int main() {
    Harl harl;

    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR", "RANDOM"};

    for (int i = 0; i < 5; ++i) {
        std::cout << "\n👉 Calling level: " << levels[i] << "\n" << '\n';
        harl.complain(levels[i]);
    }

    return 0;
}
