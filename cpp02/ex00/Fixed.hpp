#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
    Fixed();
    Fixed(const Fixed& src);
    Fixed& operator=(const Fixed& src);
    ~Fixed();

    int  getRawBits(void) const;
    void setRawBits(int const raw);

	private:
    int                 _value;
    static const int    _fractionalBits = 8;
};

#endif