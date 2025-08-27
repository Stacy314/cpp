#include "fileReplacer.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "Usage: ./replacer <filename> <s1> <s2>." << '\n';
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if (s1.empty()) {
        std::cerr << "Error: s1 must not be empty.\n";
        return 1;
    }
    FileReplacer replacer(filename, s1, s2);
    if (!replacer.process()){
		std::cerr << "Error: failed replace a file.\n";
        return 1;
	}
    std::cout << "Replacements done. Output file: " << filename << ".replace." << '\n';
    return 0;
}
