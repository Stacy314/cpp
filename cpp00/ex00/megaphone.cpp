//TODO: special characters print err,try-catch???

#include <iostream>

void validateAscii(const std::string& str) {
    for (unsigned char c : str) {
        if (c > 127) {
            throw std::runtime_error("Non-ASCII character detected");
        }
    }
}

int main(int argc, char *argv[]) {
	if (argc == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
    try {
        validateAscii(argv[1]);
        std::cout << "String is ASCII-only." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
	for (int i = 1; argv[i]; i++){
		for (int j = 0; argv[i][j]; j++){
				argv[i][j] = toupper(argv[i][j]);
		}
	}
	for (int i = 1; argv[i]; i++){
		std::cout << argv[i];
	}
	std::cout << std::endl;
	return 0;
}