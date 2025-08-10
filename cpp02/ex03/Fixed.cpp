#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0) {}
Fixed::Fixed(const Fixed& other) : _value(other._value) {}
Fixed& Fixed::operator=(const Fixed& other) { if (this != &other) _value = other._value; return *this; }
Fixed::~Fixed() {}

Fixed::Fixed(int n) { _value = n << _fractionalBits; }
Fixed::Fixed(float f) { _value = static_cast<int>(roundf(f * (1 << _fractionalBits))); }

float Fixed::toFloat(void) const { return static_cast<float>(_value) / static_cast<float>(1 << _fractionalBits); }
int   Fixed::toInt(void) const   { return _value >> _fractionalBits; }

int Fixed::getRawBits(void) const { return _value; }
void Fixed::setRawBits(int const raw) { _value = raw; }

bool Fixed::operator>(const Fixed& rhs) const { return _value > rhs._value; }
bool Fixed::operator<(const Fixed& rhs) const { return _value < rhs._value; }
bool Fixed::operator>=(const Fixed& rhs) const { return _value >= rhs._value; }
bool Fixed::operator<=(const Fixed& rhs) const { return _value <= rhs._value; }
bool Fixed::operator==(const Fixed& rhs) const { return _value == rhs._value; }
bool Fixed::operator!=(const Fixed& rhs) const { return _value != rhs._value; }

Fixed Fixed::operator+(const Fixed& rhs) const { Fixed r; r.setRawBits(_value + rhs._value); return r; }
Fixed Fixed::operator-(const Fixed& rhs) const { Fixed r; r.setRawBits(_value - rhs._value); return r; }
Fixed Fixed::operator*(const Fixed& rhs) const {
    Fixed r; long a = static_cast<long>(_value); long b = static_cast<long>(rhs._value);
    r.setRawBits(static_cast<int>((a * b) >> _fractionalBits)); return r; }
Fixed Fixed::operator/(const Fixed& rhs) const {
    Fixed r; long a = static_cast<long>(_value) << _fractionalBits; long b = static_cast<long>(rhs._value);
    r.setRawBits(static_cast<int>(a / b)); return r; }

Fixed& Fixed::operator++() { ++_value; return *this; }
Fixed  Fixed::operator++(int) { Fixed tmp(*this); ++_value; return tmp; }
Fixed& Fixed::operator--() { --_value; return *this; }
Fixed  Fixed::operator--(int) { Fixed tmp(*this); --_value; return tmp; }

Fixed& Fixed::min(Fixed& a, Fixed& b) { return (a < b) ? a : b; }
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return (a < b) ? a : b; }
Fixed& Fixed::max(Fixed& a, Fixed& b) { return (a > b) ? a : b; }
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) { return (a > b) ? a : b; }

std::ostream& operator<<(std::ostream& os, const Fixed& fx) { os << fx.toFloat(); return os; }