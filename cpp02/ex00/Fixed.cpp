#include "Fixed.hpp"

//overflow
Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& src) : _value(src._value) {
    std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& src) {
    std::cout << "Copy assignment operator called\n";
    if (this != &src) { //overwrite protection
        this->_value = src._value;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called\n";
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
    this->_value = raw;
}