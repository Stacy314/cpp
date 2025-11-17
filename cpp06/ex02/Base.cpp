#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base::~Base() {}

Base *generate(void)
{
    int r = std::rand() % 3;

    switch (r)
    {
        case 0:
            std::cout << "Generated type: A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated type: B" << std::endl;
            return new B();
        default:
            std::cout << "Generated type: C" << std::endl;
            return new C();
    }
}

void identify(Base *p)
{
    if (p == 0)
    {
        std::cout << "Null pointer" << std::endl;
        return;
    }

    if (dynamic_cast<A *>(p) != 0)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p) != 0)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p) != 0)
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base &p)
{
    // Використовуємо dynamic_cast з посиланням і catch(...) без <typeinfo>
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (...) {}

    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (...) {}

    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (...) {}

    std::cout << "Unknown type" << std::endl;
}