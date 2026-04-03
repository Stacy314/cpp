#include "BitcoinExchange.hpp"


int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error: too many arguments." << std::endl;
        return 1;
    }
    try {
        BitcoinExchange btc(argv[1]);
        btc.processInputFile(argv[1]);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
