#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(static_cast<unsigned int>(std::time(0)));

    for (int i = 0; i < 5; ++i)
    {
        Base *ptr = generate();

        std::cout << "identify(Base*): ";
        identify(ptr);

        std::cout << "identify(Base&): ";
        identify(*ptr);

        delete ptr;
        std::cout << "----" << std::endl;
    }
    return 0;
}