#include "BitcoinExchange.hpp"


int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error: Usage: ./btc <file_name>\n";
        return 1;
    }
    try {
        BitcoinExchange btc(argv[1]);
        btc.processInputFile(argv[1]);
    } catch (const std::exception &e) {
        std::cout << e.what() << "\n";
        return 1;
    }
    return 0;
}
