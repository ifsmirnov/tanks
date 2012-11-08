#include "geom.hpp"

#include <cmath>

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

double Point::angle() const { return atan2(y(), x()); }
double Point::angleTo(const Point &point) const { return (point - *this).angle(); }

double Point::length() const { return sqrt(x()*x() + y()*y()); }
double Point::distanceTo(const Point &point) const { return (point - *this).length(); }

namespace geom
{

double timeToReachSegment(Point u, Point v, Point p1, Point p2)
{
    p1 -= u;
    p2 -= u;
    if (fabs(v * (p1 - p2)) < Point::eps)
        return -1; // no intersection sign

    double alpha = (p1 * p2) / (v * (p2 - p1));
    if (alpha < 0)
        return 0;
    Point res = v * alpha;
    if (p1.distanceTo(res) + p2.distanceTo(res) - p1.distanceTo(p2) < Point::eps) // point lies inside segment
        return alpha;
    else
        return -1;
}

} // namespace geom
