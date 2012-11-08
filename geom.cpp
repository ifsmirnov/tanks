#include "geom.hpp"

#include <cmath>
#include <iostream>

Point::Point() :
    x_(0), y_(0) {  }
Point::Point(double x, double y) :
    x_(x), y_(y) {  }

double Point::x() const { return x_; }
double Point::y() const { return y_; }

Point Point::operator +=(const Point& point) { x_ += point.x(); y_ += point.y(); return *this; }
Point Point::operator -=(const Point& point) { x_ -= point.x(); y_ -= point.y(); return *this; }
Point Point::operator *=(double factor) { x_ *= factor; y_ *= factor; return *this; }

Point Point::operator +(const Point& point) const { return Point(x() + point.x(), y() + point.y()); }
Point Point::operator -(const Point& point) const { return Point(x() - point.x(), y() - point.y()); }
Point Point::operator *(double factor) const { return Point(x() * factor, y() * factor); }

Point Point::turned(double sin, double cos) const {
    return Point(x()*cos - y()*sin, x()*sin + y()*cos);
}

double Point::operator *(const Point& point) const { return x() * point.y() - y() * point.x(); }
double Point::operator ^(const Point& point) const { return x() * point.x() + y() * point.y(); }

double Point::angle() const { return atan2(y(), x()); }
double Point::angleTo(const Point &point) const { return atan2(operator*(point), operator^(point)); }

double Point::length() const { return sqrt(x()*x() + y()*y()); }
double Point::distanceTo(const Point &point) const { return (point - *this).length(); }

bool Point::inSegment(const Point &p1, const Point &p2) const
{
    return fabs((p2-p1) * (p2-*this)) < eps &&
            ((p2 - p1) ^ (*this - p1)) > -eps &&
            ((p1 - p2) ^ (*this - p2)) > -eps;
}

std::ostream &operator<<(std::ostream &out, const Point &point)
{
    out << point.x() << " " << point.y();
    return out;
}

namespace geom
{

double timeToReachSegment(Point u, Point v, Point p1, Point p2)
{
    p1 -= u;
    p2 -= u;
    if (fabs(v * (p1 - p2)) < Point::eps)
        return -1;

    double alpha = (p1 * p2) / (v * (p2 - p1));
    Point res = v * alpha;

    if (alpha > 0 && res.inSegment(p1, p2))
        return alpha;
    else
        return -1;
}

} // namespace geom
