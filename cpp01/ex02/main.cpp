#include <iostream>
#include <string>

int main() {
    std::string brain = "HI THIS IS BRAIN";
    std::string* stringPTR = &brain;
    std::string& stringREF = brain;
	
    std::cout << "Address of brain         : " << &brain << '\n';
    std::cout << "Address held by stringPTR: " << stringPTR << '\n';
    std::cout << "Address held by stringREF: " << &stringREF << '\n';

    std::cout << '\n';

    std::cout << "Value of brain               : " << brain << '\n';
    std::cout << "Value pointed by stringPTR   : " << *stringPTR << '\n';
    std::cout << "Value referenced by stringREF: " << stringREF << '\n';

    return 0;
}
