#include "Point.hpp"

// Helper for cross product sign of AB x AP
static Fixed cross(const Point& a, const Point& b, const Point& p) {
    Fixed abx = b.getX() - a.getX();
    Fixed aby = b.getY() - a.getY();
    Fixed apx = p.getX() - a.getX();
    Fixed apy = p.getY() - a.getY();
    // cross = ab.x * ap.y - ab.y * ap.x
    return (abx * apy) - (aby * apx);
}

// Strictly inside (points on edge or vertex → false)
bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed c1 = cross(a, b, point);
    Fixed c2 = cross(b, c, point);
    Fixed c3 = cross(c, a, point);

    // If any cross is zero → on an edge → false
    if (c1 == Fixed(0) || c2 == Fixed(0) || c3 == Fixed(0))
        return false;

    bool hasNeg = (c1 < Fixed(0)) || (c2 < Fixed(0)) || (c3 < Fixed(0));
    bool hasPos = (c1 > Fixed(0)) || (c2 > Fixed(0)) || (c3 > Fixed(0));
    return !(hasNeg && hasPos); // all have same sign → inside
}