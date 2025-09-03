#include "Fixed.hpp"
#include <cmath>

//1 << n  ==  2^n
//0000 0000 0000 0001  = 1
//0000 0001 0000 0000  = 256

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(int n) {
    std::cout << "Int constructor called\n";
    _value = n << _fractionalBits;
}

Fixed::Fixed(float f) {
    std::cout << "Float constructor called\n";
    _value = (roundf(f * (1 << _fractionalBits))); //multiply by 256
}

Fixed::Fixed(const Fixed& src) : _value(src._value) {
    std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& src) {
    std::cout << "Copy assignment operator called\n";
    if (this != &src) this->_value = src._value;
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

float Fixed::toFloat(void) const {
    return (float)(_value) / (float)(1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _value >> _fractionalBits;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called\n";
    return _value;
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fx) {
    os << fx.toFloat();
    return os;
}