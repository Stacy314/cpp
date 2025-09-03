#include "Fixed.hpp"

int main(void) {
    Fixed a; //constructor
    Fixed b(a); //сopy constructor
    Fixed c; //constructor

    c = b; //copy assignment(doesn't create a new object)

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
	
    return 0; //destructor (3 times)
}