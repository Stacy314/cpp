#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(int n) {
    std::cout << "Int constructor called\n";
    _value = n << _fractionalBits;
}

Fixed::Fixed(float f) {
    std::cout << "Float constructor called\n";
    _value = (roundf(f * (1 << _fractionalBits)));
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

// Comparisons
bool Fixed::operator>(const Fixed &rhs) const{
	return (_value > rhs._value);
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return (_value < rhs._value);
}
bool Fixed::operator>=(const Fixed &rhs) const
{
	return (_value >= rhs._value);
}
bool Fixed::operator<=(const Fixed &rhs) const
{
	return (_value <= rhs._value);
}
bool Fixed::operator==(const Fixed &rhs) const
{
	return (_value == rhs._value);
}
bool Fixed::operator!=(const Fixed &rhs) const
{
	return (_value != rhs._value);
}

// Arithmetic (use 64-bit intermediates to preserve precision)
Fixed Fixed::operator+(const Fixed &rhs) const
{
	Fixed r;
	r._value = _value + rhs._value;
	return (r);
}
Fixed Fixed::operator-(const Fixed &rhs) const
{
	Fixed r;
	r._value = _value - rhs._value;
	return (r);
}
Fixed Fixed::operator*(const Fixed &rhs) const
{
	Fixed r;
	long a = static_cast<long>(_value);
	long b = static_cast<long>(rhs._value);
	r._value = static_cast<int>((a * b) >> _fractionalBits);
	return (r);
}
Fixed Fixed::operator/(const Fixed &rhs) const
{
	Fixed r;
	long a = static_cast<long>(_value) << _fractionalBits;
	long b = static_cast<long>(rhs._value); // may be 0 → UB allowed by subject
	r._value = static_cast<int>(a / b);
	return (r);
}

// ++/-- step is 1 LSB (epsilon)
Fixed &Fixed::operator++()
{
	++_value;
	return (*this);
}
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++_value;
	return (tmp);
}
Fixed &Fixed::operator--()
{
	--_value;
	return *this;
}
Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--_value;
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fx) {
    os << fx.toFloat();
    return os;
}
