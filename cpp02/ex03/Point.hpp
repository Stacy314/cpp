#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    const Fixed _x;
    const Fixed _y;

public:
    // Orthodox Canonical Form
    Point();
    Point(const float x, const float y);
    Point(const Point& other);
    Point& operator=(const Point& other); // Defined but does nothing due to const members
    ~Point();

    const Fixed& getX() const;
    const Fixed& getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif