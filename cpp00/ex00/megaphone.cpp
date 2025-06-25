#include <iostream>

bool isAsciiOnly(const std::string& str) {
    for (std::size_t i = 0; i < str.size(); ++i) {
        if (static_cast<unsigned char>(str[i]) > 127) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
	if (argc == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n';
		return 0;
	}
	for (int i = 1; argv[i]; i++) {
    	if (!isAsciiOnly(argv[i])) {
        	std::cerr << "Wrong character found" << '\n';
			return 1;
		}
	}
	for (int i = 1; argv[i]; i++){
		for (int j = 0; argv[i][j]; j++){
				argv[i][j] = std::toupper(static_cast<unsigned char>(argv[i][j]));
		}
	}
	for (int i = 1; argv[i]; i++){
		std::cout << argv[i];
	}
	std::cout << '\n';
	return 0;
}
