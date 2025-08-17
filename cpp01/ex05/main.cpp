#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv) {
    Harl harl;

	if (argc != 2) {
        std::cerr << "Usage: ./harl <level>" << '\n';
        return 1;
    }
	harl.complain(argv[1]);
    return 0;
}
