#include <iostream>
#include <string>

int main() {
    std::string brain = "HI THIS IS BRAIN";

    std::string* stringPTR = &brain;     // вказівник
    std::string& stringREF = brain;      // посилання

    // Вивід адрес
    std::cout << "Address of brain       : " << &brain << std::endl;
    std::cout << "Address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Address held by stringREF: " << &stringREF << std::endl;

    std::cout << std::endl;

    // Вивід значень
    std::cout << "Value of brain         : " << brain << std::endl;
    std::cout << "Value pointed by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value referenced by stringREF: " << stringREF << std::endl;

    return 0;
}
