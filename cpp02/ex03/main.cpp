#include <iostream>
#include "Point.hpp"

static void report(const Point& a, const Point& b, const Point& c, const Point& p) {
    std::cout << "Triangle A(" << a.getX() << ", " << a.getY() << ") "
              << "B(" << b.getX() << ", " << b.getY() << ") "
              << "C(" << c.getX() << ", " << c.getY() << ")\n";
    std::cout << "Point P(" << p.getX() << ", " << p.getY() << ") is "
              << (bsp(a,b,c,p) ? "inside" : "outside") << std::endl;
}

int main() {
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);

    Point p1(2.0f, 2.0f);    // inside
    Point p2(0.0f, 0.0f);    // vertex → outside (per subject)
    Point p3(5.0f, 5.0f);    // on edge → outside
    Point p4(8.0f, 1.0f);    // inside
    Point p5(10.0f, 10.0f);  // outside

    report(a,b,c,p1);
    report(a,b,c,p2);
    report(a,b,c,p3);
    report(a,b,c,p4);
    report(a,b,c,p5);
    return 0;
}