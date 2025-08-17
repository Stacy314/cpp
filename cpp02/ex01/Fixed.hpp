#pragma once

class Fixed {
private:
    int                 _value;
    static const int    _fractionalBits = 8;

public:
    // Orthodox Canonical Form
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    // New constructors
    Fixed(int n);
    Fixed(float f);

    // Conversions
    float toFloat(void) const;
    int   toInt(void) const;

    // Raw accessors
    int  getRawBits(void) const;
    void setRawBits(int const raw);
};

// Stream output
std::ostream& operator<<(std::ostream& os, const Fixed& fx);