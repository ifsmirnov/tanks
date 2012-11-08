#ifndef GEOM_HPP
#define GEOM_HPP

#include <iostream>

class Point
{
public:
    const static double eps = 1e-5;

    Point();
    Point(double, double);

    double x() const;
    double y() const;

    Point operator += (const Point&);
    Point operator -= (const Point&);
    Point operator *= (double);

    Point operator + (const Point&) const;
    Point operator - (const Point&) const;
    Point operator * (double) const;

    Point turned(double sin, double cos) const;

    double operator * (const Point&) const;
    double operator ^ (const Point&) const;

    double angle() const;
    double angleTo(const Point&) const;

    double length() const;
    double distanceTo(const Point&) const;

    bool inSegment(const Point&, const Point&) const;

private:
    double x_, y_;
};
std::ostream &operator<<(std::ostream &out, const Point &point);

namespace geom
{

double timeToReachSegment(Point u, Point v, Point p1, Point p2);

} // namespace geom

#endif // GEOM_HPP
