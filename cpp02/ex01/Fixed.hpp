#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
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
	
private:
    int                 _value;
    static const int    _fractionalBits = 8;

};

std::ostream& operator<<(std::ostream& os, const Fixed& fx);

#endif