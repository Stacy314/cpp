#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>


class Fixed {
private:
    int                 _value;
    static const int    _fractionalBits = 8;

public:

    Fixed();
	Fixed(const int n);
    Fixed(const float f);
    Fixed(const Fixed& src);
    Fixed& operator=(const Fixed& src);
    ~Fixed();
  
    float toFloat(void) const;
    int   toInt(void) const;

    int  getRawBits(void) const;
    void setRawBits(int const raw);
	
    // Comparison operators
    bool operator>(const Fixed& rhs) const;
    bool operator<(const Fixed& rhs) const;
    bool operator>=(const Fixed& rhs) const;
    bool operator<=(const Fixed& rhs) const;
    bool operator==(const Fixed& rhs) const;
    bool operator!=(const Fixed& rhs) const;

    // Arithmetic operators
    Fixed operator+(const Fixed& rhs) const;
    Fixed operator-(const Fixed& rhs) const;
    Fixed operator*(const Fixed& rhs) const;
    Fixed operator/(const Fixed& rhs) const; // Division by 0 is UB (allowed to crash per subject)

    // Pre/Post inc/dec
    Fixed& operator++();      // ++a
    Fixed  operator++(int);   // a++
    Fixed& operator--();      // --a
    Fixed  operator--(int);   // a--

    // Min/Max
    static Fixed&       min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed&       max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fx);

#endif